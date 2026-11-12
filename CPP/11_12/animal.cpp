#include <iostream>

using namespace std;

// 순수 가상함수를 갖는 클래스 -> 추상 클래스 (abstract class)
// 모든 멤버가 순수 가상 함수인 추상 클래스 -> interface
// 해당 클래스를 상속 받는 하위 클래스들이 순수 가상 함수를 하나라도 구현하지 않으면 에러 => 무조건 오버라이딩 하도록 프로그래밍에 제약을 걸음
class Animal {
public:
  virtual void speak() = 0;
}

class Dog : public Animal {
public:
  void speak() override {
    cout << "Bark bark" << endl;
  }
}

class Cat : public Animal {
public:
  void speak() override {
    cout << "Meow meow" << endl;
  }
}

int main() {
  Animal *animals[] = {new Dog(), new Cat()};
  for (int i = 0; i < sizeof(animals) / sizeof(animals[0]); i++)
    animals[i]->speak();

  for (int i = 0; i < sizeof(animals) / sizeof(animals[0]); i++)
    delete animals[i];

  return 0;
}