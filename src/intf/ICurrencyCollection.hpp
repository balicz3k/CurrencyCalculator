#pragma once

#include "ICurrency.hpp"
#include <vector>

class ICurrencyCollection
{
public:
    virtual ~ICurrencyCollection() = default;
    virtual std::vector<std::shared_ptr<ICurrency>> getCurrencies() const = 0;
    virtual std::shared_ptr<ICurrency> getCurrencyByCode(const std::string& code) const = 0;
    virtual void addCurrency(std::shared_ptr<ICurrency> currency) = 0;
};
