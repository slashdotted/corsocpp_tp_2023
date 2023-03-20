#pragma once

// for struct the default is public
// for class the default is private
class Fraction {
public:
    Fraction(int num = 0, int den = 1);
    // Fraction();

private: // or protected:
    int numerator, denominator;

public:
    // const prevents you from modifying 
    // the state of Fraction from print
    void print() const;
    void reset();

    Fraction& operator += (const Fraction& f);
    Fraction& operator -= (const Fraction& f);
    
    // inline implementation
    int num() const {
        return numerator;
    }
    int den() const {
        return denominator;
    }
    void num(int n) {
        numerator = n;
    }
    void den(int d) {
        denominator = d;
    }

};