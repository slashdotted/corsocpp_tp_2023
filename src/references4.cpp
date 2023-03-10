#include <iostream>

int& foo() {
    int temp{42};
    return temp; // WARNING! Returning a reference to a temporary
}

int& bar(int& x) {
    x += 10;
    return x;
}

int main() {
    std::cout << foo() << std::endl;
    int k{7};
    std::cout << bar(k) << std::endl;
}