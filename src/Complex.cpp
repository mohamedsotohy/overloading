#include <iostream>
#include <string>
using namespace std;

class Complex {
 private:
  int real;
  int img;
  // static int objectCount;

 public:
  Complex() {
    this->real = 0;
    this->img = 0;
    // objectCount++;
  }
  Complex(int real, int img) {
    this->real = real;
    this->img = img;
    // objectCount++;
  }

  void SetReal(int real) { this->real = real; }

  void SetImag(int img) { this->img = img; }
  int GetReal() { return this->real; }
  int GetImag() { return this->img; }

  void Display() { cout << real << "+" << img; }

  Complex operator+(Complex c) {
    Complex res;
    res.real = this->real + c.real;
    res.img = this->img + c.img;
    return res;
  }
  bool operator==(Complex c1) { return real == c1.real && img == c1.img; }

  // static int GetObjectCount()
  // {
  //     return objectCount;
  // }
};

// int Complex::objectCount = 0;

int main() {
  Complex c1(2, 5);
  Complex c2(2, 5);
  bool c3 = c1 == c2;
  cout << c3;
  return 0;
}
