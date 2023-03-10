void foo(const int& a) {
}

void foo2(int& a) {
}

void bar(int a) {
}

void baz(int* a) {
}

int gen() {
    return 42;
}

int main() {
    int x;

    x = 77; // x is an L-VALUE (on the left of the assignment)
            // 77 is an R-VALUE (can only be on the right of the assignment)
    
    // x is an L-VALUE therefore
    foo(x); // x can be passed by reference
    bar(x); // x can be passed by value (-> copy!)
    baz(&x); // can be pass by using its address (which is passed by value)

    // 42 is an R-VALUE therefore
    bar(42); // 42 can be passed by value
    foo(42); // 42 can be passed by by const reference
    //foo2(42); // ERROR: 42 CANNOT be passed by non-const reference
    //baz(&42); // ERROR: 42 has no address

    // (the return value of) gen() is R-VALUE therefore
    bar(gen()); // (the return value of) gen() can be passed by alue
    foo(gen()); // (the return value of) gen() can be passed by by const reference
    //foo2(gen()); // ERROR: (the return value of) gen() CANNOT be passed by non-const reference
    //baz(&gen()); // ERROR: gen() has no address
}