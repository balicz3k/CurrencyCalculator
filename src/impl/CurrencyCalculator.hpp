#include "src/intf/ICurrencyCalculator.hpp"
#include "src/intf/IDataProvider.hpp"
#include "src/impl/DataParser.hpp"
#include "src/intf/ICurrencyCollection.hpp"
#include "src/impl/CurrencyCollection.hpp"
#include "src/intf/IExchanger.hpp"
#include <memory>
#include <string>
#include <iostream>

class CurrencyApplication : public ICurrencyCalculator
{
public:
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
            Exchanger& exchanger = Exchanger::getInstance();
            double result = exchanger.exchange(collection, from, to, amount);
            std::cout << amount << " " << from << " is " << result << " " << to << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

private:
    std::shared_ptr<IDataProvider> dataProvider;
    std::shared_ptr<DataParser> dataParser;
    std::shared_ptr<ICurrencyCollection> collection;
};
