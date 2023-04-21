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

void fun(std::unique_ptr<Foo> f) {
    
}

void fun2(std::unique_ptr<Foo>& f) {
    
}

void fun3(std::unique_ptr<Foo>&& f) {
    
}

void fun4(Foo*) {

}

int main() {
    std::cout << "=== Start of Main ===\n";
    {
        std::unique_ptr<Foo> ptr{new Foo};
        ptr->sayHello();
        (*ptr).sayHello();
        fun4(ptr.get()); // the get() method gives us a Foo*
        Foo* theptr = ptr.release();
        delete theptr;
    }
    auto ptr2 = std::make_unique<Foo>();
    auto ptr3 = std::make_unique<Foo>();
    //ptr2 = ptr3; // Cannot create copies of unique_ptr
    // fun(ptr2); // Cannot create copies of unique_ptr
    fun2(ptr2);
    fun3(std::move(ptr2)); // Transferring the ownership to fun3
    
    std::vector<std::unique_ptr<Foo>> container;
    container.push_back(std::move(ptr3)); // With move we transfer the ownership to container
    //ptr3->sayHello(); // This should not be done! The ownership has been transferred!
    std::cout << "=== End of Main ===\n";


}