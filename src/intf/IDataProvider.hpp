#include <sstream>
#include <string>

class IDataProvider
{
public:
    virtual ~IDataProvider() = default;
    virtual std::string aquireData(const std::string& link = "https://api.nbp.pl/api/exchangerates/tables/a/") = 0;
};