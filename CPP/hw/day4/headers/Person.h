#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Person {
private:
	int num;
	string name;
	string tel;
public:
	Person():num(0), name(""), tel("") {}
	Person(int num, string name, string tel) :num(num), name(name), tel(tel) {}
	string toString() const;
	void setTel(string tel);
	int getNum();
	bool operator==(const Person& other) const;
};

class PersonService {
private:
	vector<Person> arr;
public:
	void add();
	void get();
	void edit();
	void del();
	void printAll();
};