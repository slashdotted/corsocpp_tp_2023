#include <iostream>

void increase_by_one(int* a) {
   using namespace std;
   cout << "a=" << a << " &a="<< &a << endl;
   *a = *a + 1; 
}

void increase_by_one(int& a) {
   using namespace std;
   cout << "a=" << a << " &a="<< &a << endl;
   a = a + 1; 
}

void increase_by_one_not(int a) {
   a = a + 1; 
}

int main() {
    using namespace std;
    int x{7};
    auto y{&x}; // the type of y is int*, and the value is the address of x
    auto y1{&x}; // the type of y1 is int*, and the value is the address of x
    auto z{*y}; // the type of z is int, and the value is a COPY of x

    int& refx{x};  // refx is a reference to x / alias of x
    cout << "x=" << x <<  " &y="<< &y << " &y1=" << &y1 
         << " *y=" << *y << " z="<< z << " refx=" << refx << endl;
    cout << "&x=" << &x << " &refx=" << &refx << endl;
    /*increase_by_one(&x);
    cout << "x=" << x <<  " &y="<< &y << " &y1=" << &y1 << " *y=" << *y << " z="<< z << endl;
    increase_by_one_not(x);
    cout << "x=" << x <<  " &y="<< &y << " &y1=" << &y1 << " *y=" << *y << " z="<< z << endl;*/
    increase_by_one(y1);
    cout << "x=" << x <<  " &y="<< &y << " &y1=" << &y1 
         << " *y=" << *y << " z="<< z << " refx=" << refx << endl;
    increase_by_one(x);
    cout << "x=" << x <<  " &y="<< &y << " &y1=" 
         << &y1 << " *y=" << *y << " z="<< z << " refx=" << refx << endl;

}