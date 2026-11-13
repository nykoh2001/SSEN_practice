namespace C_;

class Person
{
  public int num;
  public string name;
  public int score;

  // NOTE: C#에는 포인터가 없음, this 자체에 직접 접근
  public Person(int num, string name, int score)
  {
    this.num = num;
    this.name = name;
    this.score = score;
  }

  public void print()
  {
    Console.WriteLine("Num: " + this.num);
    Console.WriteLine("Name: " + this.name);
    Console.WriteLine("Score: " + this.score);
  }
}