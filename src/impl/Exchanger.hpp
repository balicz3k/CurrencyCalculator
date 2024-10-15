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
};