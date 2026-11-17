object[] objs = { 1, "aaa", new Person("name", 12), 3.14 };

foreach(object obj in objs)
{
  Console.WriteLine(obj.GetType().Name + ":" + obj);
}