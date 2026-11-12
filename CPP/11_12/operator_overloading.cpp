#include <iostream>

using namespace std;

class Point {
private:
  int x, y;

public:
  Point() : x(0), y(0) {}
  Point(int x, int y) : x(x), y(y) {}
  void print() { cout << "(" << x << ", " << y << ")" << endl; }

  // TODO: 멤버 함수와 전역 오버로딩의 호출 시 차이점 있는지 확인 (없음)
  // 현대 컴파일러는 RVO(Return Value Optimization) -> 불필요한 복사를 최소화하고 호출자 쪽에 객체 생성
  Point operator+(const Point &p) const {
    return Point(this->x + p.x, this->y + p.y);
  }

  // 전위: 증가한 객체 자신을 반환
  Point& operator++() {
    ++x;
    ++y;
    return *this;
  }

  // 후위: 이전 값을 보관한 뒤 증가, int는 오버로딩으로 전위와 구분하기 위한 dummy param으로 int를 포함하는 증감연산자가 후위 연산자인 것은 C++ 컴파일러에서의 약속
  Point operator++(int) {
    Point old = *this;
    ++(*this);
    return old;
  }

  // friend 선언 -> 전역 operator +에서 private 멤버에 접근 가능하도록
  // friend Point operator+(const Point &p1, const Point &p2); 
};

/* 전역 연산자 오버로딩 */
// Point operator+(const Point &p1, const Point &p2) {
//   return Point(p1.x + p2.x, p1.y + p2.y);
// }

int main() {


  return 0;
}