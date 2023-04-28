#pragma once

#include <string>

class Employee {
  Employee(std::string name, std::string institute, int nr);
  ~Employee();
  const std::string& name() const;
  const std::string& institute() const;
  int employeenr() const;
  std::string classname() const;

protected:
  std::string m_name;
  std::string m_institute;
  int m_employeenr;
};