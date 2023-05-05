#include <iostream>
using namespace std;

class Example {
public:
  void f(double x) {  // overload of f
    cout << "f(double x)" << endl;
  }

  void f(int x) { // overload of f
    cout << "f(int x)" << endl;
  }
};

void foo(double x, double y) { // overload of foo

}

void foo(int k) { // overload of foo
  
}

int main() {
  Example e;
  e.f(3.2);
  e.f(3);
}