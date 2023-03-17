#include <iostream>

using namespace std;

void bar(int* b) {
    cout << 'A' << *b;
}

void bar(int b) {
    cout << 'B' << b;
}

void bar(int const* b) {
    cout << 'C' << *b;
}

// Cannot overload on const vs non-const values / pointers
/*void bar(int * const b) {
    cout << 'D' << *b;
}

void bar(int const b) {
    cout << 'E' << *b;
}*/

int
main(void)
{
    int* x = new int{1};
    int  y = 2;
    int const * z = x;
    int * const q = &y;

    //cout << "x=" << x << ", z=" << z << ", q=" << q << endl;
    //cout << "&x=" << &x << ", &z=" << &z << ", &q=" << q << endl;
    //cout << "*x=" << *x << ", *z=" << *z << ", *q=" << *q << endl;

    bar(x);
    bar(y);
    bar(z);
    bar(q);

    delete x;
    
    return 0;
}