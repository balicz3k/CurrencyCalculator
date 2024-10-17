#pragma once

class ICurrencyCalculator
{
public:
    virtual ~ICurrencyCalculator() noexcept = default; 
    virtual void run() = 0;
};