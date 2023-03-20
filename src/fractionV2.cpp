#include "fractionV2.h"
#include <iostream>

/*Fraction::Fraction()
    : numerator{0}, denominator{0} {
}*/

// Delegating to another constructor is
// done through the init-list
/*Fraction::Fraction() : Fraction(1,0) {
    //Fraction(1,0); // this is a temporary object!          
}*/

Fraction::Fraction(int num, int den) 
    : numerator{num}, denominator{den} {
    //this->numerator = num;
    //this->denominator = den;
}


void Fraction::print() const {
    std::cout << this->numerator << "/" 
        << this->denominator << std::endl;
}

void Fraction::reset() {
    this->numerator = 0;
    this->denominator = 0;
}


Fraction& Fraction::operator += (const Fraction& f) {
    int temp_numerator { f.numerator * denominator };
    denominator *= f.denominator;
    numerator *= f.denominator;
    numerator += temp_numerator;
    return *this;
}


Fraction& Fraction::operator -= (const Fraction& f) {
    int temp_numerator { f.numerator * denominator };
    denominator *= f.denominator;
    numerator *= f.denominator;
    numerator += temp_numerator;
    return *this;
}