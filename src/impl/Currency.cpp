#include "Currency.hpp"

Currency::Currency(const double &rate, const std::string &name,
                                   const std::string &code) : rate_(rate), name_(name), code_(code) {};

double Currency::getRate() const { return rate_; }

std::string Currency::getName() const { return name_; }

std::string Currency::getCode() const { return code_; }

double Currency::setRate(const double& rate) { rate_ = rate; }

std::string Currency::setName(const std::string& name) { name_ = name; }

std::string Currency::setCode(const std::string& code) { code_ = code; }

bool Currency::operator==(const Currency &other) const 
{
    return rate_ == other.rate_ and name_ == other.name_ and code_ == other.code_;
}
