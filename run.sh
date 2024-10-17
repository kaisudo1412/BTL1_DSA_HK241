#!/bin/bash

# Check if the executable 'main' already exists and remove it
if [ -f main ]; then
    echo "Removing existing executable 'main'."
    rm main
fi

# Compile the C++ program
g++ -fsanitize=address  -o main -Iinclude -Isrc -std=c++17 main.cpp \
 test/unit_test/arrayList/unit_test.cpp \
 test/unit_test/linkedList/unit_test.cpp \
 test/unit_test/data/unit_test.cpp \
 test/random_test/random_test.cpp \
 src/ann/xtensor_lib.cpp src/util/Point.cpp


# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo -e "\033[36m\033[1mCompilation successful. Run ./main to execute.\033[0m"
    echo -e "\033[32m\033[1mterminal unit test\033[0m"
    echo -e "\033[31m./main test_unit_array\033[0m"
    echo -e "\033[31m./main test_unit_array nameFunctionUnitTest\033[0m"
    echo
    echo -e "\033[32m\033[1mterminal unit test\033[0m"
    echo -e "\033[31m./main test_unit_linkeList\033[0m"
    echo -e "\033[31m./main test_unit_linkeList nameFunctionUnitTest\033[0m"
    echo
    echo -e "\033[32m\033[1mterminal auto test\033[0m"
    echo -e "\033[31m./main test_random number_1 number_2\033[0m"
    echo -e "\033[31m./main test_random number\033[0m"
else
    echo -e "\033[31m\033[1mCompilation failed.\033[0m"
fi