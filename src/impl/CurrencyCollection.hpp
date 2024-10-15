<<<<<<< HEAD
=======
#pragma once

>>>>>>> 0170123 (project scheme and first implementation required classes and interfaces)
#include "src/intf/ICurrencyCollection.hpp"
#include "src/intf/ICurrency.hpp"


class CurrencyCollection : public ICurrencyCollection
{
public:
    CurrencyCollection();
    virtual std::vector<std::shared_ptr<ICurrency>> getCurrencies() const final;
    virtual std::shared_ptr<ICurrency> getCurrencyByCode(const std::string &code) const final;
    virtual void addCurrency(std::shared_ptr<ICurrency> currency) final;
    ~CurrencyCollection() = default;
private:
    std::vector<std::shared_ptr<ICurrency>> currencies_;
};