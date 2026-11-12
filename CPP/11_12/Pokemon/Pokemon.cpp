#include "Pokemon.h"

Pokemon::Pokemon(string name, int level, int hp, double exp): name(name), level(level), hp(hp), exp(exp) { }
void Pokemon::eat() { hp += 10; }
void Pokemon::sleep() { hp += 30; }
void Pokemon::workout() { 
    hp -= 10;
    exp += 20;
    if(hp <= 0) cout << name << "is Died\n";
    else if(exp > 100) {
        level++;
        cout << name << " level up~!\n";
        exp = 0;
    }
}
void Pokemon::play() { 
    hp -= 5;
    exp += 10;
    if(hp <= 0) cout << name << "is Died\n";
    else if(exp > 100) {
        level++;
        cout << name << " level up~!\n";
        exp = 0;
    }
}
void Pokemon::checkState() {
    cout << name << "'s state:\n";
    cout << "hp: " << hp << endl;
    cout << "level:" << level << endl;
    cout << "exp: " << exp << endl;
}
void Pokemon::checkLevel() { cout << name << "'s level: " << level << endl; }
// void Poketmon::attack() { cout << "attac" << endl; }

/* override 키워드는 클래스 선언부에만 */
void Pikachu::attack() { cout << "Electric attack" << endl; }
void Squirtle::attack() { cout << "Water bomb" << endl; }
void Bulbasaur::attack() { cout << "Ivysaur" << endl; }