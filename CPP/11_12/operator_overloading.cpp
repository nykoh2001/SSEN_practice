#include <iostream>

using namespace std;

class Point {
private:
  int x, y;

public:
  Point() : x(0), y(0) {}
  Point(int x, int y) : x(x), y(y) {}
  void print() { cout << "(" << x << ", " << y << ")" << endl; }

  // TODO: 멤버 함수와 전역 오버로딩의 호출 시 차이점 있는지 확인
  // 현대 컴파일러는 RVO(Return Value Optimization) -> 불필요한 복사를 최소화하고 호출자 쪽에 객체 생성
  Point operator+(const Point &p) const {
    return Point(this->x + p.x, this->y + p.y);
  }

  // friend 선언 -> 전역 operator +에서 private 멤버에 접근 가능하도록
  friend Point operator+(const Point &p1, const Point &p2); 
};

Point operator+(const Point &p1, const Point &p2) const {
  return Point(p1.x + p2.x, p1.y + p2.y);
}

int main() {


  return 0;
}