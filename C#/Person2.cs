class Person2
{
  private string name;
  private string tel;

  public Person2(string name, string tel) { this.name = name; this.tel = tel; }
  public Person2() { name = "Jane Doe"; tel = "010-0000-0000"; }

  public void print()
  {
    Console.WriteLine("Name: " + name);
    Console.WriteLine("Tel: " + tel);
  }

  public string getName() { return name; }
  public string getTel() { return tel; }
  public void setName(string name) { this.name = name; }
  public void setTel(string tel) { this.tel = tel; }
}