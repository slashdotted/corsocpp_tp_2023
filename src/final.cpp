class Destination final {
};

// final forbids inheriting from Destination
/*class Derived : public Destination {
}*/


struct Example {
    virtual void foo() {}
    virtual void bar() final {}
};

struct Derived : Example {
    void foo() override final {}
    /*void bar() override { 
    }*/ // Cannot override final method
};

struct DoubleDerived : Derived {
    // void foo() override {} // Error, cannot override final method
};

int main() {

}