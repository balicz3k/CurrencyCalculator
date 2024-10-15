<<<<<<< HEAD
class ICurrencyCalculator
{
    virtual ~ICurrencyCalculator() = default;
=======
#pragma once

class ICurrencyCalculator
{
public:
    virtual ~ICurrencyCalculator() noexcept = default; 
>>>>>>> 0170123 (project scheme and first implementation required classes and interfaces)
    virtual void run() = 0;
};