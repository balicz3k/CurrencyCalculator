#pragma once
<<<<<<< HEAD
=======

>>>>>>> 0170123 (project scheme and first implementation required classes and interfaces)
#include "ICurrencyCollection.hpp"

class DataParser
{
public:
<<<<<<< HEAD
    static void parseData(const std::string& data, ICurrencyCollection& collection);
private:
    static std::shared_ptr<ICurrency> stringToICurrency(const std::string &line);
    static void addPLN(ICurrencyCollection& collection);
=======
    static void parseData(const std::string& data, std::shared_ptr<ICurrencyCollection> collection);
private:
    static std::shared_ptr<ICurrency> stringToICurrency(const std::string &line);
    static void addPLN(std::shared_ptr<ICurrencyCollection> collection);
>>>>>>> 0170123 (project scheme and first implementation required classes and interfaces)
    std::string extractValue(const std::string &data, const std::string &tag);
};