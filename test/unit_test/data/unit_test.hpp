/*
 * Assignment 1 - Developing List Data Structures and Artificial Neural Networks
 * file : unit_test.hpp
 * Data Structures and Algorithms
 * Author: Võ Tiến
 * Link FB : https://www.facebook.com/Shiba.Vo.Tien
 * Link Group : https://www.facebook.com/groups/khmt.ktmt.cse.bku
 * Date: 10.9.2024
 */
#ifndef UNIT_TEST_DATA_HPP
#define UNIT_TEST_DATA_HPP

#include "../../../main.hpp"
#include "ann/dataloader.h"

class T_Data {
 public:
  T_Data() {
    // test Array List
    T_Data::registerTest("data01", &T_Data::data1);
    T_Data::registerTest("data02", &T_Data::data2);
    T_Data::registerTest("data03", &T_Data::data3);
    T_Data::registerTest("data04", &T_Data::data4);
    T_Data::registerTest("data05", &T_Data::data5);
    T_Data::registerTest("data06", &T_Data::data6);
    T_Data::registerTest("data07", &T_Data::data7);
    T_Data::registerTest("data08", &T_Data::data8);
    T_Data::registerTest("data09", &T_Data::data9);
    T_Data::registerTest("data10", &T_Data::data10);
    T_Data::registerTest("data11", &T_Data::data11);
    T_Data::registerTest("data12", &T_Data::data12);
    T_Data::registerTest("data13", &T_Data::data13);
    T_Data::registerTest("data14", &T_Data::data14);
    T_Data::registerTest("data15", &T_Data::data15);
    T_Data::registerTest("data16", &T_Data::data16);
    T_Data::registerTest("data17", &T_Data::data17);
    T_Data::registerTest("data18", &T_Data::data18);
    T_Data::registerTest("data19", &T_Data::data19);
    T_Data::registerTest("data20", &T_Data::data20);
    T_Data::registerTest("data21", &T_Data::data21);
    T_Data::registerTest("data22", &T_Data::data22);
    T_Data::registerTest("data23", &T_Data::data23);
    T_Data::registerTest("data24", &T_Data::data24);
    T_Data::registerTest("data25", &T_Data::data25);
    T_Data::registerTest("data26", &T_Data::data26);
    T_Data::registerTest("data27", &T_Data::data27);
    T_Data::registerTest("data28", &T_Data::data28);
    T_Data::registerTest("data29", &T_Data::data29);
    T_Data::registerTest("data30", &T_Data::data30);
    T_Data::registerTest("data31", &T_Data::data31);
     T_Data::registerTest("data32", &T_Data::data32); 
     T_Data::registerTest("data33", &T_Data::data33);
     T_Data::registerTest("data34", &T_Data::data34);

    // TODO unit new
  }

 private:
  bool data1();
  bool data2();
  bool data3();
  bool data4();
  bool data5();
  bool data6();
  bool data7();
  bool data8();
  bool data9();
  bool data10();
  bool data11();
  bool data12();
  bool data13();
  bool data14();
  bool data15();
  bool data16();
  bool data17();
  bool data18();
  bool data19();
  bool data20();
  bool data21();
  bool data22();
  bool data23();
  bool data24();
  bool data25();
  bool data26();
  bool data27();
  bool data28();
  bool data29();
  bool data30();
  bool data31();
  bool data32();
  bool data33();
  bool data34();
  // TODO unit new

 public:
  static map<string, bool (T_Data::*)()> TESTS;
  // ANSI escape codes for colors
  const string green = "\033[32m";
  const string red = "\033[31m";
  const string cyan = "\033[36m";
  const string reset = "\033[0m";  // To reset to default color

  bool printResult(string output, string expect, string name) {
    if (expect == output) {
      cout << green << "test " + name + " --------------- PASS" << reset
           << "\n";
      return true;
    } else {
      cout << red << "test " + name + " --------------- FAIL" << reset << "\n";
      cout << "\texpect : " << expect << endl;
      cout << "\toutput : " << output << endl;
      return false;
    }
  }

  static void registerTest(string name, bool (T_Data::*function)()) {
    if (TESTS.find(name) != TESTS.end()) {
      throw std::runtime_error("Test with name '" + name + "' already exists.");
    }
    TESTS[name] = function;
  }

  void runTest(const std::string &name) {
    auto it = TESTS.find(name);
    if (it != TESTS.end()) {
      (this->*(it->second))();  // Gọi hàm kiểm tra
    } else {
      throw std::runtime_error("Test with name '" + name + "' does not exist.");
    }
  }

  void runAllTests() {
    vector<string> fails;
    for (const auto &test : TESTS) {
      if (!(this->*(test.second))()) {
        fails.push_back(test.first);
      }
    }

    cout << cyan << "\nResult -------------------------" << reset << endl;
    // Print the results
    if (fails.empty()) {
      cout << green << "All tests passed!" << reset << endl;
    } else {
      int totalTests = TESTS.size();
      int failedTests = fails.size();
      int passedTests = totalTests - failedTests;
      double passRate =
          (totalTests > 0)
              ? (static_cast<double>(passedTests) / totalTests) * 100.0
              : 0.0;
      cout << red << "Some tests failed:";
      for (const auto &fail : fails) {
        cout << "  " << fail;
      }
      cout << cyan << "\nPass rate: " << passRate << "%" << reset << endl;
    }
  }
};

#endif  // UNIT_TEST_DATA_HPP