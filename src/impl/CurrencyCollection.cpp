#include "CurrencyCollection.hpp"
#include <algorithm>
#include <memory>

std::vector<std::shared_ptr<ICurrency>> CurrencyCollection::getCurrencies() const {
  return currencies_;
}

std::shared_ptr<ICurrency> CurrencyCollection::getCurrencyByCode(const std::string& code) const {
    auto result = std::find_if(currencies_.begin(), currencies_.end(), [&code](const auto& currency) {
        return currency->getCode() == code;
    });
    if (result == currencies_.end()) {
        throw std::runtime_error("Currency not found");
    }
    return *result;
}

void CurrencyCollection::addCurrency(std::shared_ptr<ICurrency> currency) 
{
    currencies_.push_back(currency);
}
