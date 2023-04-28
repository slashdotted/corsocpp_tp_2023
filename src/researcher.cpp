#include "researcher.h"
#include <iostream>

Researcher::Researcher(std::string name, std::string institute, int nr, 
    std::string researcharea)
    :  Employee{name, institute, nr}, m_researcharea{researcharea} {
  std::cout << "Costructing Researcher" << std::endl;
}
Researcher::~Researcher() { std::cout << "Destroying Researcher" << std::endl; }
const std::string& Researcher::researcharea() const { return m_researcharea; }
std::string Researcher::classname() const { return "Researcher"; }