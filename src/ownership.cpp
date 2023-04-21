#include <iostream>
#include <vector>

struct Foo {

};

struct Bar {
    Bar() : ptr{new Foo} {}
    // RAII (Resource Acquisition Is Initialization)
    ~Bar() {
        delete ptr;
    }
    // Rule of three
    Bar(const Bar& o) : ptr{new Foo{*o.ptr}} {}
    Bar& operator=(const Bar& o) {
        *ptr = *o.ptr;
        return *this;
    }
    private:
        Foo* ptr;
};

void work_with_foo() {
    using namespace std;
    vector<Foo*> container;
    container.push_back(new Foo);
    container.push_back(new Foo);
    container.push_back(new Foo);

    cout << "Container:\n"; 
    for(auto& p : container) {
        cout << "Pointer: " << p << "\n";
    }
    
    vector<Foo*> container2{container};

    cout << "Container2:\n"; 
    for(auto& p : container) {
        cout << "Pointer: " << p << "\n";
    }

    container2.push_back(new Foo);

    for(auto& p : container) {
        delete p;
    }

    // Double free !
    for(auto& p : container2) {
        delete p;
    }

}

void work_with_bar() {
    using namespace std;
    vector<Bar> container;
    container.push_back(Bar{});
    container.push_back(Bar{});
    container.push_back(Bar{});

    cout << "Container:\n"; 
    for(auto& p : container) {
        cout << "Address: " << &p << "\n";
    }
    
    vector<Bar> container2{container};

    cout << "Container2:\n"; 
    for(auto& p : container) {
        cout << "Address: " << &p << "\n";
    }

    container2.push_back(Bar{});
}

int main() {
    using namespace std;
    Bar b; // *b.ptr (the object of type Foo) is owned by b
    work_with_bar();
}