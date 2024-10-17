/*
 * Assignment 1 - Developing List Data Structures and Artificial Neural Networks
 * file : unit_test.hpp
 * Data Structures and Algorithms
 * Author: Võ Tiến
 * Link FB : https://www.facebook.com/Shiba.Vo.Tien
 * Link Group : https://www.facebook.com/groups/khmt.ktmt.cse.bku
 * Date: 10.9.2024
 */
#ifndef UNIT_TEST_LINKEDLIST_HPP
#define UNIT_TEST_LINKEDLIST_HPP

#include "../../../main.hpp"
#include "list/listheader.h"
#include "util/Point.h"

class T_LinkedList {
 public:
  T_LinkedList() {
    // test Array List
    T_LinkedList::registerTest("linkedList01", &T_LinkedList::linkedList1);
    T_LinkedList::registerTest("linkedList02", &T_LinkedList::linkedList2);
    T_LinkedList::registerTest("linkedList03", &T_LinkedList::linkedList3);
    T_LinkedList::registerTest("linkedList04", &T_LinkedList::linkedList4);
    T_LinkedList::registerTest("linkedList05", &T_LinkedList::linkedList5);
    T_LinkedList::registerTest("linkedList06", &T_LinkedList::linkedList6);
    T_LinkedList::registerTest("linkedList07", &T_LinkedList::linkedList7);
    T_LinkedList::registerTest("linkedList08", &T_LinkedList::linkedList8);
    T_LinkedList::registerTest("linkedList09", &T_LinkedList::linkedList9);
    T_LinkedList::registerTest("linkedList10", &T_LinkedList::linkedList10);
    T_LinkedList::registerTest("linkedList11", &T_LinkedList::linkedList11);
    T_LinkedList::registerTest("linkedList12", &T_LinkedList::linkedList12);
    T_LinkedList::registerTest("linkedList13", &T_LinkedList::linkedList13);
    T_LinkedList::registerTest("linkedList14", &T_LinkedList::linkedList14);
    T_LinkedList::registerTest("linkedList15", &T_LinkedList::linkedList15);
    T_LinkedList::registerTest("linkedList16", &T_LinkedList::linkedList16);
    T_LinkedList::registerTest("linkedList17", &T_LinkedList::linkedList17);
    T_LinkedList::registerTest("linkedList18", &T_LinkedList::linkedList18);
    T_LinkedList::registerTest("linkedList19", &T_LinkedList::linkedList19);
    T_LinkedList::registerTest("linkedList20", &T_LinkedList::linkedList20);
    T_LinkedList::registerTest("linkedList21", &T_LinkedList::linkedList21);
    T_LinkedList::registerTest("linkedList22", &T_LinkedList::linkedList22);
    T_LinkedList::registerTest("linkedList23", &T_LinkedList::linkedList23);
    T_LinkedList::registerTest("linkedList24", &T_LinkedList::linkedList24);
    T_LinkedList::registerTest("linkedList25", &T_LinkedList::linkedList25);
    T_LinkedList::registerTest("linkedList26", &T_LinkedList::linkedList26);
    T_LinkedList::registerTest("linkedList27", &T_LinkedList::linkedList27);
    T_LinkedList::registerTest("linkedList28", &T_LinkedList::linkedList28);
    T_LinkedList::registerTest("linkedList29", &T_LinkedList::linkedList29);
    T_LinkedList::registerTest("linkedList30", &T_LinkedList::linkedList30);
    T_LinkedList::registerTest("linkedList31", &T_LinkedList::linkedList31);
    T_LinkedList::registerTest("linkedList32", &T_LinkedList::linkedList32);
    T_LinkedList::registerTest("linkedList33", &T_LinkedList::linkedList33);
    T_LinkedList::registerTest("linkedList34", &T_LinkedList::linkedList34);
    T_LinkedList::registerTest("linkedList35", &T_LinkedList::linkedList35);
    T_LinkedList::registerTest("linkedList36", &T_LinkedList::linkedList36);
    // TODO unit new
  }

 private:
  bool linkedList1();
  bool linkedList2();
  bool linkedList3();
  bool linkedList4();
  bool linkedList5();
  bool linkedList6();
  bool linkedList7();
  bool linkedList8();
  bool linkedList9();
  bool linkedList10();
  bool linkedList11();
  bool linkedList12();
  bool linkedList13();
  bool linkedList14();
  bool linkedList15();
  bool linkedList16();
  bool linkedList17();
  bool linkedList18();
  bool linkedList19();
  bool linkedList20();
  bool linkedList21();
  bool linkedList22();
  bool linkedList23();
  bool linkedList24();
  bool linkedList25();
  bool linkedList26();
  bool linkedList27();
  bool linkedList28();
  bool linkedList29();
  bool linkedList30();
  bool linkedList31();
  bool linkedList32();
  bool linkedList33();
  bool linkedList34();
  bool linkedList35();
  bool linkedList36();
  // TODO unit new

 public:
  static map<string, bool (T_LinkedList::*)()> TESTS;
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

  static void registerTest(string name, bool (T_LinkedList::*function)()) {
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

#endif  // UNIT_TEST_LINKEDLIST_HPP