#include <iostream>
#include <string>

void f() {
    int* ptr{new int};
    int* ptr2{new int{13}};

    int x{3};
    std::string msg{"Hello world"};
    if (x == 3) {
        return;
    }
    // Here x and msg are destroyed

    delete ptr;
    delete ptr2;
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