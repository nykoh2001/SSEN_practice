#include <cassert>
#include <iostream>
#include <string>
#include <utility>

// Approach 1: overload buy() for each product type.
namespace approach1 {

class TV {
public:
  std::string name = "tv";
  int price = 1000;
  int point = 100;
};

class Audio {
public:
  std::string name = "audio";
  int price = 2000;
  int point = 200;
};

class Computer {
public:
  std::string name = "computer";
  int price = 3000;
  int point = 300;
};

class Buyer {
public:
  int money = 10000;
  int point = 0;

  void buy(const TV& product) { buyProduct(product); }
  void buy(const Audio& product) { buyProduct(product); }
  void buy(const Computer& product) { buyProduct(product); }

private:
  // 임의의 타입 이름 지정
  template <typename Product>
  void buyProduct(const Product& product) {
    if (money < product.price) {
      std::cout << "Need more money - current balance: " << money << ", " << product.name << " price: " << product.price << '\n';
      return;
    }

    money -= product.price;
    point += product.point;
    std::cout << "Remaining: " << money << ", Point: " << point << '\n';
  }
};

}

// Approach 2: Use polymorphism to implement only one/shared buy method
namespace approach2 {

class ElecProduct {
public:
  std::string name;
  int price;
  int point;

  ElecProduct(std::string name, int price, int point)
      : name(std::move(name)), price(price), point(point) {}
  virtual ~ElecProduct() = default;
};

class TV : public ElecProduct {
public:
  TV() : ElecProduct("tv", 1000, 100) {}
  TV(std::string name, int price, int point)
      : ElecProduct(std::move(name), price, point) {}
};

class Audio : public ElecProduct {
public:
  Audio() : ElecProduct("audio", 2000, 200) {}
  Audio(std::string name, int price, int point)
      : ElecProduct(std::move(name), price, point) {}
};

class Computer : public ElecProduct {
public:
  Computer() : ElecProduct("computer", 3000, 300) {}
  Computer(std::string name, int price, int point)
      : ElecProduct(std::move(name), price, point) {}
};

class Buyer {
public:
  int money = 10000;
  int point = 0;

  void buy(const ElecProduct& product) {
    if (money < product.price) {
      std::cout << "Need more money - current balance: " << money  << ", " << product.name << " price: " << product.price << '\n';
      return;
    }

    money -= product.price;
    point += product.point;
    std::cout << "Remaining: " << money << ", Point: " << point << '\n';
  }
};

}

int main() {
  // Approach 1:
  {
    approach1::Buyer buyer;
    buyer.buy(approach1::TV{});
    buyer.buy(approach1::Audio{});
    assert(buyer.money == 7000);
    assert(buyer.point == 300);

    buyer.money = 500;
    buyer.buy(approach1::TV{});
    assert(buyer.money == 500);
    assert(buyer.point == 300);
  }

  // Approach 2: 
  {
    approach2::Buyer buyer;
    approach2::TV tv;
    approach2::Audio audio;
    approach2::Computer computer;
    buyer.buy(tv);
    buyer.buy(audio);
    buyer.buy(computer);
    assert(buyer.money == 4000);
    assert(buyer.point == 600);

    buyer.money = 1000;
    buyer.buy(computer);
    assert(buyer.money == 1000);
    assert(buyer.point == 600);
  }

  std::cout << "All tests passed.\n";
  return 0;
}
