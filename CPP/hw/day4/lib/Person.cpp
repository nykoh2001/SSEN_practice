#include "../headers/Person.h"
#include <algorithm>


string Person::toString() const{
	return to_string(num) + " / " + name + " / " + tel;
}

void Person::setTel(string tel) {
	this->tel = tel;
}
int Person::getNum() {
	return num;
}
bool Person::operator==(const Person& other) const {
	return num == other.num;
}

/// PersonService 멤버 함수 구현 //////
void PersonService::add() {
	int num;
	auto it = arr.end();
	string name, tel;
	cout << "=== add ===" << endl;
	
	do{
		cout << "num:";
		cin >> num;
		it = find(arr.begin(), arr.end(), Person(num, "", ""));
	} while (it != arr.end());

	cout << "name:";
	cin >> name;
	cout << "tel:";
	cin >> tel;
	arr.push_back(Person(num, name, tel));
}

void PersonService::get() {
	int num;
	cout << "=== search ===" << endl;
	cout << "search num:";
	cin >> num;
	auto it = find(arr.begin(), arr.end(), Person(num, "", ""));
	if (it == arr.end()) {
		cout << "not found" << endl;
		return;
	}
	cout << (*it).toString() << endl;
}

void PersonService::edit() {
	int num;
	string tel;
	cout << "=== edit ===" << endl;
	cout << "edit num:";
	cin >> num;
	auto it = find(arr.begin(), arr.end(), Person(num, "", ""));
	if (it == arr.end()) {
		cout << "not found" << endl;
		return;
	}
	cout << "before edit" << endl;
	cout << it->toString() << endl;
	cout << "new tel:";
	cin >> tel;
	it->setTel(tel);
}
void PersonService::del() {
	int num;
	cout << "=== del ===" << endl;
	cout << "del num:";
	cin >> num;
	auto it = find(arr.begin(), arr.end(), Person(num, "", ""));
	if (it == arr.end()) {
		cout << "not found" << endl;
		return;
	}
	cout << "del item" << endl;
	cout << it->toString() << endl;
	arr.erase(it);//요소삭제
}
void PersonService::printAll() {
	cout << "=== printAll ===" << endl;
	for (auto p:arr) {
		cout << p.toString() << endl;
	}
}