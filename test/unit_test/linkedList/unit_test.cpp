/*
 * Assignment 1 - Developing List Data Structures and Artificial Neural Networks
 * file : unit_test.cpp
 * Data Structures and Algorithms
 * Author: Võ Tiến
 * Link FB : https://www.facebook.com/Shiba.Vo.Tien
 * Link Group : https://www.facebook.com/groups/khmt.ktmt.cse.bku
 * Date: 10.9.2024
 */
#include "unit_test.hpp"
map<string, bool (T_LinkedList::*)()> T_LinkedList::TESTS;

bool T_LinkedList::linkedList1() {
  string name = "linkedList1";
  //! data
  DLinkedList<int> list;

  //! expect
  string expect = "[]\nsize=0\nempty=1";

  //! output
  string output = list.toString() + "\nsize=" + to_string(list.size()) +
                  "\nempty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_LinkedList::linkedList2() {
  string name = "linkedList2";
  //! data
  DLinkedList<int> list;
  list.add(0);

  //! expect
  string expect = "[0]\nsize=1\nempty=0";

  //! output
  string output = list.toString() + "\nsize=" + to_string(list.size()) +
                  "\nempty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_LinkedList::linkedList3() {
  string name = "linkedList3";
  //! data
  DLinkedList<int> list;
  list.add(0);
  list.add(1);
  list.add(2);
  list.add(3);
  list.add(4);
  list.add(5);
  list.add(6);
  list.add(7);
  list.add(8);
  list.add(9);
  list.add(10);

  //! expect
  string expect = "[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]\nsize=11\nempty=0";

  //! output
  string output = list.toString() + "\nsize=" + to_string(list.size()) +
                  "\nempty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_LinkedList::linkedList4() {
  string name = "linkedList4";
  //! data
  DLinkedList<int> list;
  list.add(0, 0);
  list.add(0, 1);
  list.add(0, 2);
  list.add(2, 3);

  //! expect
  string expect = "[2, 1, 3, 0]\nsize=4";

  //! output
  string output = list.toString() + "\nsize=" + to_string(list.size());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_LinkedList::linkedList5() {
  string name = "linkedList5";
  //! data
  DLinkedList<int> list;
  list.add(0);
  list.add(0, 1);
  list.add(1, 2);
  list.add(3, 3);
  list.add(2, 4);
  list.add(4, 5);
  list.add(6);
  list.add(6, 7);
  list.add(0, 8);
  list.add(1, 9);
  list.add(2, 10);

  //! expect
  string expect = "[8, 9, 10, 1, 2, 4, 0, 5, 3, 7, 6]\nsize=11";

  //! output
  string output = list.toString() + "\nsize=" + to_string(list.size());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_LinkedList::linkedList6() {
  string name = "linkedList6";
  //! data
  DLinkedList<int> list;

  //! expect
  string expect = "Error: Out of range exception: Index is out of range!";

  //! output
  string output = "";
  try {
    list.add(1, 0);
  } catch (const std::out_of_range &e) {
    output = "Error: Out of range exception: " + string(e.what());
  }

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_LinkedList::linkedList7() {
  string name = "linkedList7";
  //! data
  DLinkedList<int> list;
  list.add(0, 0);
  list.add(0, 1);
  list.add(0, 2);

  //! expect
  string expect = "Error: Out of range exception: Index is out of range!";

  //! output
  string output = "";
  try {
    list.add(-1, 3);
  } catch (const std::out_of_range &e) {
    output = "Error: Out of range exception: " + string(e.what());
  }
  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_LinkedList::linkedList8() {
  string name = "linkedList8";
  //! data
  DLinkedList<int> list;

  //! expect
  string expect = "Error: Out of range exception: Index is out of range!";

  //! output
  string output = "";
  try {
    list.removeAt(0);
  } catch (const std::out_of_range &e) {
    output = "Error: Out of range exception: " + string(e.what());
  }

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_LinkedList::linkedList9() {
  string name = "linkedList9";
  //! data
  DLinkedList<int> list;
  list.add(0, 0);
  list.add(0, 1);
  list.add(0, 2);

  //! expect
  string expect = "Error: Out of range exception: Index is out of range!";

  //! output
  string output = "";
  try {
    list.removeAt(3);
  } catch (const std::out_of_range &e) {
    output = "Error: Out of range exception: " + string(e.what());
  }
  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_LinkedList::linkedList10() {
  string name = "linkedList10";
  //! data
  DLinkedList<int> list;
  list.add(0);
  list.removeAt(0);
  //! expect
  string expect = "[]\nsize=0\nempty=1";

  //! output
  string output = list.toString() + "\nsize=" + to_string(list.size()) +
                  "\nempty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_LinkedList::linkedList11() {
  string name = "linkedList11";
  //! data
  DLinkedList<int> list;
  list.add(0);
  list.add(1);
  list.add(2);
  list.removeAt(1);
  list.add(1, 1);
  list.removeAt(2);
  //! expect
  string expect = "[0, 1];size=2;empty=0";

  //! output
  string output = list.toString() + ";size=" + to_string(list.size()) +
                  ";empty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_LinkedList::linkedList12() {
  string name = "linkedList12";
  //! data
  DLinkedList<int> list;
  list.add(0);
 
  

  //! expect
  string expect = "removeItem=1;[];size=0;empty=1";

  //! output
  string output = "removeItem=" + to_string(list.removeItem(0)) + ";";
  output += list.toString() + ";size=" + to_string(list.size()) +
            ";empty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_LinkedList::linkedList13() {
  string name = "linkedList13";
  //! data
  DLinkedList<int> list;
  list.add(0);

  //! expect
  string expect = "removeItem=0;[0];size=1;empty=0";

  //! output
  string output = "removeItem=" + to_string(list.removeItem(1)) + ";";
  output += list.toString() + ";size=" + to_string(list.size()) +
            ";empty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_LinkedList::linkedList14() {
  string name = "linkedList14";
  //! data
  DLinkedList<int> list;
  list.add(0);
  list.add(1);
  list.add(2);
  list.add(1);

  //! expect
  string expect = "removeItem=1;[0, 2, 1];size=3;empty=0";

  //! output
  string output = "removeItem=" + to_string(list.removeItem(1)) + ";";
  output += list.toString() + ";size=" + to_string(list.size()) +
            ";empty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_LinkedList::linkedList15() {
  string name = "linkedList15";
  //! data
  DLinkedList<int> list;
  list.add(0);
  list.add(1);
  list.add(2);
  list.add(1);

  //! expect
  string expect = "removeItem=1;[0, 2, 1];size=3;empty=0";

  //! output
  string output = "removeItem=" + to_string(list.removeItem(1)) + ";";
  output += list.toString() + ";size=" + to_string(list.size()) +
            ";empty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_LinkedList::linkedList16() {
  string name = "linkedList16";
  //! data
  DLinkedList<int> list;
  list.add(0);
  list.add(1);
  list.add(2);
  list.add(1);

  //! expect
  string expect = "removeItem=0;[0, 1, 2, 1];size=4;empty=0";

  //! output
  string output = "removeItem=" + to_string(list.removeItem(-1)) + ";";
  output += list.toString() + ";size=" + to_string(list.size()) +
            ";empty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_LinkedList::linkedList17() {
  string name = "linkedList17";
  //! data
  DLinkedList<int> list;
  list.clear();
  list.add(0);
  list.add(1);
  list.add(2);
  list.add(1);
  list.clear();
  list.add(2);
  list.add(1);
  list.clear();
  //! expect
  string expect = "[];size=0;empty=1";

  //! output
  string output = list.toString() + ";size=" + to_string(list.size()) +
                  ";empty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_LinkedList::linkedList18() {
  string name = "linkedList18";
  //! data
  DLinkedList<int> list;

  //! expect
  string expect = "Error: Out of range exception: Index is out of range!";

  //! output
  string output = "";
  try {
    list.get(0);
  } catch (const std::out_of_range &e) {
    output = "Error: Out of range exception: " + string(e.what());
  }
  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_LinkedList::linkedList19() {
  string name = "linkedList19";
  //! data
  DLinkedList<int> list;
  list.add(0);
  list.add(1);
  list.add(2);

  //! expect
  string expect = "Error: Out of range exception: Index is out of range!";

  //! output
  string output = "";
  try {
    list.get(-1);
  } catch (const std::out_of_range &e) {
    output = "Error: Out of range exception: " + string(e.what());
  }
  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_LinkedList::linkedList20() {
  string name = "linkedList20";
  //! data
  DLinkedList<int> list;
  list.add(0);
  list.add(10);
  list.add(2);

  //! expect
  string expect = "get=10;[0, 10, 2];size=3;empty=0";

  //! output
  string output = "get=" + to_string(list.get(1)) + ";";
  output += list.toString() + ";size=" + to_string(list.size()) +
            ";empty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_LinkedList::linkedList21() {
  string name = "linkedList21";
  //! data
  DLinkedList<int> list;
  list.clear();
  list.add(0);
  list.add(1);
  list.add(2);
  list.add(1);

  //! expect
  string expect = "Index of item 1: 1";

  //! output
  int index = list.indexOf(1);
  string output = "Index of item 1: " + to_string(index);

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_LinkedList::linkedList22() {
  string name = "linkedList22";
  //! data
  DLinkedList<int> list;
  list.clear();
  list.add(0);
  list.add(1);
  list.add(2);
  list.add(1);

  //! expect
  string expect = "Index of item 1: -1";

  //! output
  int index = list.indexOf(-1);
  string output = "Index of item 1: " + to_string(index);

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_LinkedList::linkedList23() {
  string name = "linkedList23";
  //! data
  DLinkedList<int> list;
  list.clear();
  list.add(0);
  list.add(1);
  list.add(2);

  //! expect
  string expect = "Contains item 1: true";

  //! output
  bool contains = list.contains(1);
  string output = "Contains item 1: " + string(contains ? "true" : "false");

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_LinkedList::linkedList24() {
  string name = "linkedList24";
  //! data
  DLinkedList<int> list;
  list.clear();
  list.add(0);
  list.add(1);
  list.add(2);

  //! expect
  string expect = "Contains item 1: false";

  //! output
  bool contains = list.contains(3);
  string output = "Contains item 1: " + string(contains ? "true" : "false");

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_LinkedList::linkedList25() {
  string name = "linkedList25";
  //! data
  DLinkedList<Point> list;
  list.add(Point(23.2f, 25.4f));
  list.add(Point(24.6f, 23.1f));

  //! expect
  string expect = "[X: 23.2, X: 24.6]";

  //! output
  string output = list.toString(&Point::point2str_X);

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_LinkedList::linkedList26() {
  string name = "linkedList26";
  //! data
  DLinkedList<Point> list;
  list.add(Point(23.2f, 25.4f));
  list.add(Point(24.6f, 23.1f));

  //! expect
  string expect = "[P(23.2, 25.4, 0), P(24.6, 23.1, 0)]";

  //! output
  string output = list.toString(&Point::point2str);

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_LinkedList::linkedList27() {
  string name = "linkedList27";
  //! data
  DLinkedList<Point> list(0, &Point::pointEQ);
  list.add(Point(3.f, 4.f));
  list.add(Point(4.f, 3.f));

  //! expect
  string expect = "Index of item 1: -1";

  //! output
  int index = list.indexOf(Point(3.f, 5.f));
  string output = "Index of item 1: " + to_string(index);

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_LinkedList::linkedList28() {
  string name = "linkedList28";
  //! data
  DLinkedList<Point> list(0, &Point::pointEQ);
  list.add(Point(3.f, 4.f));
  list.add(Point(4.f, 3.f));

  //! expect
  string expect = "Index of item 1: 1";

  //! output
  int index = list.indexOf(Point(4.f, 3.f));
  string output = "Index of item 1: " + to_string(index);

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_LinkedList::linkedList29() {
  string name = "linkedList29";
  //! data
  DLinkedList<Point> list(0, &Point::pointEQ_X);
  list.add(Point(3.f, 4.f));
  list.add(Point(4.f, 3.f));

  //! expect
  string expect = "Contains item 1: true";

  //! output
  bool contains = list.contains(Point(3.f, 5.f));
  string output = "Contains item 1: " + string(contains ? "true" : "false");

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_LinkedList::linkedList30() {
  string name = "linkedList30";
  //! data
  DLinkedList<Point *> list(&DLinkedList<Point *>::free, &Point::pointEQ);
  list.add(new Point(23.2f, 25.4f));
  list.add(new Point(24.6f, 23.1f));
  list.add(new Point(12.5f, 22.3f));

  //! expect
  string expect = "[P(23.2, 25.4, 0), P(24.6, 23.1, 0), P(12.5, 22.3, 0)]";

  //! output
  string output = list.toString(&Point::point2str);

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_LinkedList::linkedList31() {
  string name = "linkedList31";
  //! data
  DLinkedList<Point *> list(&DLinkedList<Point *>::free, &Point::pointEQ);
  list.add(new Point(23.2f, 25.4f));
  list.add(new Point(24.6f, 23.1f));
  list.add(new Point(12.5f, 22.3f));
  list.clear();
  //! expect
  string expect = "[]";

  //! output
  string output = list.toString(&Point::point2str);

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_LinkedList::linkedList32() {
  string name = "linkedList32";
  //! data
  DLinkedList<Point *> list(&DLinkedList<Point *>::free, &Point::pointEQ);
  list.add(new Point(23.2f, 25.4f));
  list.add(new Point(24.6f, 23.1f));
  list.add(new Point(12.5f, 22.3f));
  Point p = Point(23.2f, 25.4f);

  //! expect
  string expect = "removeItem=1";

  //! output

  string output =
      "removeItem=" + to_string(list.removeItem(&p, &Point::pointRemove));

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_LinkedList::linkedList33() {
  string name = "linkedList33";
  //! data
  DLinkedList<Point *> list(&DLinkedList<Point *>::free, &Point::pointEQ);
  list.add(new Point(23.2f, 25.4f));
  list.add(new Point(24.6f, 23.1f));
  list.add(new Point(12.5f, 22.3f));

  //! expect
  string expect =
      "[P(23.2, 25.4, 0.0), P(24.6, 23.1, 0.0), P(12.5, 22.3, 0.0)]";

  //! output
  stringstream output;
  output << "[";
  for (auto it = list.begin(); it != list.end(); ++it) {
    if (it != list.begin()) output << ", ";
    output << **it;
  }
  output << "]";

  //! remove data
  list.clear();  // Clear list to avoid memory leaks

  //! print result
  return printResult(output.str(), expect, name);
}

bool T_LinkedList::linkedList34() {
  string name = "linkedList34";
  //! data
  DLinkedList<Point *> list(&DLinkedList<Point *>::free, &Point::pointEQ);
  list.add(new Point(23.2f, 25.4f));
  list.add(new Point(24.6f, 23.1f));
  list.add(new Point(12.5f, 22.3f));

  auto interator = list.begin();
  interator.remove(&Point::pointRemove);
  interator++;
  interator.remove(&Point::pointRemove);

  //! expect
  string expect = "[P(12.5, 22.3, 0.0)]";

  //! output
  stringstream output;
  output << "[";
  for (auto it = list.begin(); it != list.end(); ++it) {
    if (it != list.begin()) output << ", ";
    output << **it;
  }
  output << "]";

  //! remove data
  list.clear();  // Clear list to avoid memory leaks

  //! print result
  return printResult(output.str(), expect, name);
}

bool T_LinkedList::linkedList35() {
  string name = "linkedList35";
  //! data
  DLinkedList<Point *> list(&DLinkedList<Point *>::free, &Point::pointEQ);
  list.add(new Point(23.2f, 25.4f));
  list.add(new Point(24.6f, 23.1f));
  list.add(new Point(12.5f, 22.3f));

  //! expect
  string expect =
      "[P(12.5, 22.3, 0.0), P(24.6, 23.1, 0.0), P(23.2, 25.4, 0.0)]";

  //! output
  stringstream output;
  output << "[";
  for (auto it = list.bbegin(); it != list.bend(); ++it) {
    if (it != list.bbegin()) output << ", ";
    output << **it;
  }
  output << "]";

  //! remove data
  list.clear();  // Clear list to avoid memory leaks

  //! print result
  return printResult(output.str(), expect, name);
}

bool T_LinkedList::linkedList36() {
  string name = "linkedList36";
  //! data
  DLinkedList<Point *> list(&DLinkedList<Point *>::free, &Point::pointEQ);
  list.add(new Point(23.2f, 25.4f));
  list.add(new Point(24.6f, 23.1f));
  list.add(new Point(12.5f, 22.3f));

  auto interator = list.bbegin();
  interator.remove(&Point::pointRemove);
  interator++;
  interator.remove(&Point::pointRemove);

  //! expect
  string expect = "[P(23.2, 25.4, 0.0)]";

  //! output
  stringstream output;
  output << "[";
  for (auto it = list.bbegin(); it != list.bend(); ++it) {
    if (it != list.bbegin()) output << ", ";
    output << **it;
  }
  output << "]";

  //! remove data
  list.clear();  // Clear list to avoid memory leaks

  //! print result
  return printResult(output.str(), expect, name);
}