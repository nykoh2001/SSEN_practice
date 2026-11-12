#pragma once

#include <iostream>
#include <string>
using namespace std;

class Pokemon {
private:
    string name;
    int level;
    int hp;
    int exp;
public:
    Pokemon(string name, int level, int hp, double exp);
    virtual ~Pokemon() { } // NOTE: new를 통해 객체를 생성하기 때문에 부모 클래스 소멸자를 virtual로 정의해야 함
    bool isDead() { return hp <= 0; }
    void eat();
    void sleep();
    void workout();
    void play();
    void checkState();
    void checkLevel();
    virtual void attack() = 0; // NOTE: 부모 클래스에서의 구현이 필요 없는 순수 가상 함수
};

/* NOTE: 부모 클래스 메소드를 오버라이드하려면 재정의/선언 필요 */
class Pikachu : public Pokemon {
public:
  Pikachu() : Pokemon("Pikachu", 1, 100, 0){};
  void attack() override;
};

class Squirtle : public Pokemon {
public:
  Squirtle() : Pokemon("Squirtle", 1, 100, 0){};
  void attack() override;
};

class Bulbasaur : public Pokemon {
public:
  Bulbasaur() : Pokemon("Bulbasaur", 1, 100, 0){};
  void attack() override;
};
