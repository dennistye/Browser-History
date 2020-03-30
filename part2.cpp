#include <iostream>
#include <string>
#include "CovidData.h"

using std::cout;
using std::endl;
using std::string;

template <typename T>
bool testAnswer(const string &nameOfTest, const T &received, const T &expected);

int main() {
  {
  CovidData cd;
  cout << "Reading exampledata.txt ..." << endl;
  testAnswer("file reading 1", cd.readData("exampledata.txt"), 16);
  testAnswer("getDays(Afghanistan)", cd.getDays("Afghanistan"), 16);
  testAnswer("getDays(Algeria)", cd.getDays("Algeria"), 15);
  testAnswer("getDays(China)", cd.getDays("China"), -1);
  }
  {
  CovidData cd;
  cout << "Reading confirmedcases.txt ..." << endl;
  testAnswer("file reading 2", cd.readData("confirmedcases.txt"), 3320);
  testAnswer("getDays(Afghanistan)", cd.getDays("Afghanistan"), 25);
  testAnswer("getDays(Algeria)", cd.getDays("Algeria"), 24);
  testAnswer("getDays(China)", cd.getDays("China"), 58);
  }
}

template <typename T>
bool testAnswer(const string &nameOfTest, const T &received, const T &expected) {
    if (received == expected) {
        cout << "\033[32m" << "PASSED "
        << "\033[0m" << nameOfTest << ": expected and received " << received << endl;
        return true;
    }
    cout << "FAILED " << nameOfTest << ": expected " << expected << " but received " << received << endl;
    return false;
}
