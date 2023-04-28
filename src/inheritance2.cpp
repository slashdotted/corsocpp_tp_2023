struct A {
    public:
        void foo() {}
    protected:
        void bar() {}
    private:
        void baz() {};
};

class E : A {  // == struct E : private A
};

struct F : A { // == struct F : public A
};

int main() {
    E e;
    // e.foo(); // Error: foo() became private in E
    // e.bar(); // bar() is private in E
    // e.baz(); // Error: bar() "does not exist" in B (was private in A)

    F f;
    f.foo();
    //f.bar(); // bar() is protected
    //f.baz(); // baz() is private
    
}