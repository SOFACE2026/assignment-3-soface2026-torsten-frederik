#include "file_logger.hpp"
#include <fstream>
#include <iostream>

// Implement this:
/*
concrete implementation:
This is a "volatile concrete class" 
according to DIP, other parts of the system (like IntCalculator) 
should not depend on this specific file, but only on the Logger interface
*/
FileLogger::FileLogger(std::string filename)
{
    logfile.open(filename, std::ios::app);

    if (!logfile.is_open()) {
        throw std::runtime_error("FileLogger: could not open file: " + filename);
    }
}

// Implement this:
void FileLogger::log(std::string msg)
{
    /*
    open-closed principle (OCP):
    By implementing this virtual function, we allow the system to be 
    extended with file-logging behavior without modifying existing 
    calculator code
    */
    logfile << msg << std::endl;;
}

// Implement this:
FileLogger::~FileLogger() = default; // default - FileLogger closes by iteself when out-of-scope