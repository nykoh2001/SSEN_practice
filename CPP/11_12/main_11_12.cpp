#if 0

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Parent {
protected:
  int x, y;

public:
  Parent(int x, int y) : x(x), y(y) {}
  virtual void print() { cout << x << ", " << y; }
  /*
  * NOTE: virtual 멤버를 갖는 부모 객체 포인터 타입으로 new를 통한 자식 객체 생성 시에, 소멸자를 반드시 virtual로 선언해야 함
  * 소멸자를 virtual로 해야, 호출 시에 부모 클래스의 소멸자만 호출되지 않고 자식 소멸자 호출 후 부모 소멸자 호출
  * (현재 경우에는 해당 안됨, new를 통한 생성이 이루어지지 않음)
  */
  ~Parent() {
    cout << "Parent destructor" << endl;
  }
};

class Child : public Parent {
private:
  int z;

public:
  /*
  * Parent에 커스텀한 생성자를 정의했기 때문에, 자식 생성자에서 부모 생성자를 명시적으로 호출하지 않으면 에러 (부모의 디폴트 생성자가 컴파일러에 의해 주입되지않기 때문)
  * 1. 디폴트 생성자를 넣어주거나, 2. 자식 생성자에서 부모 생성자 명시적으로 호출
  */
  // Issue) Child(int x, int y, int z): x(x), y(y), z(z) {}
  Child(int x, int y, int z) : Parent(x, y), z(z) {}

  ~Child() {cout << "Child Destructor" << endl;}

  // Override
  void print() override {
    Parent::print();
    cout << ", " << z << endl;
  }
};

int main() {
  Child c(1, 2, 3);
  c.print();

  Parent *cp = &c;
  cp->print();
}

#endif