#include <iostream>

using namespace std;

// Data Access Object: interface for DB operations
class DAO {
public:
  // virtual -> 동적바인딩: Service에 주입된 각 DAO 객체의 vptr이 DAO의 세부 클래스 메소드(virtual 오버라이딩)를 가리킴
  virtual void insert() = 0;
  virtual void select() = 0;
  virtual void update() = 0;
  virtual void del() = 0;
};

class DaoOracleImpl : public DAO {
public:
  void insert() { cout << "Oracle Insert" << endl; }
  void select() { cout << "Oracle Select" << endl; }
  void update() { cout << "Oracle Update" << endl; }
  void del() { cout << "Oracle Delete" << endl; }
};

class DaoMySQLImpl : public DAO {
public:
  void insert() { cout << "MySQL Insert" << endl; }
  void select() { cout << "MySQL Select" << endl; }
  void update() { cout << "MySQL Update" << endl; }
  void del() { cout << "MySQL Delete" << endl; }
};

/* DaoMySQLImpl, DaoPostgresImpl, etc. */

// Business logic -> call DB operations through DAO
// DAO dependency injection
class Service {
private:
  DAO *dao;

public:
  Service(DAO* dao) : dao(dao) {}
  ~Service() { delete dao; }

  void add() { dao->insert(); }
  void get() { dao->select(); }
  void edit() { dao->update(); }
  void del() { dao->del(); }
};

int main() {
  DAO* dao = new DaoOracleImpl();
  Service s(dao);

  s.add();

  return 0;
}