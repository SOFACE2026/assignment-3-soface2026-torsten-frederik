#include <sstream> // Hint to how you should build the message.
#include <format>
#include <stdexcept>
#include "int_calculator.hpp"

// Constructor Injection (dependency inversion principle)
IntCalculator::IntCalculator(Logger *logger) : logger(logger) {}

// Implement this:
int IntCalculator::sum(int a, int b)
{
    // Using SRP 
    if (!logger) throw std::runtime_error("IntCalculator: logger is null");

    int result = a + b;

    /*
    component protection and ISP:
    By using the logger interface, this high-level calculator component 
    is protected from changes made to low-level logging components 
    (like changing from console to file logging)
    */
    logger->log(std::format("taking the sum of: {} and {} which is {}", a, b, result)); // C++20

    return result;
}

// Implement this:
int IntCalculator::multiply(int a, int b)
{
    if (!logger) throw std::runtime_error("IntCalculator: logger is null");

    int result = a * b;

    logger->log(std::format("taking the product of: {} and {} which is {}", a, b, result)); // C++20

    return result;
}