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
map<string, bool (T_Data::*)()> T_Data::TESTS;

bool T_Data::data1() {
  string name = "data1";
  //! data
  xt::xarray<float> data = {1., 2., 3.};
  xt::xarray<string> label = {"one", "two", "three"};
  TensorDataset tensor(data, label);

  //! expect
  string expect = "len=3";

  //! output
  string output = "len=" + to_string(tensor.len());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_Data::data2() {
  string name = "data2";
  //! data
  xt::xarray<float> data = {{1., 2., 3.}, {1., 2., 3.}};
  xt::xarray<string> label = {"one", "two", "three"};
  TensorDataset tensor(data, label);

  //! expect
  string expect = "len=2";

  //! output
  string output = "len=" + to_string(tensor.len());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_Data::data3() {
  string name = "data3";
  //! data
  xt::xarray<float> data = {{{1., 2., 3.}, {1., 2., 3.}}};
  xt::xarray<string> label = {"one", "two", "three"};
  TensorDataset tensor(data, label);

  //! expect
  string expect = "len=1";

  //! output
  string output = "len=" + to_string(tensor.len());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_Data::data4() {
  string name = "data4";

  //! data
  xt::xarray<float> data = {1., 2., 3.};
  xt::xarray<string> label = {"one", "two", "three"};
  TensorDataset tensor(data, label);

  xt::svector<unsigned long> get_data_shape = tensor.get_data_shape();
  xt::svector<unsigned long> get_label_shape = tensor.get_label_shape();

  //! expect
  string expect = "data_shape=[3] label_shape=[3]";

  //! output
  stringstream ss;
  ss << "data_shape=[";
  for (size_t i = 0; i < get_data_shape.size(); ++i) {
    ss << get_data_shape[i];
    if (i != get_data_shape.size() - 1) {
      ss << ", ";
    }
  }
  ss << "] label_shape=[";
  for (size_t i = 0; i < get_label_shape.size(); ++i) {
    ss << get_label_shape[i];
    if (i != get_label_shape.size() - 1) {
      ss << ", ";
    }
  }
  ss << "]";

  string output = ss.str();

  //! print result
  return printResult(output, expect, name);
}

bool T_Data::data5() {
  string name = "data5";
  //! data
  xt::xarray<float> data = {{1., 2., 3.}, {1., 2., 3.}};
  xt::xarray<float> label = {{1., 2., 3.}, {1., 2., 3.}, {1., 2., 3.}};
  TensorDataset tensor(data, label);
  xt::svector<unsigned long> get_data_shape = tensor.get_data_shape();
  xt::svector<unsigned long> get_label_shape = tensor.get_label_shape();

  //! expect
  string expect = "data_shape=[2, 3] label_shape=[3, 3]";

  //! output
  stringstream ss;
  ss << "data_shape=[";
  for (size_t i = 0; i < get_data_shape.size(); ++i) {
    ss << get_data_shape[i];
    if (i != get_data_shape.size() - 1) {
      ss << ", ";
    }
  }
  ss << "] label_shape=[";
  for (size_t i = 0; i < get_label_shape.size(); ++i) {
    ss << get_label_shape[i];
    if (i != get_label_shape.size() - 1) {
      ss << ", ";
    }
  }
  ss << "]";

  string output = ss.str();

  //! print result
  return printResult(output, expect, name);
}

bool T_Data::data6() {
  string name = "data6";
  //! data
  xt::xarray<float> data = {{{1., 2., 3.}, {1., 2., 3.}}};
  xt::xarray<double>::shape_type shape = {2, 3, 1};
  xt::xarray<string> label(shape);

  TensorDataset tensor(data, label);
  xt::svector<unsigned long> get_data_shape = tensor.get_data_shape();
  xt::svector<unsigned long> get_label_shape = tensor.get_label_shape();

  //! expect
  string expect = "data_shape=[1, 2, 3] label_shape=[2, 3, 1]";

  //! output
  stringstream ss;
  ss << "data_shape=[";
  for (size_t i = 0; i < get_data_shape.size(); ++i) {
    ss << get_data_shape[i];
    if (i != get_data_shape.size() - 1) {
      ss << ", ";
    }
  }
  ss << "] label_shape=[";
  for (size_t i = 0; i < get_label_shape.size(); ++i) {
    ss << get_label_shape[i];
    if (i != get_label_shape.size() - 1) {
      ss << ", ";
    }
  }
  ss << "]";

  string output = ss.str();

  //! print result
  return printResult(output, expect, name);
}

bool T_Data::data7() {
  string name = "data7";
  //! data
  xt::xarray<float> data = {{1., 2., 3.}, {4., 5., 6.}, {7., 8., 9.}};
  xt::xarray<string> label = {"one", "two", "three"};
  TensorDataset tensor(data, label);
  DataLabel<float, string> getitem = tensor.getitem(0);
  xt::xarray<float> getData = getitem.getData();
  xt::xarray<string> getLabel = getitem.getLabel();
  //! expect
  string expect = "data= { 1.,  2.,  3.} label=one";

  //! output
  stringstream ss;
  ss << "data= " << getData << " " << "label=" << getLabel;
  string output = ss.str();

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_Data::data8() {
  string name = "data8";
  //! data
  xt::xarray<float> data = {{1., 2., 3.}, {4., 5., 6.}, {7., 8., 9.}};
  xt::xarray<string> label = {"one", "two", "three"};
  TensorDataset tensor(data, label);
  DataLabel<float, string> getitem = tensor.getitem(2);
  xt::xarray<float> getData = getitem.getData();
  xt::xarray<string> getLabel = getitem.getLabel();
  //! expect
  string expect = "data= { 7.,  8.,  9.} label=three";

  //! output
  stringstream ss;
  ss << "data= " << getData << " " << "label=" << getLabel;
  string output = ss.str();

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_Data::data9() {
  string name = "data9";
  //! data
  xt::xarray<float> data = {{1., 2., 3.}, {4., 5., 6.}, {7., 8., 9.}};
  xt::xarray<string> label = {"one", "two", "three"};
  TensorDataset tensor(data, label);
  //! expect
  string expect = "Error: Out of range exception: Index is out of range!";

  //! output
  string output = "";
  try {
    DataLabel<float, string> getitem = tensor.getitem(3);
  } catch (const std::out_of_range &e) {
    output = "Error: Out of range exception: " + string(e.what());
  }

  //! remove data

  //! print result
  return printResult(output, expect, name);
}
bool T_Data::data10() {
  string name = "data10";
  //! data
  xt::xarray<float> data = {{1., 2., 3.}, {4., 5., 6.}, {7., 8., 9.}};
  xt::xarray<string> label = {"one", "two", "three"};
  TensorDataset tensor(data, label);
  //! expect
  string expect = "Error: Out of range exception: Index is out of range!";

  //! output
  string output = "";
  try {
    DataLabel<float, string> getitem = tensor.getitem(-1);
  } catch (const std::out_of_range &e) {
    output = "Error: Out of range exception: " + string(e.what());
  }

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_Data::data11() {
  string name = "data11";
  //! data
  int nsamples = 100;
  xt::xarray<float> data = {1, 2, 3};
  xt::xarray<string> label = {"one", "two", "three"};
  TensorDataset<double, string> ds(data, label);
  DataLoader<double, string> loader(&ds, 3, false, false);
  //! expect
  string expect = "getData={ 1.,  2.,  3.} ; getLabel={  one,   two, three} ";

  //! output

  stringstream output;
  output << "getData=";
  for (auto it = loader.begin(); it != loader.end(); ++it) {
    output << (*it).getData() << " ";
  }
  output << "; getLabel=";
  for (auto it = loader.begin(); it != loader.end(); ++it) {
    output << (*it).getLabel() << " ";
  }
  //! remove data

  //! print result
  return printResult(output.str(), expect, name);
}

bool T_Data::data12() {
  string name = "data12";
  //! data
  int nsamples = 100;
  xt::xarray<float> data = {1, 2, 3, 4};
  xt::xarray<string> label = {"one", "two", "three", "four"};
  TensorDataset<double, string> ds(data, label);
  DataLoader<double, string> loader(&ds, 3, false, true);
  //! expect
  string expect = "getData={ 1.,  2.,  3.} ; getLabel={  one,   two, three} ";

  //! output

  stringstream output;
  output << "getData=";
  for (auto it = loader.begin(); it != loader.end(); ++it) {
    output << (*it).getData() << " ";
  }
  output << "; getLabel=";
  for (auto it = loader.begin(); it != loader.end(); ++it) {
    output << (*it).getLabel() << " ";
  }
  //! remove data

  //! print result
  return printResult(output.str(), expect, name);
}

bool T_Data::data13() {
  string name = "data13";
  //! data
  int nsamples = 100;
  xt::xarray<float> data = {1, 2, 3, 4};
  xt::xarray<string> label = {"one", "two", "three", "four"};
  TensorDataset<double, string> ds(data, label);
  DataLoader<double, string> loader(&ds, 3, false, false);
  //! expect
  string expect =
      "getData={ 1.,  2.,  3.,  4.} ; getLabel={  one,   two, three,  four} ";

  //! output

  stringstream output;
  output << "getData=";
  for (auto it = loader.begin(); it != loader.end(); ++it) {
    output << (*it).getData() << " ";
  }
  output << "; getLabel=";
  for (auto it = loader.begin(); it != loader.end(); ++it) {
    output << (*it).getLabel() << " ";
  }
  //! remove data

  //! print result
  return printResult(output.str(), expect, name);
}

bool T_Data::data14() {
  string name = "data14";
  //! data
  int nsamples = 100;
  xt::xarray<float> data = {1, 2};
  xt::xarray<string> label = {"one", "two"};
  TensorDataset<double, string> ds(data, label);
  DataLoader<double, string> loader(&ds, 3, false, false);
  //! expect
  string expect = "getData=; getLabel=";

  //! output

  stringstream output;
  output << "getData=";
  for (auto it = loader.begin(); it != loader.end(); ++it) {
    output << (*it).getData() << " ";
  }
  output << "; getLabel=";
  for (auto it = loader.begin(); it != loader.end(); ++it) {
    output << (*it).getLabel() << " ";
  }
  //! remove data

  //! print result
  return printResult(output.str(), expect, name);
}

bool T_Data::data15() {
  string name = "data15";
  //! data
  int nsamples = 100;
  xt::xarray<float> data = {1};
  xt::xarray<string> label = {"one"};
  TensorDataset<double, string> ds(data, label);
  DataLoader<double, string> loader(&ds, 3, false, true);
  //! expect
  string expect = "getData=; getLabel=";

  //! output

  stringstream output;
  output << "getData=";
  for (auto it = loader.begin(); it != loader.end(); ++it) {
    output << (*it).getData() << " ";
  }
  output << "; getLabel=";
  for (auto it = loader.begin(); it != loader.end(); ++it) {
    output << (*it).getLabel() << " ";
  }
  //! remove data

  //! print result
  return printResult(output.str(), expect, name);
}

bool T_Data::data16() {
  string name = "data16";
  //! data
  xt::xarray<float> data = {{1., 2., 3.}, {4., 5., 6.}, {7., 8., 9.}};
  xt::xarray<string> label = {"one", "two", "three"};
  TensorDataset<double, string> ds(data, label);
  DataLoader<double, string> loader(&ds, 4, false, true);
  //! expect
  string expect =
      "getData=;"
      "getLabel=";

  //! output

  stringstream output;
  output << "getData=";
  for (auto it = loader.begin(); it != loader.end(); ++it) {
    output << (*it).getData() << " ";
  }
  output << ";getLabel=";
  for (auto it = loader.begin(); it != loader.end(); ++it) {
    output << (*it).getLabel() << " ";
  }
  //! remove data

  //! print result
  return printResult(output.str(), expect, name);
}

bool T_Data::data17() {
  string name = "data17";
  //! data
  xt::xarray<float> data = {{1., 2., 3.}, {4., 5., 6.}, {7., 8., 9.}};
  xt::xarray<string> label = {"one", "two", "three"};
  TensorDataset<double, string> ds(data, label);
  DataLoader<double, string> loader(&ds, 3, false, true);
  //! expect
  string expect =
      "getData={{ 1.,  2.,  3.},\n { 4.,  5.,  6.},\n { 7.,  8.,  9.}} ;"
      "getLabel={  one,   two, three} ";

  //! output

  stringstream output;
  output << "getData=";
  for (auto it = loader.begin(); it != loader.end(); ++it) {
    output << (*it).getData() << " ";
  }
  output << ";getLabel=";
  for (auto it = loader.begin(); it != loader.end(); ++it) {
    output << (*it).getLabel() << " ";
  }
  //! remove data

  //! print result
  return printResult(output.str(), expect, name);
}

bool T_Data::data18() {
  string name = "data18";
  //! data
  xt::xarray<float> data = {{1., 2., 3.}, {4., 5., 6.}, {7., 8., 9.}};
  xt::xarray<string> label = {"one", "two", "three"};
  TensorDataset<double, string> ds(data, label);
  DataLoader<double, string> loader(&ds, 2, false, true);
  //! expect
  string expect =
      "getData={{ 1.,  2.,  3.},\n { 4.,  5.,  6.}} ; getLabel={one, two} ";

  //! output

  stringstream output;
  output << "getData=";
  for (auto it = loader.begin(); it != loader.end(); ++it) {
    output << (*it).getData() << " ";
  }
  output << "; getLabel=";
  for (auto it = loader.begin(); it != loader.end(); ++it) {
    output << (*it).getLabel() << " ";
  }
  //! remove data

  //! print result

  return printResult(output.str(), expect, name);
}

bool T_Data::data19() {
  string name = "data19";
  //! data
  int nsamples = 100;
  xt::xarray<double> X = xt::random::randn<double>({nsamples, 10});
  xt::xarray<double> T = xt::random::randn<double>({nsamples, 5});
  TensorDataset<double, double> ds(X, T);
  DataLoader<double, double> loader(&ds, 30, true, true);
  //! expect
  string expect = "(30, 10);(30, 5) (30, 10);(30, 5) (30, 10);(30, 5) ";

  //! output

  stringstream output;
  for (auto batch : loader) {
    output << shape2str(batch.getData().shape()) << ";";
    output << shape2str(batch.getLabel().shape()) << " ";
  }
  //! remove data

  //! print result
  return printResult(output.str(), expect, name);
}

bool T_Data::data20() {
  string name = "data20";
  //! data
  int nsamples = 120;
  xt::xarray<double> X = xt::random::randn<double>({nsamples, 10, 5});
  xt::xarray<double> T = xt::random::randn<double>({nsamples, 5, 5});
  TensorDataset<double, double> ds(X, T);
  DataLoader<double, double> loader(&ds, 30, true, true);
  //! expect
  string expect =
      "(30, 10, 5);(30, 5, 5) (30, 10, 5);(30, 5, 5) (30, 10, 5);(30, 5, 5) "
      "(30, 10, 5);(30, 5, 5) ";

  //! output

  stringstream output;
  for (auto batch : loader) {
    output << shape2str(batch.getData().shape()) << ";";
    output << shape2str(batch.getLabel().shape()) << " ";
  }
  //! remove data

  //! print result
  return printResult(output.str(), expect, name);
}

bool T_Data::data21() {
  string name = "data21";
  //! data
  int nsamples = 100;
  xt::xarray<double> X = xt::random::randn<double>({nsamples, 1, 2, 3});
  xt::xarray<double> T = xt::random::randn<double>({nsamples, 1, 2, 3});
  TensorDataset<double, double> ds(X, T);
  DataLoader<double, double> loader(&ds, 30, true, false);
  //! expect
  string expect =
      "(30, 1, 2, 3);(30, 1, 2, 3) (30, 1, 2, 3);(30, 1, 2, 3) (40, 1, 2, "
      "3);(40, 1, 2, 3) ";

  //! output

  stringstream output;
  for (auto batch : loader) {
    output << shape2str(batch.getData().shape()) << ";";
    output << shape2str(batch.getLabel().shape()) << " ";
  }
  //! remove data

  //! print result
  return printResult(output.str(), expect, name);
}

bool T_Data::data22() {
  string name = "data22";
  //! data
  int nsamples = 40;
  xt::xarray<double> X = xt::random::randn<double>({nsamples, 1});
  xt::xarray<double> T = xt::random::randn<double>({nsamples, 1});
  TensorDataset<double, double> ds(X, T);
  DataLoader<double, double> loader(&ds, 30, true, true);
  //! expect
  string expect = "(30, 1) (30, 1)";

  //! output

  stringstream output;
  auto batch = loader.begin();
  Batch b = *(batch);
  output << shape2str(b.getData().shape()) << " ";
  output << shape2str(b.getLabel().shape());
  //! remove data

  //! print result
  return printResult(output.str(), expect, name);
}

bool T_Data::data23() {
  string name = "data23";
  //! data
  int nsamples = 40;
  xt::xarray<double> X = xt::random::randn<double>({nsamples, 1});
  xt::xarray<double> T = xt::random::randn<double>({nsamples, 1});
  TensorDataset<double, double> ds(X, T);
  DataLoader<double, double> loader(&ds, 30, true, true);
  //! expect
  string expect = "(30, 1) (30, 1)";

  //! output

  stringstream output;
  auto batch = loader.begin();
  Batch b = *(batch++);
  output << shape2str(b.getData().shape()) << " ";
  output << shape2str(b.getLabel().shape());
  //! remove data

  //! print result
  return printResult(output.str(), expect, name);
}

bool T_Data::data24() {
  string name = "data24";
  //! data
  xt::xarray<float> data = {1., 2., 3.};
  xt::xarray<string> label;
  TensorDataset tensor(data, label);

  //! expect
  string expect = "len=3";

  //! output
  string output = "len=" + to_string(tensor.len());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}

bool T_Data::data25() {
  string name = "data25";
  //! data
  xt::xarray<float> data = {1., 2., 3.};
  xt::xarray<string> label;
  TensorDataset tensor(data, label);

  //! expect
  string expect = "(3,);()";

  //! output
  stringstream output;
  output << shape2str(tensor.get_data_shape()) << ";";
  output << shape2str(tensor.get_label_shape());

  //! remove data

  //! print result
  return printResult(output.str(), expect, name);
}

bool T_Data::data26() {
  string name = "data26";
  //! data
  xt::xarray<float> data = {1., 2., 3.};
  xt::xarray<string> label;
 
  TensorDataset tensor(data, label);
  
  DataLabel<float, string> getitem = tensor.getitem(0);

  xt::xarray<float> getData = getitem.getData();
  xt::xarray<string> getLabel = getitem.getLabel();

  //! expect
  string expect = " 1.;";

  //! output
  stringstream output;
  output << getData << ";";
  output << getLabel;

  //! remove data

  //! print result
  return printResult(output.str(), expect, name);
}

bool T_Data::data27() {
  string name = "data27";
  //! data
  xt::xarray<float> data = {1., 2., 3.};
  xt::xarray<int> label = 1;

  TensorDataset tensor(data, label);
  DataLabel<float, int> getitem = tensor.getitem(2);
  xt::xarray<float> getData = getitem.getData();
  xt::xarray<int> getLabel = getitem.getLabel();

  //! expect
  string expect = " 3.;1";

  //! output
  stringstream output;
  output << getData << ";";
  output << getLabel;

  //! remove data

  //! print result
  return printResult(output.str(), expect, name);
}

bool T_Data::data28() {
  string name = "data28";
  //! data
  xt::xarray<float> data = {1, 2, 3, 4};
  xt::xarray<string> label;
  TensorDataset<double, string> ds(data, label);
  DataLoader<double, string> loader(&ds, 3, true, true);
  //! expect
  string expect = "getData={ 1.,  4.,  2.} ; getLabel= ";

  //! output

  stringstream output;
  output << "getData=";
  for (auto it = loader.begin(); it != loader.end(); ++it) {
    output << (*it).getData() << " ";
  }
  output << "; getLabel=";
 
  for (auto it = loader.begin(); it != loader.end(); ++it) {
    output << (*it).getLabel() << " ";
  }
  //! remove data
  
  //! print result
 
  return printResult(output.str(), expect, name);
}

bool T_Data::data29() {
  string name = "data29";
  //! data
  xt::xarray<float> data = {1, 2, 3, 4};
  xt::xarray<string> label;
  TensorDataset<double, string> ds(data, label);

  DataLoader<double, string> loader(&ds, 2, true, true);
  //! expect
  string expect = "getData={ 1.,  4.} { 2.,  3.} ; getLabel=  ";

  //! output

  stringstream output;
  output << "getData=";
  for (auto it = loader.begin(); it != loader.end(); ++it) {

    output << (*it).getData() << " ";
    
  }
  output << "; getLabel=";

  for (auto it = loader.begin(); it != loader.end(); ++it) {
    output << (*it).getLabel() << " ";
  }
  //! remove data

  //! print result
  return printResult(output.str(), expect, name);
}

bool T_Data::data30() {
  string name = "data30";
  //! data
  xt::xarray<float> data = {1, 2, 3, 4, 5};
  xt::xarray<string>label;
  TensorDataset<float, string> ds(data, label);
  DataLabel<float, string> getitem = ds.getitem(0);
  xt::xarray<float> getData = getitem.getData();
  xt::xarray<string> getLabel = getitem.getLabel();
  DataLoader<float, string> loader(&ds, 2, false, true);
  //! expect
  string expect = "getData={ 1.,  2.} { 3.,  4.} ; getLabel=  \n 1.;";

  //! output

  stringstream output;
  output << "getData=";
  for (auto it = loader.begin(); it != loader.end(); ++it) {
    output << (*it).getData() << " ";
  }
  output << "; getLabel=";
  for (auto it = loader.begin(); it != loader.end(); ++it) {
    output << (*it).getLabel() << " ";
  }
  output << endl;
  output << getData << ";";
  output << getLabel;

  //! remove data

  //! print result
  return printResult(output.str(), expect, name);
}

bool T_Data::data31() {
  string name = "data31";
  //! data
  xt::xarray<float> data = {1, 2, 3, 4,5,5,4};
  xt::xarray<string> label = {"1", "2", "3", "4","5","5","4"};
  TensorDataset<double, string> ds(data, label);
  DataLoader<double, string> loader(&ds, 2, true, true);
  //! expect
  string expect = "getData={ 1.,  3.} { 2.,  5.} { 5.,  4.} ; getLabel={1, 3} {2, 5} {5, 4} ";

  //! output

  stringstream output;
  output << "getData=";
  for (auto it = loader.begin(); it != loader.end(); ++it) {
    output << (*it).getData() << " ";
  }
  output << "; getLabel=";

  for (auto it = loader.begin(); it != loader.end(); ++it) {
    output << (*it).getLabel() << " ";
  }
  //! remove data

  //! print result
  return printResult(output.str(), expect, name);
}

bool T_Data::data32() {
  string name = "data32";
  //! data
  xt::xarray<float> data = {4,2,1,0};
  xt::xarray<string> label = {"d", "c", "a","b"};
  TensorDataset<double, string> ds(data, label);
  DataLoader<double, string> loader(&ds, 2, true, true);
  //! expect
  string expect = "getData={ 4.,  0.} { 2.,  1.} ; getLabel={d, b} {c, a} ";

  //! output

  stringstream output;
  output << "getData=";
  for (auto it = loader.begin(); it != loader.end(); ++it) {
    output << (*it).getData() << " ";
  }
  output << "; getLabel=";

  for (auto it = loader.begin(); it != loader.end(); ++it) {
    output << (*it).getLabel() << " ";
  }
  //! remove data

  //! print result
  return printResult(output.str(), expect, name);
}

bool T_Data::data33() {
  string name = "data33";
  //! data

  //! expect
  string expect = "";

  //! output

  stringstream output;
  output << "getData=";
 xt::xarray<int> X = xt::arange<int>(10*4).reshape({10, 4});
    xt::xarray<int> t;
    //Show X and t
    cout << "############################################" << endl;
    cout << "#CASE: data WITHOUT label" << endl;
    cout << "############################################" << endl;
    cout << "ORIGINAL data and label:" << endl;
    cout << "X.shape: " << shape2str(X.shape()) << endl;
    cout << "X: " << endl << X << endl;
    cout << "t.shape: " << shape2str(t.shape()) << endl;
    cout << "t: " << endl << t << endl;
    cout << "=================================" << endl;

    //Create TensorDataset and DataLoader
    TensorDataset<int, int> ds(X, t);
    int batch_size = 3;
    bool shuffle = false, drop_last = false;
    int seed;
    DataLoader<int, int> *pLoader;

    cout << "Loading (1): with shuffle=false:" << endl;
    cout << "################################" << endl;
    shuffle = false;
    pLoader = new DataLoader<int, int>(&ds, batch_size, shuffle, drop_last, seed);
    int batch_idx = 1;
    for(auto batch: *pLoader){
        cout << "batch_idx:" << batch_idx++ << endl;
        string dshape = shape2str(batch.getData().shape());
        string lshape = shape2str(batch.getLabel().shape());
        cout << "(data.shape, label.shape): " << dshape + ", " + lshape << endl;
        cout << "data:"  << endl << batch.getData() << endl;
        cout << "label:" << endl << batch.getLabel() << endl;
    }
    cout << endl << endl;
    delete pLoader;

    // cout << "Loading (2): with shuffle=true + no seed (seed < 0):" << endl;
    // cout << "when seed < 0: DO NOT call xt::random:seed" << endl;
    // cout << "################################" << endl;
    // shuffle = true;
    // seed = -1;
    // pLoader = new DataLoader<int, int>(&ds, batch_size, shuffle, drop_last, seed);
    // batch_idx = 1;
    // for(auto batch: *pLoader){
    //     cout << "batch_idx:" << batch_idx++ << endl;
    //     string dshape = shape2str(batch.getData().shape());
    //     string lshape = shape2str(batch.getLabel().shape());
    //     cout << "(data.shape, label.shape): " << dshape + ", " + lshape << endl;
    //     cout << "data:"  << endl << batch.getData() << endl;
    //     cout << "label:" << endl << batch.getLabel() << endl;
    // }
    // cout << endl << endl;
    // delete pLoader;

    // cout << "Loading (3): with shuffle=true + no seed (seed < 0):" << endl;
    // cout << "when seed < 0: DO NOT call xt::random:seed" << endl;
    // cout << "################################" << endl;
    // shuffle = true;
    // seed = -1;
    // pLoader = new DataLoader<int, int>(&ds, batch_size, shuffle, drop_last, seed);
    // batch_idx = 1;
    // for(auto batch: *pLoader){
    //     cout << "batch_idx:" << batch_idx++ << endl;
    //     string dshape = shape2str(batch.getData().shape());
    //     string lshape = shape2str(batch.getLabel().shape());
    //     cout << "(data.shape, label.shape): " << dshape + ", " + lshape << endl;
    //     cout << "data:"  << endl << batch.getData() << endl;
    //     cout << "label:" << endl << batch.getLabel() << endl;
    // }
    // cout << endl << endl;
    // delete pLoader;
    cout << "NOTE: Loading (2) and (3): DO NOT CALL seed; so results are different." << endl;
    cout << endl << endl;

    cout << "Loading (4): with shuffle=true + with seed (seed >= 0):" << endl;
    cout << "when seed >= 0: CALL xt::random:seed" << endl;
    cout << "################################" << endl;
    shuffle = true;
    seed = 100;
    pLoader = new DataLoader<int, int>(&ds, batch_size, shuffle, drop_last, seed);
    batch_idx = 1;
    for(auto batch: *pLoader){
        cout << "batch_idx:" << batch_idx++ << endl;
        string dshape = shape2str(batch.getData().shape());
        string lshape = shape2str(batch.getLabel().shape());
        cout << "(data.shape, label.shape): " << dshape + ", " + lshape << endl;
        cout << "data:"  << endl << batch.getData() << endl;
        cout << "label:" << endl << batch.getLabel() << endl;
    }
    delete pLoader;

    cout << "Loading (5): with shuffle=true + with seed (seed >= 0):" << endl;
    cout << "when seed >= 0: CALL xt::random:seed" << endl;
    cout << "################################" << endl;
    shuffle = true;
    seed = 100;
    pLoader = new DataLoader<int, int>(&ds, batch_size, shuffle, drop_last, seed);
    batch_idx = 1;
    for(auto batch: *pLoader){
        cout << "batch_idx:" << batch_idx++ << endl;
        string dshape = shape2str(batch.getData().shape());
        string lshape = shape2str(batch.getLabel().shape());
        cout << "(data.shape, label.shape): " << dshape + ", " + lshape << endl;
        cout << "data:"  << endl << batch.getData() << endl;
        cout << "label:" << endl << batch.getLabel() << endl;
    }
    delete pLoader;
    cout << "NOTE: Loading (4) and (5): CALL xt::random::seed and use SAME seed => same results." << endl;
    cout << endl << endl;
    

  //! remove data

  //! print result
  return printResult(output.str(), expect, name);
}

bool T_Data::data34() {
  string name = "data34";
  //! data
  xt::xarray<int> X = xt::arange<int>(10*4).reshape({10, 4});
  xt::xarray<int> t;
  TensorDataset<int, int> ds(X, t);
  int batch_size = 3;
  bool shuffle = false, drop_last = false;
  int seed,batch_idx;
  DataLoader<int, int> *pLoader;
  //! expect
  string expect = "";

  //! output

  stringstream output;
  output << "getData=";
  shuffle = true;
  seed = 100;
  pLoader = new DataLoader<int, int>(&ds, batch_size, shuffle, drop_last, seed);
  batch_idx = 1;
  for(auto batch: *pLoader){
    cout << "batch_idx:" << batch_idx++ << endl;
    string dshape = shape2str(batch.getData().shape());
    string lshape = shape2str(batch.getLabel().shape());
    cout << "(data.shape, label.shape): " << dshape + ", " + lshape << endl;
    cout << "data:"  << endl << batch.getData() << endl;
    cout << "label:" << endl << batch.getLabel() << endl;
}

  //! remove data
  delete pLoader;
  //! print result
  return printResult(output.str(), expect, name);
}