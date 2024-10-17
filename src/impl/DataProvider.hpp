#pragma once

#include "src/intf/IDataProvider.hpp"
#include <string>
#include <sstream>

class DataProvider : public IDataProvider
{
public:
    DataProvider() = default;
    virtual std::string acquireData(const std::string& link) final;
    ~DataProvider() = default;
private:
    static size_t writeCallback(void* contents, size_t size, size_t nmemb, void* userp);
    void init(const std::string& link);
    void acquire();

    std::string link_;
    std::stringstream inputStream_;
};
