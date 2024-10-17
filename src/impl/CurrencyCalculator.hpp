#pragma once

#include "src/intf/ICurrencyCalculator.hpp"
#include "src/intf/IDataProvider.hpp"
#include "src/impl/DataProvider.hpp"
#include "src/impl/DataParser.hpp"
#include "src/intf/ICurrencyCollection.hpp"
#include "src/impl/CurrencyCollection.hpp"
#include "src/impl/CurrencyCollection.hpp"
#include "src/impl/Exchanger.hpp"
#include <memory>
#include <string>
#include <iostream>

class CurrencyApplication : public ICurrencyCalculator
{
public:
    CurrencyApplication() 
    {
        dataProvider_ = std::make_shared<DataProvider>();
        collection_ = std::make_shared<CurrencyCollection>();
    }

    void initialize() {
        auto data = dataProvider_->aquireData();
        DataParser::parseData(data, collection_);
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
            auto result = Exchanger::exchange(collection_, from, to, amount);
            std::cout << amount << " " << from << " is " << result << " " << to << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

private:
    std::shared_ptr<IDataProvider> dataProvider_;
    std::shared_ptr<DataParser> dataParser_;
    std::shared_ptr<ICurrencyCollection> collection_;
};
