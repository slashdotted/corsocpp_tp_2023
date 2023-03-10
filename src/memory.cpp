#include <iostream>
#include <string>

void f() {
    // Check for memory leaks using valgrind
    
    int* ptr{new int};
    int* ptr2{new int{13}};

    auto ptr3{new int{7}};
    auto* ptr4{new int{12}};

    int* ptr5{nullptr}; // In C++ don't use NULL!
    if (!ptr5) {
        //std::cout << *ptr5; // This will segfault!
    }

    // Arrays
    auto array_of_doubles{new double[100]};

    int x{3};
    std::string msg{"Hello world"};
    if (x == 3) {
        return;
    }
    // Here x and msg are destroyed
    delete ptr;
    delete ptr2;
    delete ptr3;
    delete ptr4;
    delete[] array_of_doubles; // Release the memory of an array
}

int main() {
    int x{3};
    std::string msg{"Hello world"};
    f();
    {
        int x{3};
        std::string msg{"Hello world"};
        // Here x and msg are destroyed
    }
    // Here x and msg are destroyed
}