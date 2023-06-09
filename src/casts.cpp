#include <string>
#include <iostream>
#include <typeinfo>
#include <map>

struct Foo {
    Foo(std::string v) 
        : value{v} {}
    std::string value;
    virtual ~Foo() = default;
};

struct Bar : virtual Foo {
    Bar(std::string v, int x) 
        : Foo{v} , mx{x} {}
    int mx; 
};

struct Baz : virtual Foo {
    Baz(std::string v, double y) 
        : Foo{v} , my{y} {}
    double my; 
};

struct Oof : Bar, Baz {
    Oof(std::string v, int x, double y, bool z) 
        : Foo{v}, Bar{v,x}, Baz{v,y}, mz{z} {}
    bool mz;
};

bool instanceOfOof(Foo* f) {
    auto p = dynamic_cast<Oof*>(f);
    return p != nullptr;
}

bool instanceOfOof(Foo& f) {
    try {
        auto p = dynamic_cast<Oof&>(f);
        return true;
    } catch(...) {
        return false;
    }
}

struct BarNV : Foo {
    BarNV(std::string v, int x) 
        : Foo{v} , mx{x} {}
    int mx; 
};

struct BazNV : Foo {
    BazNV(std::string v, double y) 
        : Foo{v} , my{y} {}
    double my; 
};

struct OofNV : BarNV, BazNV {
    OofNV(std::string v, int x, double y, bool z) 
        : BarNV{v,x}, BazNV{v,y}, mz{z} {}
    bool mz;
};

void fn(Foo*) {}
void fn(Foo&) {}

void staticcast() {
    Foo foo{"MyFoo"};
    Bar bar{"MyBar", 42};
    Baz baz{"MyBaz", 3.14};
    Oof oof{"MyOof", 13, 2.6, false};
    BarNV barnv{"MyBarNV", 42};
    BazNV baznv{"MyBazNV", 3.14};
    OofNV oofnv{"MyOofNV", 13, 2.6, false};

    fn(&foo);
    fn(&bar);
    fn(&baz);
    fn(&oof);
    fn(&barnv);
    fn(&baznv);
    //fn(&oofnv); // Ambiguous: we have two instances of Foo

    fn(foo);
    fn(bar);
    fn(baz);
    fn(oof);
    fn(barnv);
    fn(baznv);
    //fn(oofnv); // Ambiguous: we have two instances of Foo

    // static_cast<target>(source) 

    // Upcasting
    Bar bar_from_oof = static_cast<Bar>(oof); // Casting from Oof to Bar (value)
    Bar bar_from_oof_2 = oof;

    Bar& bar_ref_from_oof = static_cast<Bar&>(oof); // Casting from Oof& to Bar& (reference)
    Bar& bar_ref_from_oof_2 = oof;

    Bar* bar_ptr_from_oof = static_cast<Bar*>(&oof); // Casting from Oof* to Bar* (pointer)
    Bar* bar_ptr_from_oof_2 = &oof;

    // Downcasting

    std::cout << "&oof:" << &oof << '\n';
    //Oof oof_from_bar = static_cast<Oof>(bar_from_oof); // Error: cannot reconstruct information
    Oof& oof_ref_from_bar = static_cast<Oof&>(bar_ref_from_oof);
    //Oof& oof_ref_from_bar_2 = bar_ref_from_oof; // Implicit cast does not work

    Oof* oof_ptr_from_bar = static_cast<Oof*>(bar_ptr_from_oof);
    //Oof* oof_ptr_from_bar_2 = bar_ptr_from_oof; // Implicit cast does not work

    //BazNV baznv_from_barnv = static_cast<BazNV>(barnv);
    //BazNV* baznv_ptr_from_barnv = static_cast<BazNV*>(&barnv);
    OofNV* oofnv_ptr_from_a_bar = static_cast<OofNV*>(&barnv);
    std::cout << "my:" << oofnv_ptr_from_a_bar->my << '\n'; // Garbage
    std::cout << "mz:" << oofnv_ptr_from_a_bar->mz << '\n'; // Garbage

    Foo* foo_ptr_from_oof  = static_cast<Foo*>(&oof); // Upcasting works
    // Oof* oof_ptr_from_foo = static_cast<Oof*>(foo_ptr_from_oof); // Downcasting through a virtual doesn't

    std::cout << "&oof_ref_from_bar:" << &oof_ref_from_bar << '\n';
    std::cout << "oof_ptr_from_bar:" << oof_ptr_from_bar << '\n';

}


void dynamiccast() {
    Foo foo{"MyFoo"};
    Bar bar{"MyBar", 42};
    Baz baz{"MyBaz", 3.14};
    Oof oof{"MyOof", 13, 2.6, false};
    BarNV barnv{"MyBarNV", 42};
    BazNV baznv{"MyBazNV", 3.14};
    OofNV oofnv{"MyOofNV", 13, 2.6, false};

    // dynamic_cast<target>(source) 

    // Upcasting
    //Bar bar_from_oof = dynamic_cast<Bar>(oof); // Casting from Oof to Bar (value) is not possible
    Bar bar_from_oof_2 = oof;

    Bar& bar_ref_from_oof = dynamic_cast<Bar&>(oof); // Casting from Oof& to Bar& (reference)
    Bar& bar_ref_from_oof_2 = oof;

    Bar* bar_ptr_from_oof = dynamic_cast<Bar*>(&oof); // Casting from Oof* to Bar* (pointer)
    Bar* bar_ptr_from_oof_2 = &oof;

    // Downcasting

    std::cout << "&oof:" << &oof << '\n';
    
    Oof& oof_ref_from_bar = dynamic_cast<Oof&>(bar_ref_from_oof);
    Oof* oof_ptr_from_bar = dynamic_cast<Oof*>(bar_ptr_from_oof);

    BazNV* baznv_ptr_from_barnv = dynamic_cast<BazNV*>(&barnv);
    if(!baznv_ptr_from_barnv) {
        std::cerr << "Cast non valido\n";
    }

    try {
        BazNV& baznv_ref_from_barnv = dynamic_cast<BazNV&>(barnv);
    } catch(std::bad_cast e) {
        std::cerr << "Cast non valido\n";
    }
    
    OofNV* oofnv_ptr_from_a_bar = dynamic_cast<OofNV*>(&barnv);
    if (oofnv_ptr_from_a_bar) {
        std::cout << "my:" << oofnv_ptr_from_a_bar->my << '\n'; 
        std::cout << "mz:" << oofnv_ptr_from_a_bar->mz << '\n';
    }

    Foo* foo_ptr_from_oof  = dynamic_cast<Foo*>(&oof); // Upcasting works
    Oof* oof_ptr_from_foo = dynamic_cast<Oof*>(foo_ptr_from_oof); // Downcasting through a virtual works with dynamic_cast

    std::cout << "&oof_ref_from_bar:" << &oof_ref_from_bar << '\n';
    std::cout << "oof_ptr_from_bar:" << oof_ptr_from_bar << '\n';

    void* void_ptr_from_foo = foo_ptr_from_oof;
    //Foo* foo_ptr_from_void  = dynamic_cast<Foo*>(void_ptr_from_foo); // Can't dynamic cast from void*
}

struct Computer {

    int compute(int z) const {
        if (cache.count(z)) {
            return cache.at(z);
        }
        int result = z*z;
        Computer* c{const_cast<Computer*>(this)};
        c->cache[z] = result;
        return result;
    }

private:
    std::map<int,int> cache;
};


void constcast() {
    int i{42};
    const int& ri{i};
    const int* pi{&i};

    // ri =13;// not possible since ri is const
    // *pi = 52; // not possible since *pi is const

    int& ncri{const_cast<int&>(ri)};
    ncri = 13;
    int* ncpi{const_cast<int*>(pi)};
    *ncpi = 52;

    const Computer c;
    c.compute(44);
}



int main() {
    staticcast();
    dynamiccast();
    constcast();

}