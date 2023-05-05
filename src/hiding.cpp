#include <iostream>
using std::cout;
using std::endl;

class Base {
public:
  virtual void f(double x) { 
    cout << "Base::f(double x)" << endl;
  }

  virtual void f(const std::string& k) {
    cout << "Base::f(const std::string& x)" << endl;
  } 
};

class Derived : public Base {
public:
  using Base::f; // OPTION 3: "import" f from the Base class

  void f(int x) { // this f HIDES Base::f
    cout << "Derived::f(int x)" << endl;
  }

  // OPTION 1
  /*void f(double x) override { 
    Base::f(x);
  }

  void f(const std::string& k) override {
    Base::f(k);
  }*/   
};

int main() {
  Base b;
  b.f(3.2);
  b.f(3);
  b.f("hello world");  

  Derived e;
  // e.Base::f(3.2); // OPTION 2
  e.f(3);
  // e.Base::f("hello world"); // OPTION 2
  e.f(3.2);
  e.f("Hello world");
}