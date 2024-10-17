/*
 * Assignment 1 - Developing List Data Structures and Artificial Neural Networks
 * file : random_test.cpp
 * Data Structures and Algorithms
 * Author: Võ Tiến
 * Link FB : https://www.facebook.com/Shiba.Vo.Tien
 * Link Group : https://www.facebook.com/groups/khmt.ktmt.cse.bku
 * Date: 10.9.2024
 */
#include "random_test.hpp"

struct Task1 {
  int number_line, capacity;
  string skip, _iList, _type, _itemEqual, _deleteUserData;
};

RandomTest::RandomTest(int from, int to) : from(from), to(to) {}

void RandomTest::runTest() {
  for (int i = from; i <= to; ++i) {
    std::string inputFilename =
        "test/random_test/input/input_" + std::to_string(i);
    std::string outputFilename =
        "test/random_test/output/output_" + std::to_string(i);
    // "test/random_test/expected/expected_" + std::to_string(i);
    processFile(inputFilename, outputFilename);
  }

  compareOutputs();
}

void RandomTest::processFile(string inputFilename, string outputFilename) {
  std::ifstream file(inputFilename);
  // Check if the file was successfully opened
  if (!file.is_open()) {
    cerr << "Error: Could not open file " << inputFilename << endl;
    return;
  }

  int seed, batch_size;
  string skip, date_label, input, shuffle, drop_last;
  std::vector<std::size_t> shape;

  file >> skip >> skip >> seed;
  file >> skip >> skip >> date_label;
  file >> skip >> skip >> batch_size >> skip >> shuffle >> skip >> drop_last;
  file >> skip >> skip;
  while (file >> input) {
    if (input == "len")
      break;
    else if (input == "x")
      continue;
    shape.push_back(stoi(input));
  }
  file >> skip >> skip >> skip;

  std::ofstream outFile(outputFilename);
  if (!outFile) {
    std::cerr << "Error opening output file: " << outputFilename << '\n';
    return;
  }

  xt::random::default_engine_type engine(seed);
  xt::xarray<double> data =
      xt::random::randn<double>(shape, 0.0f, 100.0f, engine);
  xt::xarray<int> label;

  if (date_label != "null") {
    label = xt::random::randint<int>({shape[0]}, 0, 100, engine);
  }
  TensorDataset<double, int> tensor(data, label);
  DataLoader<double, int> loader(&tensor, batch_size, shuffle == "True",
                                 drop_last == "True");
  outFile << "len=" << tensor.len() << endl;
  outFile << "get_data_shape=" << shape2str(tensor.get_data_shape()) << endl;
  outFile << "get_data_shape=" << shape2str(tensor.get_label_shape()) << endl;
  outFile << "foreach" << endl;
  for (auto batch : loader) {
    outFile << "getData " << batch.getData() << endl;
    outFile << "getLabel " << batch.getLabel() << endl;
  }
  int index;
  while (file >> input) {
    file >> index;
    outFile << input << " " << index << endl;
    try {
      DataLabel<double, int> getitem = tensor.getitem(index);
      xt::xarray<double> getData = getitem.getData();
      xt::xarray<int> getLabel = getitem.getLabel();
      outFile << "getData " << getData << endl;
      outFile << "getLabel " << getLabel << endl;
    } catch (const std::out_of_range &e) {
      outFile << "Error: Out of range exception: " + string(e.what()) << endl;
    }
  }
}

void RandomTest::compareOutputs() {
  std::vector<std::string> fails;
  int totalTests = 0;

  for (int i = from; i <= to; ++i) {
    std::string outputFile =
        "test/random_test/output/output_" + std::to_string(i);
    std::string expectedFile =
        "test/random_test/expected/expected_" + std::to_string(i);

    try {
      bool result = compareFiles(outputFile, expectedFile);
      if (result) {
        // Print pass message if files match
        std::cout << "Test input_" << i << " --------------- PASS";
      } else {
        // Print fail message if files don't match
        fails.push_back("input_" + std::to_string(i));
        std::cout << "Test input_" << i << " --------------- FAIL";
      }
      ++totalTests;
    } catch (const std::runtime_error &e) {
      std::cerr << "Error: " << e.what() << '\n';
    }
  }

  std::cout << cyan << "\nResult -------------------------" << reset << '\n';
  if (fails.empty()) {
    std::cout << green << "All tests passed!" << reset << '\n';
  } else {
    int failedTests = fails.size();
    int passedTests = totalTests - failedTests;
    double passRate =
        (totalTests > 0)
            ? (static_cast<double>(passedTests) / totalTests) * 100.0
            : 0.0;

    std::cout << red << "Some tests failed:";
    for (const auto &fail : fails) {
      std::cout << "  " << fail;
    }
    std::cout << cyan << "\nPass rate: " << passRate << "%" << reset << '\n';
  }
}

bool RandomTest::compareFiles(const std::string &file1,
                              const std::string &file2) {
  std::ifstream f1(file1);
  std::ifstream f2(file2);

  if (!f1.is_open() || !f2.is_open()) {
    throw std::runtime_error("Could not open files for comparison.");
  }

  std::stringstream buffer1, buffer2;
  buffer1 << f1.rdbuf();
  buffer2 << f2.rdbuf();

  return buffer1.str() == buffer2.str();
}
