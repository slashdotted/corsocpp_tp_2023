#include <iostream>

void swap(int* a, int* b) {
    int t{*a};
    *a = *b;
    *b = t;
}

void swap(int& a, int& b) {
    int t{a};
    a = b;
    b = t;
}

int main() {
    //int& c; // Cannot declare a reference that isn't initialized
    int a{42}, b{17};
    std::cout << "a=" << a << ", b=" << b << std::endl;
    swap(&a,&b);
    std::cout << "a=" << a << ", b=" << b << std::endl;
    swap(a,b);
    std::cout << "a=" << a << ", b=" << b << std::endl;

    // int *x, *y;
    // swap(x,y);
}