interface DB
{
  void select();
  void insert();
  void update();
  void delete();
}

class MySQL : DB
{
  public void delete()
  {
    Console.WriteLine("MySQL delete");
  }

  public void insert()
  {
    Console.WriteLine("MySQL insert");
  }

  public void select()
  {
    Console.WriteLine("MySQL select");
  }

  public void update()
  {
    Console.WriteLine("MySQL update");
  }
}

class Oracle : DB
{
  public void delete()
  {
    Console.WriteLine("Oracle delete");
  }

  public void insert()
  {
    Console.WriteLine("Oracle insert");
  }

  public void select()
  {
    Console.WriteLine("Oracle select");
  }

  public void update()
  {
    Console.WriteLine("Oracle update");
  }
}