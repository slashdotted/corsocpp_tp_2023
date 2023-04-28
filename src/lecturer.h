#pragma once
#include <string>
#include "employee.h"

class Lecturer : public Employee {
public:
  Lecturer(std::string name, std::string institute, int nr, std::string studies,
           std::string course);
  ~Lecturer();
  const std::string& studies() const;
  const std::string& course() const;
  std::string classname() const override;

protected:
  std::string m_studies;
  std::string m_course;
};