#include <iostream>
#include <memory>

void likeInJava() {
    auto s = new std::string{"Hello world"};
    //...
    throw 42;
    delete s; // Never reached
}

void example(std::string* x) {

}

void likeInCPP() {
    std::string s{"Hello world"};
    example(&s);
    //...
    throw 42;
}

void likeInCPP2() {
    std::unique_ptr<std::string> s{new std::string{"Hello world"}};
    //...
    throw 42;
}

void fin(int i) {
    int y;
    std::unique_ptr<int> x{new int{1}}; // on the stack, 
    int* z{new int{i}};
    if (i == 0) {
        throw "Invalid number";
    }
    delete z; // Not reached if the exeception is thrown
}

void fun(int i) /* noexcept */  { // with noexcept the program terminates if an exception
                                  // "exits" this function
    try {
        fin(i);
    } catch(...) {
        std::cout << "Catch in fun\n";
        throw; // rethrow the exception
    } // THERE IS NO FINALLY IN C++ !!!
}

int main() {
    try {
        fun(0);
    } catch (char const * m) {
        std::cout << m << std::endl;
    } catch (int i) {
        std::cout << i << std::endl;
    } catch (...) {
        std::cout << "Anything else" << std::endl;
    }
    
}