#include <curl/curl.h>
#include "conversacion.h"
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <stdexcept>

#ifdef _WIN32
#include <windows.h>
#endif

// Callback para escribir la respuesta en un string
size_t write_callback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t total_size = size * nmemb;
    auto* output = static_cast<std::string*>(userp);
    output->append(static_cast<char*>(contents), total_size);
    return total_size;
}

// Función para realizar la petición al API
std::string request_chat(const std::string& api_key,
                         const std::string& base_url,
                         const std::string& model,
                         const std::string& prompt) {
    CURL* curl = curl_easy_init();
    if (!curl) throw std::runtime_error("Error inicializando CURL");

    std::string response;
    std::string url = base_url + "/v1/chat/completions";
    std::string payload = "{\"model\":\"" + model +
                          "\",\"messages\":[{\"role\":\"user\",\"content\":\"" + prompt + "\"}]}";

    struct curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, ("Authorization: Bearer " + api_key).c_str());

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    CURLcode result = curl_easy_perform(curl);
    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);

    if (result != CURLE_OK) throw std::runtime_error("Fallo en CURL");

    return response;
}

int main() {
    try {
#ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
#endif
        Conversacion conversacion;
        std::filesystem::create_directories("src/output");

        std::string api_key = std::getenv("OPENAI_API_KEY");
        if (!api_key) throw std::runtime_error("Falta OPENAI_API_KEY");

        std::string prompt;
        std::cout << "Escribe tu prompt: ";
        std::getline(std::cin, prompt);

        if (prompt.empty()) {
            std::cerr << "El prompt no puede estar vacío.\n";
            return 1;
        }

        curl_global_init(CURL_GLOBAL_DEFAULT);
        std::string response = request_chat(api_key, "https://api.openai.com", "gpt-4o-mini", prompt);
        curl_global_cleanup();

        conversacion.agregarMensaje(Mensaje(prompt, "Usuario"));
        conversacion.agregarMensaje(Mensaje(response, "Ia"));
        conversacion.guardarEnArchivo("src/output/historial_chat.txt");

        std::cout << "\nRespuesta del modelo:\n" << response << "\n";
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
}
