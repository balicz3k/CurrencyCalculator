<<<<<<< HEAD
#include "src/intf/ICurrencyCalculator.hpp"
#include "src/intf/IDataProvider.hpp"
#include "src/impl/DataParser.hpp"
#include "src/intf/ICurrencyCollection.hpp"
#include "src/impl/CurrencyCollection.hpp"
#include "src/intf/IExchanger.hpp"
=======
#pragma once

#include "src/intf/ICurrencyCalculator.hpp"
#include "src/intf/IDataProvider.hpp"
#include "src/impl/DataProvider.hpp"
#include "src/impl/DataParser.hpp"
#include "src/intf/ICurrencyCollection.hpp"
#include "src/impl/CurrencyCollection.hpp"
#include "src/impl/CurrencyCollection.hpp"
#include "src/impl/Exchanger.hpp"
>>>>>>> 0170123 (project scheme and first implementation required classes and interfaces)
#include <memory>
#include <string>
#include <iostream>

class CurrencyApplication : public ICurrencyCalculator
{
public:
<<<<<<< HEAD
    CurrencyApplication(std::shared_ptr<IDataProvider> dataProvider, std::shared_ptr<DataParser> dataParser)
        : dataProvider(dataProvider), dataParser(dataParser) 
    {
        collection = std::make_shared<CurrencyCollection>();
    }

    void initialize() {
        std::string data = dataProvider->aquireData();
        ICurrencyCollection collection;
        dataParser->parseData(data, collection);
        for (const auto& currency : currencies) {
            collection->addCurrency(currency);
        }
=======
    CurrencyApplication() 
    {
        dataProvider_ = std::make_shared<DataProvider>();
        collection_ = std::make_shared<CurrencyCollection>();
    }

    void initialize() {
        auto data = dataProvider_->aquireData();
        DataParser::parseData(data, collection_);
>>>>>>> 0170123 (project scheme and first implementation required classes and interfaces)
    }

    void run() override {
        std::string from, to;
        double amount;
        std::cout << "Enter source currency code: ";
        std::cin >> from;
        std::cout << "Enter target currency code: ";
        std::cin >> to;
        std::cout << "Enter amount: ";
        std::cin >> amount;

        try {
<<<<<<< HEAD
            Exchanger& exchanger = Exchanger::getInstance();
            double result = exchanger.exchange(collection, from, to, amount);
=======
            auto result = Exchanger::exchange(collection_, from, to, amount);
>>>>>>> 0170123 (project scheme and first implementation required classes and interfaces)
            std::cout << amount << " " << from << " is " << result << " " << to << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

private:
<<<<<<< HEAD
    std::shared_ptr<IDataProvider> dataProvider;
    std::shared_ptr<DataParser> dataParser;
    std::shared_ptr<ICurrencyCollection> collection;
=======
    std::shared_ptr<IDataProvider> dataProvider_;
    std::shared_ptr<DataParser> dataParser_;
    std::shared_ptr<ICurrencyCollection> collection_;
>>>>>>> 0170123 (project scheme and first implementation required classes and interfaces)
};
