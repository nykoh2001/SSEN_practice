using C_;

#if false

// 최상위 문, main 함수(entrypoint) 내용

Class1 c1 = new Class1{ // default constructor 호출 -> 값 대입
  name = "asdf",
  age = 2
}; // new: 모든 객체는 힙에 생성, c1: 참조 변수 (포인터, 저장하는 값은 난수 -> 주소로 맵핑됨)

// c1.name = "asdf";
// c1.age = 2;

Console.WriteLine(c1.name + ", " + c1.age);

Person p1 = new Person(3, "bello", 95);
Person p2 = p1;

// p1.print();

// NOTE: Python처럼 Object라는 최상위 클래스 -> 최상위 클래스의 멤버를 모두 상속 받음
Console.WriteLine(p1 + " / " + p1.GetHashCode());
Console.WriteLine(p2 + " / " + p2.GetHashCode());

Person2[] people = new Person2[3];
people[0] = new Person2("Hello", "010-2345-1345");
people[1] = new Person2("Bello", "010-9999-9999");
people[2] = new Person2();

for (int i = 0; i < 3; i++)
{
  people[i].print();
}

#endif

Action action = new Action(new MyInterfaceImpl());
action.call();