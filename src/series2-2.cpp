#include <iostream>

using namespace std;

void bar(int& b) {
    cout << 'A' << b;
}

// This will be ambiguous
/*void bar(int b) {
    cout << 'B' << b;
}*/

void bar(int const& b) {
    cout << 'C' << b;
}

// The const qualifier cannot be applied to a reference
/*void bar(int & const b) {
    cout << 'D' << b;
}*/

int
main(void)
{
    int* x = new int{1};
    int  y = 2;
    int const * z = x;
    int * const q = &y;

    bar(42);
    bar(*x);
    bar(y);
    bar(*z);
    bar(*q);

    delete x;

    return 0;
}