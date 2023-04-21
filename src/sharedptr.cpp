#include <iostream>
#include <memory>
#include <vector>

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

void fun(std::shared_ptr<Foo> f) {
    std::cout << "Counter inside fun: " << f.use_count() << "\n";
}

void fun2(std::shared_ptr<Foo>& f) {
    std::cout << "Counter inside fun2: " << f.use_count() << "\n";
}

void fun3(Foo* f) {

}

int main() {
    std::cout << "=== Start of Main ===\n";
    {
        std::shared_ptr<Foo> ptr{new Foo};
        std::shared_ptr<Foo> ptr2 = std::make_shared<Foo>();
        std::shared_ptr<Foo> ptr3 = ptr; // We can create copies
        fun3(ptr.get());
        std::cout << "Counter before fun: " << ptr.use_count() << "\n";
        fun(ptr);
        std::cout << "Counter after fun: " << ptr.use_count() << "\n";
        fun2(ptr);
        std::cout << "Counter before fun2: " << ptr.use_count() << "\n";
        ptr->sayHello();
    }

}