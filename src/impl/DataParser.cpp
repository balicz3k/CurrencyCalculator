#include "DataParser.hpp"
#include "ICurrency.hpp"
#include <iostream>
#include <sstream>

void DataParser::parseData(const std::string &data, ICurrencyCollection &collection) 
{
    std::istringstream stream(data);
    std::string line;
    while (std::getline(stream, line)) {
        auto currency = stringToICurrency(line);
        if (currency) {
            collection.addCurrency(currency);
        }
    }
    addPLN(collection);
}

std::shared_ptr<ICurrency> DataParser::stringToICurrency(const std::string &line) 
{
    std::istringstream iss(line);
    std::string name, code;
    double rate;

    // Przykład linii: "bat (Tajlandia)THB0.1180"
    size_t nameEnd = line.find('(');
    size_t codeStart = line.find(')', nameEnd) + 1;
    size_t rateStart = line.find_first_of("0123456789", codeStart);

    name = line.substr(0, nameEnd - 1);
    code = line.substr(codeStart, rateStart - codeStart);
    rate = std::stod(line.substr(rateStart));

    return std::make_shared<ICurrency>(name, code, rate);
}

void DataParser::addPLN(ICurrencyCollection &collection) 
{
    auto pln = std::make_shared<ICurrency>("Polski Złoty", "PLN", 1.0);
    collection.addCurrency(pln);
}
