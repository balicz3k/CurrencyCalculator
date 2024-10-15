#include "intf/ICurrencyCalculator.hpp"
#include "impl/CurrencyCalculator.hpp"
#include <memory>

int main()
{
    std::shared_ptr<ICurrencyCalculator> app = std::make_unique<CurrencyApplication>();
    app->run();
}