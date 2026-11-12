#if 1

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Point {
  int x, y;
  chat* name;

public:
  Point() {
    cout << "Default Constructor" << endl;
    name = new char[5];
    strcpy(name, "naynay");
  }
  Point(int x, int y) : x(x), y(y) {
    cout << "Initialization Constructor" << endl;
  }
  // NOTE: Point 클래스 안으로 전달된 다른 클래스 객체에 대해서는, private이어도 접근이 가능한 권한을 가짐
  Point(const Point &p) : x(p.x), y(p.y) {
    int len = strlen(p.name) + 1;
    name = new char[len];
    strcpy(name, p.name);
  }

  void printXY() { cout << "(" << x << ", " << y << ")" << endl; }

  ~Point() {delete[] name;}
  
  void setX(int x) { this->x = x; }
  void setY(int y) { this->y = y; }
  int getX() const { return x; }
  int getY() const { return y; }

}

// 객체를 함수의 반환값으로 전달
class Person {
public:
    int num;
    string name;
    Person() {}
    Person(int num, string name) :num(num), name(name) {}

    //현재 객체 반환. 
    Person getThis1() {
        return *this;  //this: 현재 객체의 주소. *this는 현재 객체의미
        //반환 타입을 Person으로 하면 현재 객체를 복사해서 전달
    }

    Person& getThis2() {
        return *this;
        //반환 타입을 Person&으로 하면 현재 객체를 복사하지 밖에서 부를 이름만 하나 더 추가
    }

    Person* getThis3() {
        return this;  //현재 객체의 주소 반환. 함수 반환 타입은 Person*(포인터)
    }
};

// 객체를 함수의 파라미터로 전달
class TestPerson {
public:
    //call by value. 객체를 복사해서 전달. 제일 나쁨.
    void printPerson(Person p) {
        cout << "num:" << p.num << ", name:" << p.name << endl;
    }

    //call by value. 객체의 주소값을 복사해서 전달. 중간
    void printPerson(Person* p) {
        cout << "num:" << p->num << ", name:" << p->name << endl;
    }

    //call by reference. 파라메터 타입이 참조형 이어야 함. 제일 좋음
    void printPerson(Person& p) {
        cout << "num:" << p.num << ", name:" << p.name << endl;
    }
};


class Test {
    int num;

  public:
    Test(int num) : num(num) {}

    friend void f1(Test &t);
    friend class TestFriend1;
    friend void TestFriend2::func1(Test& t);
}

class TestFriend1 {
  public:
    void func1(Test &t) {
        cout << "TestFriend1::func1 : " << t.num << endl;
    }
    void func2(Test& t) {
        cout << "TestFriend1::func2 : " << t.num << endl;
    }
}

class TestFriend2 {
  public:
    void func1(Test &t) {
        cout << "TestFriend2::func1 : " << t.num << endl;
    }
    void func2(Test& t) {
        cout << "TestFriend2::func2 : " << t.num << endl;
    }
}

void f1(Test &t) {
  cout << "f1 : " << t.num << endl;
}

/* Static */
class StaticTest {
public:
  int x = 0; // 생성자보다 먼저 수행
  static int y; // static: 클래스에 종속, this 포인터 사용불가

  StaticTest(int x) : x(x);
  void printXY() {
        cout << "x: " << x << ", y: " << y << endl;
  }
}

int StaticTest::y = 0; // class 밖에서 한 번 초기화

// num, name, price
// 번호 자동 할당: 생성자 안에서 값 할당
class Product {
  static int id;
  int num;
  string name;
  int price;

public:
  Product(string name, int price) : name(name), price(price) {
        num = ++id;
  }
  void printInfo() {
        cout << "Number: " << num << endl;
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl << endl;
  }
};

/*
NOTE: static 변수를 외부에서 초기화하는 이유 -> static은 한 번만 초기화 되기
때문에, 클래스 선언과 동시에 초기화하는 경우 컴파일 과정에서 여러 파일에 헤더가
포함되면서 여러 번 초기화 가능 (불필요)
예외적으로 const static은 컴파일러가 최적화 과정에서 별도로 메모리를 부여하지 않고 상수로 처리, 클래스 내부에서도 초기화 가능
*/
int Product::id = 0;

int main(void) {
  // Point p1;
  // Point* p2 = new Point(3, 4);

  // Point *arr[] = {new Point(1, 2), new Point(3, 4)};
  // for (int i = 0; i < 2; i++) {
  //   arr[i]->printXY();
  // }

  Product* p[3] = {new Product("hello", 15000), new Product("bello", 325100), new Product("kello", 15300)};
  for (int i = 0; i < sizeof(p) / sizeof(p[0]); i++) {
        p[i]->printInfo();
        delete p[i];
  }

  return 0;
}


#endif