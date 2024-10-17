/*
 * Assignment 1 - Developing List Data Structures and Artificial Neural Networks
 * file : unit_test.hpp
 * Data Structures and Algorithms
 * Author: Võ Tiến
 * Link FB : https://www.facebook.com/Shiba.Vo.Tien
 * Link Group : https://www.facebook.com/groups/khmt.ktmt.cse.bku
 * Date: 10.9.2024
 */
#ifndef UNIT_TEST_ARRAY_HPP
#define UNIT_TEST_ARRAY_HPP

#include "../../../main.hpp"
#include "list/listheader.h"
#include "util/Point.h"
class T_ArrayList {
 public:
  T_ArrayList() {
    // test Array List
    T_ArrayList::registerTest("array01", &T_ArrayList::array1);
    T_ArrayList::registerTest("array02", &T_ArrayList::array2);
    T_ArrayList::registerTest("array03", &T_ArrayList::array3);
    T_ArrayList::registerTest("array04", &T_ArrayList::array4);
    T_ArrayList::registerTest("array05", &T_ArrayList::array5);
    T_ArrayList::registerTest("array06", &T_ArrayList::array6);
    T_ArrayList::registerTest("array07", &T_ArrayList::array7);
    T_ArrayList::registerTest("array08", &T_ArrayList::array8);
    T_ArrayList::registerTest("array09", &T_ArrayList::array9);
    T_ArrayList::registerTest("array10", &T_ArrayList::array10);
    T_ArrayList::registerTest("array11", &T_ArrayList::array11);
    T_ArrayList::registerTest("array12", &T_ArrayList::array12);
    T_ArrayList::registerTest("array13", &T_ArrayList::array13);
    T_ArrayList::registerTest("array14", &T_ArrayList::array14);
    T_ArrayList::registerTest("array15", &T_ArrayList::array15);
    T_ArrayList::registerTest("array16", &T_ArrayList::array16);
    T_ArrayList::registerTest("array17", &T_ArrayList::array17);
    T_ArrayList::registerTest("array18", &T_ArrayList::array18);
    T_ArrayList::registerTest("array19", &T_ArrayList::array19);
    T_ArrayList::registerTest("array20", &T_ArrayList::array20);
    T_ArrayList::registerTest("array21", &T_ArrayList::array21);
    T_ArrayList::registerTest("array22", &T_ArrayList::array22);
    T_ArrayList::registerTest("array23", &T_ArrayList::array23);
    T_ArrayList::registerTest("array24", &T_ArrayList::array24);
    T_ArrayList::registerTest("array25", &T_ArrayList::array25);
    T_ArrayList::registerTest("array26", &T_ArrayList::array26);
    T_ArrayList::registerTest("array27", &T_ArrayList::array27);
    T_ArrayList::registerTest("array28", &T_ArrayList::array28);
    T_ArrayList::registerTest("array29", &T_ArrayList::array29);
    T_ArrayList::registerTest("array30", &T_ArrayList::array30);
    T_ArrayList::registerTest("array31", &T_ArrayList::array31);
    T_ArrayList::registerTest("array32", &T_ArrayList::array32);
    T_ArrayList::registerTest("array33", &T_ArrayList::array33);
    T_ArrayList::registerTest("array34", &T_ArrayList::array34);
    T_ArrayList::registerTest("array35", &T_ArrayList::array35);
    // TODO unit new
  }

 private:
  bool array1();
  bool array2();
  bool array3();
  bool array4();
  bool array5();
  bool array6();
  bool array7();
  bool array8();
  bool array9();
  bool array10();
  bool array11();
  bool array12();
  bool array13();
  bool array14();
  bool array15();
  bool array16();
  bool array17();
  bool array18();
  bool array19();
  bool array20();
  bool array21();
  bool array22();
  bool array23();
  bool array24();
  bool array25();
  bool array26();
  bool array27();
  bool array28();
  bool array29();
  bool array30();
  bool array31();
  bool array32();
  bool array33();
  bool array34();
  bool array35();
  // TODO unit new

 public:
  static map<string, bool (T_ArrayList::*)()> TESTS;
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

  static void registerTest(string name, bool (T_ArrayList::*function)()) {
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

#endif  // UNIT_TEST_ARRAY_HPP