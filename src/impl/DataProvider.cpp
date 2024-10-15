#include "DataProvider.hpp"
#include <curl/curl.h>

void DataProvider::init(const std::string& link) {
    link_ = link;
}

size_t writeCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::stringstream*)userp)->write((const char*)contents, size * nmemb);
    return size * nmemb;
}

void DataProvider::acquire() {
    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, link_.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &inputStream_);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            throw std::runtime_error("curl_easy_perform() failed: " + std::string(curl_easy_strerror(res)));
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

std::string DataProvider::acquireData(const std::string& link)
{
    init(link);
    acquire();
    return inputStream_.str();
}