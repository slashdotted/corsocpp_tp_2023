#include <string>
#include <iostream>

// typedef is not necessary
enum Color {
    Black, Red, Green, Blue, Yellow
};

// typedef is not necessary
// enum class is strongly typed
enum class Grade {
    VeryGood, Good, Sufficent, Bad
};

// typedef is not necessary
struct Person {
    std::string name;
    unsigned int age;
};

void foo(int i) {
   if (i == 2) {
        std::cout << "It's blue\n";
   } 
}

int main() {
    Color c{Blue};
    Grade g{Grade::Good};
    foo(c);
    // foo(g); // Error: no automatic conversion from enum class to int
}