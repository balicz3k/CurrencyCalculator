#pragma once

#include "src/intf/ICurrency.hpp"

class Currency : public ICurrency
{
public:
    Currency(const double& rate,const std::string& name, const std::string& code);
    virtual double getRate() const final;
    virtual std::string getName() const final;
    virtual std::string getCode() const final;
    virtual double setRate(const double&) final;
    virtual std::string setName(const std::string& name) final;
    virtual std::string setCode(const std::string& code) final;
    bool operator==(const Currency& other) const;
    ~Currency() = default;
private:
    double rate_;
    std::string name_;
    std::string code_;
};
