#pragma once
#include "ICurrencyCollection.hpp"

class DataParser
{
public:
    static void parseData(const std::string& data, ICurrencyCollection& collection);
private:
    static std::shared_ptr<ICurrency> stringToICurrency(const std::string &line);
    static void addPLN(ICurrencyCollection& collection);
    std::string extractValue(const std::string &data, const std::string &tag);
};