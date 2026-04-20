#include <iostream>
#include <string>
#include <cstdlib>
#include <curl/curl.h>
#include "Conversacion.h"
#include "Mensaje.h"
#include "../third_party/json.hpp"

using json = nlohmann::json;

// Callback para recibir respuesta de libcurl
static size_t escribir_callback(void* contenidos, size_t tam, size_t nmemb, void* usuario) {
    ((std::string*)usuario)->append((char*)contenidos, tam * nmemb);
    return tam * nmemb;
}

// Llamada simplificada a OpenAI (formato chat completions)
std::string llamar_openai(const std::string& api_key, const std::string& base_url, const std::string& modelo, const std::string& prompt) {
    CURL* curl = curl_easy_init();
    if (!curl) return "";

    std::string respuesta_str;
    std::string url = base_url + "/v1/chat/completions";
    json cuerpo;
    cuerpo["model"] = modelo;
    cuerpo["messages"] = json::array();
    cuerpo["messages"].push_back({{"role","user"},{"content", prompt}});

    struct curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, ("Authorization: Bearer " + api_key).c_str());
    headers = curl_slist_append(headers, "Content-Type: application/json");

    std::string cuerpo_str = cuerpo.dump();

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, cuerpo_str.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, escribir_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &respuesta_str);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
        return "";
    }

    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);

    try {
        auto j = json::parse(respuesta_str);
        if (j.contains("choices") && j["choices"].is_array() && !j["choices"].empty()) {
            auto contenido = j["choices"][0]["message"]["content"].get<std::string>();
            return contenido;
        }
    } catch (...) {
        return "";
    }
    return "";
}

// Wrapper para Gemini (aquí reutilizamos la misma estructura; ajustar según API real)
std::string llamar_gemini(const std::string& api_key, const std::string& base_url, const std::string& modelo, const std::string& prompt) {
    return llamar_openai(api_key, base_url, modelo, prompt);
}

int main(int argc, char** argv) {
    std::string proveedor = "auto";
    std::string modelo = "gpt-4o-mini";
    std::string prompt_arg;
    bool interactivo = true;

    for (int i = 1; i < argc; ++i) {
        std::string a = argv[i];
        if (a == "--provider" && i + 1 < argc) proveedor = argv[++i];
        else if (a == "--model" && i + 1 < argc) modelo = argv[++i];
        else if (a == "--prompt" && i + 1 < argc) { prompt_arg = argv[++i]; interactivo = false; }
    }

    std::string openai_key = std::getenv("OPENAI_API_KEY") ? std::getenv("OPENAI_API_KEY") : "";
    std::string openai_base = std::getenv("OPENAI_BASE_URL") ? std::getenv("OPENAI_BASE_URL") : "https://api.openai.com";
    std::string gemini_key = std::getenv("GEMINI_API_KEY") ? std::getenv("GEMINI_API_KEY") : (std::getenv("GOOGLE_API_KEY") ? std::getenv("GOOGLE_API_KEY") : "");
    std::string gemini_base = std::getenv("GEMINI_BASE_URL") ? std::getenv("GEMINI_BASE_URL") : "https://generativelanguage.googleapis.com/v1beta/openai";

    Conversacion conv;

    if (!interactivo) {
        std::string mensaje_usuario = prompt_arg;
        conv.agregarMensaje(Mensaje(Mensaje::Rol::Usuario, mensaje_usuario));
        std::string respuesta;
        bool uso_llm = false;

        if (proveedor == "openai" || (proveedor == "auto" && modelo.rfind("gpt", 0) == 0)) {
            if (!openai_key.empty()) {
                respuesta = llamar_openai(openai_key, openai_base, modelo, mensaje_usuario);
                uso_llm = !respuesta.empty();
            }
        } else if (proveedor == "gemini" || (proveedor == "auto" && modelo.rfind("gemini", 0) == 0)) {
            if (!gemini_key.empty()) {
                respuesta = llamar_gemini(gemini_key, gemini_base, modelo, mensaje_usuario);
                uso_llm = !respuesta.empty();
            }
        }

        if (!uso_llm) respuesta = mensaje_usuario; // fallback: repetir
        conv.agregarMensaje(Mensaje(Mensaje::Rol::Asistente, respuesta));
        std::cout << respuesta << std::endl;
        conv.guardarEnDisco("conversaciones");
        return 0;
    }

    // Modo interactivo
    std::cout << "Modo interactivo. Escribe 'salir' para terminar.\n";
    while (true) {
        std::cout << "> ";
        std::string linea;
        if (!std::getline(std::cin, linea)) break;
        if (linea == "salir" || linea == "exit") break;
        if (linea.empty()) continue;

        conv.agregarMensaje(Mensaje(Mensaje::Rol::Usuario, linea));
        std::string respuesta;
        bool uso_llm = false;

        if (proveedor == "openai" || (proveedor == "auto" && modelo.rfind("gpt", 0) == 0)) {
            if (!openai_key.empty()) {
                respuesta = llamar_openai(openai_key, openai_base, modelo, linea);
                uso_llm = !respuesta.empty();
            }
        } else if (proveedor == "gemini" || (proveedor == "auto" && modelo.rfind("gemini", 0) == 0)) {
            if (!gemini_key.empty()) {
                respuesta = llamar_gemini(gemini_key, gemini_base, modelo, linea);
                uso_llm = !respuesta.empty();
            }
        }

        if (!uso_llm) respuesta = linea;
        conv.agregarMensaje(Mensaje(Mensaje::Rol::Asistente, respuesta));
        std::cout << respuesta << "\n";
    }

    conv.guardarEnDisco("conversaciones");
    return 0;
}
