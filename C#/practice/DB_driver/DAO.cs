class DAO
{
  DB db;
  public DAO(DB db)
  {
    this.db = db;
  }

  public void get()
  {
    this.db.select();
  }
  public void add()
  {
    this.db.insert();
  }
  public void edit()
  {
    this.db.update();
  }
  public void delete()
  {
    this.db.delete();
  }
}