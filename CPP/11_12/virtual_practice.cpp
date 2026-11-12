#if 0

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Car {
public:
  virtual void horn() {
    cout << "honk honk" << endl;
  }
};

class PoliceCar : public Car {
public:
  void horn() override {
    cout << "wee-woo" << endl;
  }
};

class Ambulance : public Car {
public:
  void horn() override {
    cout << "high-low" << endl;
  }
};

int main() {
  Car *cars[] = {new Car(), new PoliceCar(), new Ambulance()};

  for (int i = 0; i < sizeof(cars) / sizeof(cars[0]); i++)
    cars[i]->horn();

  for (int i = 0; i < sizeof(cars) / sizeof(cars[0]); i++)
    delete cars[i];

  return 0;
}

#endif