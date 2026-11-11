#include "Person.h"
/// Person 멤버 함수 구현 //////
string Person::toString() const {
	//to_string(숫자) : 숫자를 문자열로 변환
	return to_string(num) + " / " + name + " / " + tel;
}

void Person::setTel(string tel) {
	this->tel = tel;
}
int Person::getNum() {
	return num;
}

/// PersonArr 멤버 함수 구현 //////


//소멸자. arr 방에 저장된 주소 각각 해제
PersonArr::~PersonArr() {
	for (int i = 0; i < cnt; i++) {
		delete arr[i];
	}
	delete[] arr;
};

//배열에 Person 주소를 끝에 추가
bool PersonArr::addPerson(Person* p) {
	if (cnt < 10) {
		arr[cnt++] = p;
		return true;
	}
	return false;

}

//arr 인덱스로 Person주소를 반환
Person* PersonArr::getPerson(int idx) {
	return arr[idx];
}

//번호로 검색을 해서 방번호 반환
int PersonArr::getPersonIdx(int num) {
	for (int i = 0; i < cnt; i++) {
		if (arr[i]->getNum() == num) return i;
	}
	return -1;
}

//요소 개수 반환
int PersonArr::getCnt() {
	return cnt;
}

//삭제할 방번호를 파람으로 받아서 해당 방의 Person객체 메모리 해제, 방을 한칸씩 앞으로 이동
void PersonArr::delPerson(int idx) {
	delete arr[idx];
	for (int i = idx + 1; i < cnt; i++) {
		arr[i - 1] = arr[i];
	}
	cnt--;
}

/// PersonService 멤버 함수 구현 //////
void PersonService::add() {
	int num, idx = 0;
	string name, tel;
	cout << "=== add ===" << endl;

	while (idx >= 0) {
		cout << "num:";
		cin >> num;
		idx = arr.getPersonIdx(num);
	}
	cout << "name:";
	cin >> name;
	cout << "tel:";
	cin >> tel;
	arr.addPerson(new Person(num, name, tel));
}

// 번호로 검색 기능
void PersonService::get() {
	cout << "=== get by num ===" << endl;
	int num;
	cout << "num:";
	cin >> num;

	int cnt = arr.getCnt();
	int personIdx = arr.getPersonIdx(num);
	if (personIdx < 0) {
		cout << "No such person (num: " << num << ")" << endl;
		return;
	}
	Person* p = arr.getPerson(personIdx);
	cout << p->toString() << endl;
}

//번호로 검색해서 전화번호 수정 기능
void PersonService::edit() {
	cout << "=== edit tel ===" << endl;
	string tel;
	int num;
	cout << "num:";
	cin >> num;

	int personIdx = arr.getPersonIdx(num);
	if (personIdx < 0) {
		cout << "No such person (num: " << num << ")" << endl;
		return;
	}
	Person* p = arr.getPerson(personIdx);

	cout << "tel:";
	cin >> tel;
	p->setTel(tel);
}

// 번호로 검색해서 삭제 기능
void PersonService::del() {
	cout << "=== del ===" << endl;
	int num;
	cout << "num:";
	cin >> num;
	int personIdx = arr.getPersonIdx(num);
	if (personIdx < 0) {
		cout << "No such person (num: " << num << ")" << endl;
		return;
	};
	arr.delPerson(personIdx);
}

//배열에 모든 요소 출력 기능
void PersonService::printAll() {
	cout << "=== print all ===" << endl;
	for (int i = 0; i < arr.getCnt(); i++) {
		cout << arr.getPerson(i)->toString() << endl;
	}
}
