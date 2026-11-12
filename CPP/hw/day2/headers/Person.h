#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
  int number;
  string name;

public:
  Person(int number, string name);
  void printInfo();
}