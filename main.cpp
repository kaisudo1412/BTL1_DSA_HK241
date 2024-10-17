/*
 * Assignment 1 - Developing List Data Structures and Artificial Neural Networks
 * file : main.cpp
 * Data Structures and Algorithms
 * Author: Võ Tiến
 * Link FB : https://www.facebook.com/Shiba.Vo.Tien
 * Link Group : https://www.facebook.com/groups/khmt.ktmt.cse.bku
 * Date: 18.9.2024

 ! build code : g++ -fsanitize=address  -o main -Iinclude -Isrc -std=c++17
 main.cpp test/unit_test/arrayList/unit_test.cpp
                test/unit_test/linkedList/unit_test.cpp
                test/unit_test/data/unit_test.cpp
                test/random_test/random_test.cpp
                src/ann/xtensor_lib.cpp src/util/Point.cpp

 * run code
    * terminal unit test array list
    !./main test_unit_array
    !./main test_unit_array nameFunctionUnitTest

    * terminal unit test linked list
    ! ./main test_unit_linkedList
    ! ./main test_unit_linkedList nameFunctionUnitTest

    * terminal unit test dataset
    ! ./main test_unit_data
    ! ./main test_unit_data nameFunctionUnitTest

    * terminal auto test
    ! ./main test_random number_1 number_2
    ! ./main test_random number
*/

#include "test/random_test/random_test.hpp"
#include "test/unit_test/arrayList/unit_test.hpp"
#include "test/unit_test/data/unit_test.hpp"
#include "test/unit_test/linkedList/unit_test.hpp"
void printTestCase();
void handleTestUnitArray(int argc, char *argv[]);
void handleTestUnitLinkedList(int argc, char *argv[]);
void handleTestRandom(int argc, char *argv[]);
void handleTestUnitData(int argc, char *argv[]);

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    printTestCase();
    return 1;
  }

  std::string arg1 = argv[1];
  if (arg1 == "test_unit_array") {
    handleTestUnitArray(argc, argv);
  } else if (arg1 == "test_unit_linkedList") {
    handleTestUnitLinkedList(argc, argv);
  } else if (arg1 == "test_unit_data") {
    handleTestUnitData(argc, argv);
  } else if (arg1 == "test_random") {
    handleTestRandom(argc, argv);
  } else {
    printTestCase();
  }
}

void handleTestUnitArray(int argc, char *argv[]) {
  T_ArrayList unitTest;

  if (argc == 2 || (argc == 3 && std::string(argv[2]) == "all")) {
    std::cout << "Running all unit tests array: ----------\n";
    unitTest.runAllTests();
  } else if (argc == 3) {
    std::cout << "Running unit test array: " << argv[2] << " ----------\n";
    unitTest.runTest(argv[2]);
  } else {
    printTestCase();
  }
}

void handleTestUnitLinkedList(int argc, char *argv[]) {
  T_LinkedList unitTest;

  if (argc == 2 || (argc == 3 && std::string(argv[2]) == "all")) {
    std::cout << "Running all unit tests data: ----------\n";
    unitTest.runAllTests();
  } else if (argc == 3) {
    std::cout << "Running unit test data: " << argv[2] << " ----------\n";
    unitTest.runTest(argv[2]);
  } else {
    printTestCase();
  }
}

void handleTestUnitData(int argc, char *argv[]) {
  T_Data unitTest;

  if (argc == 2 || (argc == 3 && std::string(argv[2]) == "all")) {
    std::cout << "Running all unit tests linked list: ----------\n";
    unitTest.runAllTests();
  } else if (argc == 3) {
    std::cout << "Running unit test linked list: " << argv[2]
              << " ----------\n";
    unitTest.runTest(argv[2]);
  } else {
    printTestCase();
  }
}

void handleTestRandom(int argc, char *argv[]) {
  if (argc == 3) {
    try {
      int number = std::stoi(argv[2]);
      std::cout << "Running RandomTest with single number: " << number
                << " ----------\n";
      RandomTest random(number, number);
      random.runTest();
    } catch (const std::invalid_argument &e) {
      std::cerr << "Invalid number argument: " << e.what() << std::endl;
    }
  } else if (argc == 4) {
    try {
      int number1 = std::stoi(argv[2]);
      int number2 = std::stoi(argv[3]);
      std::cout << "Running RandomTest with numbers: " << number1 << " to "
                << number2 << " ----------\n";
      RandomTest random(number1, number2);
      random.runTest();
    } catch (const std::invalid_argument &e) {
      std::cerr << "Invalid number argument: " << e.what() << std::endl;
    }
  } else {
    printTestCase();
  }
}

void printTestCase() {
  const std::string RESET = "\033[0m";
  const std::string BOLD = "\033[1m";
  const std::string RED = "\033[31m";
  const std::string GREEN = "\033[32m";
  const std::string CYAN = "\033[36m";

  std::cout << GREEN << BOLD << "terminal unit test array list" << RESET
            << std::endl;
  std::cout << RED << "./main test_unit_array" << RESET << std::endl;
  std::cout << RED << "./main test_unit_array nameFunctionUnitTest" << RESET
            << std::endl
            << std::endl;

  std::cout << GREEN << BOLD << "terminal unit test linked list" << RESET
            << std::endl;
  std::cout << RED << "./main test_unit_linkedList" << RESET << std::endl;
  std::cout << RED << "./main test_unit_linkedList nameFunctionUnitTest"
            << RESET << std::endl
            << std::endl;
  std::cout << GREEN << BOLD << "terminal unit test data" << RESET << std::endl;
  std::cout << RED << "./main test_unit_data" << RESET << std::endl;
  std::cout << RED << "./main test_unit_data nameFunctionUnitTest" << RESET
            << std::endl
            << std::endl;

  std::cout << GREEN << BOLD << "terminal auto test" << RESET << std::endl;
  std::cout << RED << "./main test_random number_1 number_2" << RESET
            << std::endl;
  std::cout << RED << "./main test_random number" << RESET << std::endl;
}