#include <iostream>

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
  }
  Complex(int real, int img) {
    this->real = real;
    this->img = img;
  }

  void SetReal(int real) { this->real = real; }

  void SetImag(int img) { this->img = img; }
  int GetReal() { return this->real; }
  int GetImag() { return this->img; }

  // ***************************** plus ***************

  Complex operator+(Complex c) {
    return Complex(this->real + c.real, this->img + c.img);
  }

  Complex operator+(double x) { return Complex(this->real + x, this->img); }
  friend Complex operator+(int num, Complex c);

  // ***************************** minus **************

  Complex operator-(Complex c) {
    return Complex(this->real - c.real, this->img - c.img);
  }

  Complex operator-(double x) { return Complex(this->real - x, this->img); }
  friend Complex operator-(int num, Complex c);
  // ***************************** multiplication *****
  Complex operator*(Complex c) {
    return Complex(this->real * c.real, this->img * c.img);
  }

  Complex operator*(double x) { return Complex(this->real * x, this->img); }
  friend Complex operator+(int num, Complex c);
  // ***************************** division ***********
  Complex operator/(Complex c) {
    return Complex(this->real / c.real, this->img / c.img);
  }

  Complex operator/(double x) { return Complex(this->real / x, this->img); }
  friend Complex operator+(int num, Complex c);
  // ***************************** equality ***********
  bool operator==(Complex c1) { return real == c1.real && img == c1.img; }
  Complex &operator=(Complex c1) {
    this->SetReal(c1.real);
    this->SetImag(c1.img);
    return *this;
  }
  // ***************************** brackets ***********
  void operator()() { cout << real << "+" << img; }
  int operator[](int index) {
    switch (index) {
      case 0:
        return this->GetReal();

      case 1:
        return this->GetImag();
      default:

        cout << "out of boundry";
        return -1;
    }
  }
  // ***************************** print **************
  friend ostream &operator<<(ostream &out, const Complex &c);
  friend istream &operator>>(istream &in, Complex &c);
  // ***************************** increment **********
  Complex &operator++() {
    this->SetReal(this->GetReal() + 1);
    this->SetImag(this->GetImag() + 1);
    return *this;
  }

  Complex &operator++(int x) {
    this->SetReal(this->GetReal() + 1);
    this->SetImag(this->GetImag() + 1);
    return *this;
  }

  // ***************************** comparison *********
  bool operator<(Complex c) { return this->GetReal() < c.GetReal(); }
  bool operator>(Complex c) { return this->GetReal() > c.GetReal(); }

  bool operator<=(Complex c) { return this->GetReal() <= c.GetReal(); }
  bool operator>=(Complex c) { return this->GetReal() >= c.GetReal(); }
};

// ***************************** print **************

// Overload << for output
ostream &operator<<(ostream &out, const Complex &c) {
  out << c.real << " + i" << c.img;
  return out;
}

// Overload >> for input
istream &operator>>(istream &in, Complex &c) {
  in >> c.real >> c.img;
  return in;
}

Complex operator+(int num, Complex c) {
  return Complex(c.GetReal() + num, c.GetImag());
}

Complex operator-(int num, Complex c) {
  return Complex(num - c.GetReal(), c.GetImag());
}
Complex operator*(int num, Complex c) {
  return Complex(c.GetReal() * num, c.GetImag());
}
Complex operator/(int num, Complex c) {
  return Complex(num / c.GetReal(), c.GetImag());
}

int main() {
  Complex a(5, 5), b(3, 2), c(3, 8);

  a++;
  ++a;

  cout << (c <= b);
  return 0;
}
