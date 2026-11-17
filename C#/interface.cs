using C_;

interface MyInterface
{
  void f1();
  void f2();
}

class MyInterfaceImpl : MyInterface
{
  public void f1()
  {
    Console.WriteLine("MyInterfaceImpl: f1");
  }

  public void f2()
  {
    Console.WriteLine("MyInterfaceImpl: f2");
  }
}

class Action
{
  private MyInterface mi;

  // 상위 클래스에 의존
  public Action(MyInterface mi)
  {
    this.mi = mi;
  }

  public void call()
  {
    this.mi.f1();
    this.mi.f2();
  }
}