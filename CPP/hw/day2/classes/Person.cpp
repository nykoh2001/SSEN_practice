#include "Person.h"

class Person {
protected:
  int number;
  string name;

public:
  Person(int number, string name): number(number), name(name) {}
  void printInfo() {
    cout << "Number: " << number << endl;
    cout << "Name: " << name << endl;
  }
}