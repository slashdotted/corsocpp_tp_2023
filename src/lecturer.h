#pragma once
#include <string>

class Lecturer {
public:
  Lecturer(std::string name, std::string institute, int nr, std::string studies,
           std::string course);
  ~Lecturer();
  const std::string& studies() const;
  const std::string& course() const;
  std::string classname() const;

protected:
  std::string m_studies;
  std::string m_course;
};