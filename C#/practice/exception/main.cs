MyData data = new();

try
{
  data[0] = "aaa";
  data[1] = "bbb";
  data[2] = "ccc";
  data[3] = "xxx";
}
catch (IndexOutOfRangeException e)
{
  Console.WriteLine(e.Message);
}

try
{
  for (int i = 0; i <= data.cnt; i++)
  {
    Console.WriteLine(data[i]);
  }
}
catch (IndexOutOfRangeException e)
{
  Console.WriteLine(e.Message);
}

Console.WriteLine("Program exit succesfully");