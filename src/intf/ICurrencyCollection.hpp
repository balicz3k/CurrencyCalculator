<<<<<<< HEAD
=======
#pragma once

>>>>>>> 0170123 (project scheme and first implementation required classes and interfaces)
#include "ICurrency.hpp"
#include <vector>

class ICurrencyCollection
{
public:
<<<<<<< HEAD
=======
    virtual ~ICurrencyCollection() = default;
>>>>>>> 0170123 (project scheme and first implementation required classes and interfaces)
    virtual std::vector<std::shared_ptr<ICurrency>> getCurrencies() const = 0;
    virtual std::shared_ptr<ICurrency> getCurrencyByCode(const std::string& code) const = 0;
    virtual void addCurrency(std::shared_ptr<ICurrency> currency) = 0;
};
