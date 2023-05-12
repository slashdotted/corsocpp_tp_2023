#include <iostream>
#include <iterator>

struct Foo {
    Foo() {
        std::cout << "Constructing Foo\n";
    }
    ~Foo() {
        std::cout << "Destructing Foo\n";
    }

    void sayHello() {
        std::cout << "Hello\n";
    }
};


struct FooUnique {
    FooUnique(Foo* p) : ptr{p} {}
    ~FooUnique() {
        delete ptr;
    }

    Foo& operator*() {
        return *ptr;
    }

    void bar() {
        FooUnique temp{*this};
    }

private:    
    FooUnique(const FooUnique&) {};
    FooUnique& operator=(const FooUnique&) { return *this; }

private:
    Foo* ptr;
};

void fun(FooUnique x) {}

int main() {
    FooUnique f{new Foo};
    FooUnique f2{new Foo};
    //f = f2;
    //fun(f);
    (*f).sayHello();
    f.bar();
}