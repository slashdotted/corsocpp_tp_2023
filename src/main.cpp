#include "fractionV2.h"

int main() {
    Fraction f1;
    Fraction *f2{new Fraction};
    Fraction f3{7,9};
    Fraction f4{8};
    //f1.numerator = 7;
    //f1.denominator = 3;
    f1.num(7);
    f1.den(3);
    f1.print();

    //f2->numerator = 8;
    //f2->denominator = 2;
    f2->num(8);
    f2->den(2);
    f2->print();

    delete f2;
}