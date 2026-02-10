#pragma once

#include <sstream>
#include <type_traits>
#include <format>
#include "logger.hpp"

/**
static polymorphism:
we use a template to create a parameterized class 
This allows the user to choose the type (T) at compile-time instead of being limited to 'int'
 */
template <typename T> 
/*
While Stefan mention we wish to "use any other type", 
this 'requires' clause ensures T supports arithmetic! This prevents 
instantiation with types that would break the logic later and we don't like that :(
*/
requires std::is_arithmetic_v<T> // Safeguard 
class TemplateCalculator
{
public:
    /*
    dependency invversion principle (DIP):
    The calculator refers only to the abstraction 'Logger' not a 
    concrete class like 'FileLogger'. This isolates 
    the calculator from volatile logging implementations
    */
    explicit TemplateCalculator(Logger *logger) : logger(logger)
    {
    }

    // Implement this:
    // function templates 
    // Quote: Templates require the implementation in the header (p42)
    T sum(T a, T b) // T is determined by the type the class is made for (template instantiation)
    {
        /*
        single responsibility princiople (SRP):
        This module is responsible for calculation. 
        By delegating strings to the logger we ensure the calculator 
        has only one "actor" to answer to
        */
        if (!logger) throw std::runtime_error("Logger is null");

        T result = a + b;

        // Logging similarly to IntCalculator (format from: C++20)
        logger->log(std::format("taking the sum of: {} and {} which is {}", a, b, result)); 

        return result;
    }

    // Implement this:
    T multiply(T a, T b)
    {
        if (!logger) throw std::runtime_error("Logger is null");

        T result = a * b;

        // Logging similarly to IntCalculator (format from: C++20)
        logger->log(std::format("taking the product of: {} and {} which is {}", a, b, result)); // C++20

        return result;
    }

private:
/*
    dynamic polumoprhism:
    while the class itself is static (template), this member uses 
    dynamic polymorphism (inheritance) to interact with the logger 
    component at high-level
*/
    Logger *logger;
};