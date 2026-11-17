
class Person // Obejct class 기본 상속
{
  // private string name;
  // private int age;

  public string Name { set; get; }
  public int Age { set; get; }

  public Person(string name, int age)
  {
    Name = name;
    Age = age;
  }

  public override string ToString()
  {
    return "Name: " + Name + " / Age: " + Age;
  }

  // ?: Nullable reference, prevent NPE
#pragma warning disable CS8632 // The annotation for nullable reference types should only be used in code within a '#nullable' annotations context.
  public override bool Equals(object? obj)
  {
    if (obj is Person p)
      return p.Name == Name && p.Age == Age;
    return false;
  }

  // TODO: 왜 이런 작업이 필요한지 추가 조사
  public override int GetHashCode()
  {
    return Name.GetHashCode() + Age.GetHashCode();
  }
}