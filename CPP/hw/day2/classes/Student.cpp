#include "../headers/Person.h"
#include "../headers/Lecture.h"

#include <vector>

class Student : Person {
  string department;;
  vector<Lecture> lectures;

public:
  Student(int number, string name, string department)
      : Person(number, name), department(department) {
    int lectureCnt;
    string lecturName;

    cout << "Enter how many lectures are registered: ";
    cin >> lectureCnt;
    
    for (int i = 0; i < lectureCnt; i++) {
      cout << "Enter lecture name: ";
      cin >> lecturName;
      lectures.push_back(Lecture(name));
    }
  }

  void printInfo() {
    Person::printInfo();
    cout << "Department: " << department << endl;
    printLectureList();
  }

  void registerLecture() {
    string lecture;
    cout << "Lecture to register: ";
    cin >> lecture;
    lectures.push_back(Lecture(name));
  }

  void cancelLecture() {
    int removeIdx;
    cout << "Idx of item to remove: ";
    cin >> removeIdx;
    lectures.erase(removeIdx);
  }

  void printLectureList() {
    for (Lecture l: lectures)
      cout << "Lecture: " << l.getName() << endl;
  }
}