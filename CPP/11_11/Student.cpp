
#if 1

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Score {
  string subject;
  int score = 0;

public:
  Score(string subject, int score): subject(subject), score(score) {}
  ~Score() {}

  string toString() { return subject + ": " + score + "\n"; }
  int getScore() { return score; }
}

class Student {
  int number;
  string name;
  Score* score[3];
  int total = 0;

public:
  Student(int number, string name) : number(number), name(name) {
    score[0] = new Student("KOR", 85);
    score[1] = new Student("ENG", 89);
    score[2] = new Student("MATH", 92);

    updateScore();
  }

  ~Student() {
    for (int i = 0; i < sizeof(score) / sizeof(score[0]); i++) {
      delete score[i];
    }
  }


  void updateScore() {
    total = 0;
    for (int i = 0; i < sizeof(score) / sizeof(score[0]); i++) {
      total += score[i].getScore();
    }
  }

  void printStudent() {
    cout << "Student: " << num << " - " << name << endl;
    cout << score.toString() << endl;
    cout << "Total: " << total << endl;
  }
}

#endif