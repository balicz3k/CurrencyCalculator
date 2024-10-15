<<<<<<< HEAD
#include "src/intf/IExchanger.hpp"

class Exchanger : public IExchanger
{
public:
    static Exchanger& getInstance() {
        static Exchanger instance;
        return instance;
    }
    virtual double exchange(const std::shared_ptr<ICurrencyCollection>& collection, const std::string& from, const std::string& to, double amount) final;
private:
    Exchanger() = default;
    ~Exchanger() = default;
    Exchanger(const Exchanger&) = delete;
    Exchanger& operator=(const Exchanger&) = delete;
=======
#pragma once

#include <string>
#include "src/intf/ICurrencyCollection.hpp"
class Exchanger
{
public:

    Exchanger() = default;
    ~Exchanger() = default;
    static double exchange(const std::shared_ptr<ICurrencyCollection>& collection, const std::string& from, const std::string& to, const double& amount);
>>>>>>> 0170123 (project scheme and first implementation required classes and interfaces)
};