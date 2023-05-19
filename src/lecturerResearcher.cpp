#include "lecturerResearcher.h"
#include "lecturer.h"

LecturerResearcher::LecturerResearcher(std::string name, std::string institute,
    int nr, std::string studies, std::string course,
    std::string researcharea,
    double researchpercentage) 
        : Employee{name, institute, nr},
          Lecturer{name,institute,nr,studies,course}, // Initialize the Lecturer base class
          Researcher{name,institute,nr,researcharea}, // Initialize the Researcher base class
          m_researchpercentage{researchpercentage} {
    }

double LecturerResearcher::researchpercentage() const {
    return m_researchpercentage;
}

std::string LecturerResearcher::classname() const {
    return "LecturerResearcher";
}

/*const std::string& LecturerResearcher::name() const {
    return Lecturer::name();
}*/