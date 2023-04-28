#include "employee.h"
#include "lecturer.h"
#include "researcher.h"
#include <iostream>

void foo(Employee* e) {
    std::cout << "Name: " << e->name() << '\n';
}

void foo(Employee& e) {
    std::cout << "Name: " << e.name() << '\n';
}

void bar(Employee e) {
    std::cout << "Name: " << e.name() << '\n';
}

void printClassName(const Employee& e) {
    std::cout << "printClassName " << e.classname() << '\n';
}

int main() {
    Employee tom{"Tom", "ISIN", 1234};
    Lecturer john{"John", "ISEA", 4545, "Electronics", "Soldering"};
    Researcher max{"Max", "ISIN", 6225, "Databases"};   
    std::cout << "Tom: " << tom.name() << '\n';
    std::cout << "John: " << john.name() << '\n';
    std::cout << "Max: " << max.name() << '\n';
    foo(&tom);
    foo(&john);
    foo(&max);
    foo(tom);
    foo(john);
    foo(max);
    bar(tom);
    //bar(john); // SLICING! 
    //bar(max);  // SLICING! 
    //Employee k{john};  // SLICING! 
    std::cout << " ==== Override? =====\n";
    std::cout << "tom.classname()=" << tom.classname() << '\n';
    printClassName(tom);
    std::cout << "john.classname()=" << john.classname() << '\n';
    printClassName(john);
    std::cout << "max.classname()=" << max.classname() << '\n';
    printClassName(max);
}