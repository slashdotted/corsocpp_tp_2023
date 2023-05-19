#include "lecturerResearcher.h"
#include <iostream>

int main() {
    LecturerResearcher lr{"Oliver", "ISIN", 1443, "CS", "C++", "AI", 0.5 };
    // NON-SOLUTION 1 - Choose a branch
    /*std::cout << "Name: " << lr.Lecturer::name() << " Research area: " << lr.researcharea() 
              << " %:" << lr.researchpercentage() << '\n';
    lr.Lecturer::name("Frank");
    std::cout << "Name: " << lr.Lecturer::name() << " Research area: " << lr.researcharea() 
              << " %:" << lr.researchpercentage() << '\n';
    std::cout << "Name: " << lr.Researcher::name() << " Research area: " << lr.researcharea() 
              << " %:" << lr.researchpercentage() << '\n';*/
    // NON-SOLUTION 2 - Reimplement the method in LecturerResearcher
    std::cout << "Name: " << lr.name() << " Research area: " << lr.researcharea() 
              << " %:" << lr.researchpercentage() << '\n';
}