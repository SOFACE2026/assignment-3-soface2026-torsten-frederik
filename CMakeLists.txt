cmake_minimum_required(VERSION 3.10)
project(template)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# static checks
# if(MSVC)
#   add_compile_options(/W4 /WX)
# else()
#   add_compile_options(-Wall -Wextra -pedantic -Werror)
# endif()

# set(CMAKE_CXX_CLANG_TIDY
#   clang-tidy;
#   -checks=*;
# )

# set(CMAKE_CXX_CPPCHECK
#   cppcheck;
#   --error-exitcode=1;
# )


include_directories(include)

add_library(calc src/int_calculator_bad.cpp src/int_calculator.cpp src/dummy_logger.cpp src/print_logger.cpp src/file_logger.cpp)




add_subdirectory(tests)

add_executable(main src/main.cpp)

