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

    Foo* get() const {
        return ptr;
    }

    void release() {
        ptr = nullptr;
    }

    Foo& operator*() {
        return *ptr;
    }

private:    
    FooUnique(const FooUnique&) {};
    FooUnique& operator=(const FooUnique&) { return *this; }

private:
    Foo* ptr;
};


struct FooShared {
    FooShared(Foo* p) : ptr{p}, counter{new int{1}} {}
    ~FooShared() {
       decrementAndDelete();
    }
    FooShared(const FooShared& o) : ptr{o.ptr}, counter{o.counter}{
        ++(*counter);
    }

    int use_count() const {
        return *counter;
    }

    Foo& operator*() {
        return *ptr;
    }

    FooShared& operator=(const FooShared& o) {
        decrementAndDelete(); // Takes care of the currently owned object
        ptr = o.ptr;
        counter = o.counter;
        ++(*counter);
        return *this;
    }

    Foo* get() const {
        return ptr;
    }
private:
    void decrementAndDelete() {
        --(*counter);
        if (*counter == 0) {
            delete ptr;
            delete counter;
        }
    }

    Foo* ptr;
    int* counter;  
};

void fun(FooUnique x) {}

void fun(FooShared x) {}

int main() {
    FooUnique f{new Foo};
    FooUnique f2{new Foo};
    //f = f2;
    //fun(f);
    (*f).sayHello();

    FooShared fs{new Foo};
    FooShared fs2{new Foo};
    fs = fs2;
    fun(fs);
    (*fs2).sayHello();

}