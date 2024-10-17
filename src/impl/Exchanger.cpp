#include "Exchanger.hpp"

double Exchanger::exchange(const std::shared_ptr<ICurrencyCollection> &collection,
                    const std::string& from, const std::string& to,
                    const double& amount) {
    auto fromCurrency = collection->getCurrencyByCode(from);
    auto toCurrency = collection->getCurrencyByCode(to);

    if (!fromCurrency || !toCurrency) {
        throw std::runtime_error("Invalid currency code");
    }

    double fromRate = fromCurrency->getRate();
    double toRate = toCurrency->getRate();

    return (amount / fromRate) * toRate;

}