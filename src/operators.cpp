#include <iostream>

struct Number {
    int v;

    Number(int i = 0) : v{i} {}

    Number& operator<<(int i) {
        v << i;
        return *this;
    }

    /*Number operator+(int x) {
        Number r;
        r.v = v+x;
        return r;
    }

    Number operator+(const Number& n) {
        Number r;
        r.v = v+n.v;
        return r;
    }*/
};

/*Number operator+(int x, const Number& y) {
    Number r;
    r.v = x + y.v;
    return r;
}*/

Number operator+(const Number& x, const Number& y) {
    Number r;
    r.v = x.v + y.v;
    return r;
}


int main() {
    Number n;
    n.v = 4;
    n << 1;
    Number m = n + 3; // = operator+(n,3) => operator+(n,Number{3})
    Number z = Number{3} + n; //
    Number k = m + z; //
}