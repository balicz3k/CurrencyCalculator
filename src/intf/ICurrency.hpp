#include <string>

class ICurrency
{
public:
    ICurrency() = default;
    virtual double getRate() const = 0;
    virtual std::string getName() const = 0;
    virtual std::string getCode() const = 0;
    virtual double setRate() const = 0;
    virtual std::string setName() const = 0;
    virtual std::string setCode() const = 0;
    virtual ~ICurrency() = default;
};
