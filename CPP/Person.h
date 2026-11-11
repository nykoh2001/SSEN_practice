#pragma once
#include <string>
#include <iostream>
using namespace std;

//vo: value object. 캡슐화. 객체의 값 저장 용도
class Person {
private:
	int num;
	string name;
	string tel;
public:
	Person() :num(0), name(""), tel("") {}
	Person(int num, string name, string tel) :num(num), name(name), tel(tel) {}
	string toString() const;
	void setTel(string tel);
	int getNum();
};

//Person객체를 배열로 저장, 삭제, 검색
class PersonArr {  //dao. 배열에 추가, 검색, 수정, 삭제
private:
	Person* arr[10];  //Person 주소 갖음. 소멸자에서 Person*를 해제
	int cnt;   //요소 개수
public:
	//생성자
	PersonArr() :cnt(0), arr({ NULL, }) {}

	//소멸자. arr 방에 저장된 주소 각각 해제
	~PersonArr();

	//배열에 Person 주소를 끝에 추가
	bool addPerson(Person* p);

	//arr 인덱스로 Person주소를 반환
	Person* getPerson(int idx);

	//번호로 검색을 해서 방번호 반환
	int getPersonIdx(int num);

	//요소 개수 반환
	int getCnt();

	//삭제할 방번호를 파람으로 받아서 해당 방의 Person객체 메모리 해제, 방을 한칸씩 앞으로 이동
	void delPerson(int idx);
};

//
class PersonService {
private:
	PersonArr arr;  //포함관계. has a 관계 
public:
	void add();//외부에 사람정보 1개 추가 기능
	void get(); // 번호로 검색 기능
	void edit(); //번호로 검색해서 전화번호 수정 기능
	void del(); // 번호로 검색해서 삭제 기능
	void printAll(); //배열에 모든 요소 출력 기능
};
