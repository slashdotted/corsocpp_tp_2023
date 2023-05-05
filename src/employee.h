#pragma once

#include "AbstractEmployee.h"
#include <string>

class Employee : public AbstractEmployee {
public:
  Employee(std::string name, std::string institute, int nr);
  ~Employee();
  const std::string& name() const;
  const std::string& institute() const;
  int employeenr() const;
  std::string classname() const override;

  void doWork() override {
  }

protected:
  std::string m_name;
  std::string m_institute;
  int m_employeenr;
};