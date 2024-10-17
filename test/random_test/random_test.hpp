/*
 * Assignment 1 - Developing List Data Structures and Artificial Neural Networks
 * file : random_test.hpp
 * Data Structures and Algorithms
 * Author: Võ Tiến
 * Link FB : https://www.facebook.com/Shiba.Vo.Tien
 * Link Group : https://www.facebook.com/groups/khmt.ktmt.cse.bku
 * Date: 10.9.2024
 */
#ifndef RANDOM_TEST_HPP
#define RANDOM_TEST_HPP

#include "../../main.hpp"
#include "ann/dataloader.h"
#include "util/Point.h"
class RandomTest {
 public:
  RandomTest(int from, int to);

  void runTest();

 private:
  void processFile(string inputFilename, string outputFilename);
  void compareOutputs();
  int from;
  int to;

  // ANSI escape codes for colors
  const std::string green = "\033[32m";
  const std::string red = "\033[31m";
  const std::string cyan = "\033[36m";
  const std::string reset = "\033[0m";  // To reset to default color

  bool compareFiles(const std::string &file1, const std::string &file2);
};

#endif  // RANDOM_TEST_HPP