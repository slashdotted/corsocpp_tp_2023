#include "employee.h"
#include <iostream>

Employee::Employee(std::string name, std::string institute,
                   int nr)
    : m_name{name}, m_institute{institute}, m_employeenr{nr} {
  std::cout << "Constructing Employee" << std::endl;
}

Employee::~Employee() { std::cout << "Destroying Employee" << std::endl; }

const std::string &Employee::name() const { return m_name; }

void Employee::name(const std::string& name) {
  m_name = name;
}

const std::string &Employee::institute() const { return m_institute; }

int Employee::employeenr() const { return m_employeenr; }

std::string Employee::classname() const { return "Employee"; }