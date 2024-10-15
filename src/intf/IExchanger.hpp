#include <memory>
#include "src/intf/ICurrencyCollection.hpp"

class IExchanger
{
    public:
    virtual ~IExchanger() = default;
    virtual double exchange(const std::shared_ptr<ICurrencyCollection>& collection, const std::string& from, const std::string& to, double amount) = 0;
};