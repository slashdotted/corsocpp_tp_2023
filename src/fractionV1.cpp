#include "fractionV1.h"
#include <iostream>

void print(const Fraction& f) {
    std::cout << f.numerator << "/" 
        << f.denominator << std::endl;
}

void reset(Fraction& f) {
    f.numerator = 0;
    f.denominator = 0;
}