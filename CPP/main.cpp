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


int main(void) {
  Point p1;
  Point* p2 = new Point(3, 4);

  Point *arr[] = {new Point(1, 2), new Point(3, 4)};
  for (int i = 0; i < 2; i++) {
    arr[i]->printXY();
  }
  return 0;
}


#endif