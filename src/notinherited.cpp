#include <iostream>

using std::cout;

struct Base {
    Base() : p{new int} {
        cout << "Constructing Base\n";
    }
    
    Base(const Base& o) : p{new int{*o.p}} {
        cout << "Copy constructing Base\n";
    }

    Base& operator=(const Base& o) {
        cout << "Operator = in Base\n";
        *p = *o.p;
        return *this;
    }
    
    virtual ~Base() {
        cout << "Destroying Base\n";
        delete p;
    }

    int* p;
};

struct Derived : Base {
    Derived() : m{new int} {
        cout << "Constructing Derived\n";
    }
    
    Derived(const Derived& o) : m{new int{*o.m}} {
        cout << "Copy constructing Derived\n";
    }

    Derived& operator=(const Derived& o) {
        cout << "Operator = in Derived\n";
        *m = *o.m;
        return *this;
    }

    ~Derived() {
        cout << "Destroying Derived\n";
        delete m;
    }

    int* m;
};

int main() {
    Base* p{new Derived};

    delete p;
}