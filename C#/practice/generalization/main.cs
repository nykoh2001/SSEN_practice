
#if false
// object 기반의 일반화 프로그래밍
object[] objs = { 1, "aaa", new Person("name", 12), 3.14 };

foreach(object obj in objs)
{
  Console.WriteLine(obj.GetType().Name + ":" + obj);
}


Person p1 = new("aaa", 12);
Person p2 = new("aaa", 12);
Person p3 = p1;

Console.WriteLine(p1 == p2);
Console.WriteLine(p1.Equals(p2));
Console.WriteLine(p1 == p3);
Console.WriteLine(p1.Equals(p3));

// 참조값 출력
Console.WriteLine(p1.GetHashCode());
Console.WriteLine(p2.GetHashCode());
Console.WriteLine(p3.GetHashCode());

#endif