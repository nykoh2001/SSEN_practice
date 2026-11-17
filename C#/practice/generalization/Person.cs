
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
}