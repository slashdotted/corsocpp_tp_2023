#include <iostream>

struct Fraction {
    int numerator, denominator;
};

void print(const Fraction& f) {
    std::cout << f.numerator << "/" << f.denominator << std::endl;
}

int main() {
    Fraction f1;
    f1.numerator = 7;
    f1.denominator = 6;
    print(f1);
}



