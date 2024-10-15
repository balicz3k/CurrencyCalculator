cmake_minimum_required(VERSION 3.10)

project(CurrencyCalculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_SOURCE_DIR}/src/intf 
                    ${CMAKE_SOURCE_DIR}/src/impl)

add_executable(CurrencyCalculator
    src/app.cpp
    src/impl/Exchanger.cpp
    src/impl/CurrencyCollection.cpp
    src/impl/CurrencyCalculator.cpp
    src/impl/DataProvider.cpp
    src/impl/DataParser.cpp
    src/impl/Currency.cpp
)