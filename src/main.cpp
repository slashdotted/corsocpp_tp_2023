#include "fractionV2.h"
#include <iostream>
#include <ostream>

struct Foo {
    // A constructor which takes only one parameter of some type T
    // is considered as a conversion constructor to construct/convert
    // any value of type T into Foo
    Foo(int i) {}
};

struct Device {
    explicit Device(int serialNumber) {}
};

void turnOn(const Device& d) {

}

void bar(Foo f) {
    //turnOn(6); // this fails because the constructor only allows explicit conversions
}




/*Fraction operator+(const Fraction& a, Fraction b) {
    Fraction temp{a};
    return temp += b;
}*/

Fraction operator+(Fraction a, const Fraction& b) {
    return a += b;
}

Fraction operator-(Fraction a, const Fraction& b) {
    return a -= b;
}

// Prefix (++f)
Fraction& operator++(Fraction& f) {
    return f += 1; //Fraction{1,1};
}

// Postfix (f++)
Fraction operator++(Fraction& f, int) {
    auto beforeIncrement{f};
    f += 1; // Fraction{1,1};
    return beforeIncrement;
}

std::ostream& operator<<(std::ostream& o, const Fraction& f) {
    o << f.num() << "/" 
        << f.den();
    return o;
}

void fun(double d) {
    std::cout << "fun says " << d << "\n";
}

void fun2(int d) {
    std::cout << "fun2 says " << d << "\n";
}

int main() {
    Fraction f1{7,2};
    fun(f1.toDouble());
    fun(f1);

    fun2(f1.toDouble());
    fun2(f1);

    Fraction *f2{new Fraction};
    Fraction f3{7,9};
    Fraction f4{8};
    //f1.numerator = 7;
    //f1.denominator = 3;
    f1.num(7);
    f1.den(3);
    f1.print();

    std::cout << f1 << std::endl; 

    f1 += f3;
    f1.operator+=(f3);

    Fraction f5{f1+f3}; // equivalent to Fraction f5{operator+(f1,f3)};
    f5 = 42; // f5 = Fraction{42,1}
    std::cout << "f5=" << f5 << std::endl;
    //f2->numerator = 8;
    //f2->denominator = 2;
    f2->num(8);
    f2->den(2);
    f2->print();

    Foo u{5};
    u = 7; // u = Foo{7}
    bar(8); // bar(Foo{8})

    delete f2;
}