class A {
    public:
        void foo() {}
    protected:
        void bar() {}
    private:
        void baz() {};
};

class B : public A {

};

class C : protected A {

};

class D : private A {

};

class E : A { // == class E : private A

};

struct F : A { // == struct F : public A

};

int main() {
    A a;
    a.foo();
    // a.bar(); // Error: bar() is protected
    // a.baz(); // Error: baz() is private
    B b;
    b.foo();
    // b.bar(); // Error: bar() is protected
    // b.baz(); // Error: bar() "does not exist" in B (was private in A)
    C c;
    // c.foo(); // Error: foo() became protected in C
    // c.bar(); // Error: bar() is protected
    //c.baz(); // Error: bar() "does not exist" in B (was private in A)
    D d;
    // d.foo(); // Error: foo() became private in D
    // d.bar(); // bar() is private in D
    //d.baz(); // Error: bar() "does not exist" in B (was private in A)
    E e;
    // e.foo(); // Error: foo() became private in E
    // e.bar(); // bar() is private in E
    //e.baz(); // Error: bar() "does not exist" in B (was private in A)
    F f;
    f.foo();
    // f.bar(); // bar() is protected
    // f.baz(); // baz() is private
}