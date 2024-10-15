#include "Exchanger.hpp"

double Exchanger::exchange(const std::shared_ptr<ICurrencyCollection> &collection,
                    const std::string& from, const std::string& to,
<<<<<<< HEAD
                    double amount) {
=======
                    const double& amount) {
>>>>>>> 0170123 (project scheme and first implementation required classes and interfaces)
    auto fromCurrency = collection->getCurrencyByCode(from);
    auto toCurrency = collection->getCurrencyByCode(to);

    if (!fromCurrency || !toCurrency) {
        throw std::runtime_error("Invalid currency code");
    }

    double fromRate = fromCurrency->getRate();
    double toRate = toCurrency->getRate();

    return (amount / fromRate) * toRate;

}