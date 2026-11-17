using C_;
using System;
using System.Collections.Generic;
using System.Diagnostics.Tracing;
using System.Text;

class Person3
{
  private static int cnt;
  public int Num { set; get; } //중복안됨. 자동할당. 

  public string Name { set; get; }

  public string Tel { set; get; }

  public Person3() { }

  public Person3(string name, string tel)
  {
    Num = cnt++;
    Name = name;
    Tel = tel;
  }

  public override string ToString()
  {
    return Num + " / " + Name + " / " + Tel;
  }

  public override bool Equals(object? obj)
  {
    if (obj is Person3 p)
    {
      return this.Num == p.Num;
    }
    return false;
  }

  public override int GetHashCode()
  {
    return this.Num.GetHashCode();
  }
}

class AddressBook
{
  private List<Person3> list = new();

  public void add(Person3 p)
  {
    list.Add(p);
  }

  public int getIdxByNum(int num)
  {
    Person3 temp = new Person3();
    temp.Num = num;
    // NOTE: Equals를 오버라이드 해서 num이 같으면 같은 객체로 판단하는 것으로 정의 => Num 값만 설정해서 IndexOf 사용 가능
    int idx = list.IndexOf(temp);
    if (idx < 0)
      Console.WriteLine("No such object with number " + num);
    return idx;
  }

  public Person3? getByNum(int num)
  {
    int idx = getIdxByNum(num);
    if (idx < 0) return null;
    return list.ElementAt(idx);
  }

  public bool deleteByNum(int num)
  {
    int idx = getIdxByNum(num);
    if (idx < 0) return false;

    list.RemoveAt(idx);
    return true;
  }

  public bool edit(int num)
  {
    int idx = getIdxByNum(num);
    if (idx < 0) return false;

    Console.Write("New Tel: ");
    string newTel = Console.ReadLine();
    Person3 p = list.ElementAt(idx);
    p.Tel = newTel;

    return true;
  }

  public void printAll()
  {
    foreach (var p in list)
    {
      Console.WriteLine(p + " ");
    }
    Console.WriteLine();
  }
}


class Service
{
  private AddressBook ab = new();

  public void addPerson()
  {
    Console.WriteLine("=== 추가 ===");
    Console.Write("Name: ");
    string name = Console.ReadLine();
    Console.Write("Tel: ");
    string tel = Console.ReadLine();
    Person3 p = new(name, tel);
    ab.add(p);
  }

  public Person3? getPerson()
  {
    Console.WriteLine("=== 조회===");
    Console.Write("Num: ");
    int num = Convert.ToInt32(Console.ReadLine());
    return ab.getByNum(num);
  }

  public bool updatePerson()
  {
    Console.WriteLine("=== 전화번호 업데이트 ===");
    Console.Write("Num: ");
    int num = Convert.ToInt32(Console.ReadLine());
    return ab.edit(num);
  }

  public bool deletePerson()
  {
    Console.WriteLine("=== 삭제 ===");
    Console.Write("Num: ");
    int num = Convert.ToInt32(Console.ReadLine());
    return ab.deleteByNum(num);
  }

  public void printPersons()
  {
    Console.WriteLine("===전체 목록===");
    ab.printAll();
  }
}