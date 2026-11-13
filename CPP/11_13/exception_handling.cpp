#include <iostream>

using namespace std;

int main() {

  int a = 1, b = 0;
  try {
    if (b == 0)
      throw 2;
    cout << a / b << endl;
  } catch (int code) {
    cout << "Error: " << code << endl;
  }
  cout << "Program terminated succesfully" << endl;

  return 0;
}