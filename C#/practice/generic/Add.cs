using System.Numerics;


public class Box<T>
{ // T는 타입 매개변수
  private T _data;
  public void Set(T data) => _data = data;
  public T Get() => _data;
}


public class Add<T> where T : INumber<T>
{
  private T data1, data2;

  public Add(T data1, T data2)
  {
    this.data1 = data1;
    this.data2 = data2;
  }

  public T add()
  {
    return data1 + data2;
  }

  public override string ToString()
  {
    return data1 + " + " + data2 + " = " + add();
  }
}
