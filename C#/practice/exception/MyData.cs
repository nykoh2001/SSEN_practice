// class InvalidIdxException : Exception
// {
//   public InvalidIdxException(string msg) : base(msg) { }
// }

class MyData
{
  private string[] data = new string[3];
  public readonly int cnt; // immutable, 선언 시점 or 생성자 안에서만 값 할당

  public MyData()
  {
    cnt = data.Length;
  }

  // 인덱서
  public string this[int idx]
  {
    set
    {
      if (idx < 0 || idx >= data.Length) throw new IndexOutOfRangeException("Invalid idx range");
      data[idx] = value;
    }

    get
    {
      if (idx < 0 || idx >= data.Length) throw new IndexOutOfRangeException("Invalid idx range");
      return data[idx];
    }
  }
}