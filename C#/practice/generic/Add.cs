using System.Numerics;


public class Box<T>
{ // T는 타입 매개변수
  private T _data;
  public void Set(T data) => _data = data;
  public T Get() => _data;
}


public class Add<T> where T : INumber<T>
{
  public T Data1 { set; get; }
  public T Data2 { set; get; }

  public Add(T data1, T data2)
  {
    Data1 = data1;
    Data2 = data2;
  }

  public T add()
  {
    return Data1 + Data2;
  }

  public override string ToString()
  {
    return Data1 + " + " + Data2 + " = " + add();
  }
}
