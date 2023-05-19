#pragma once
#include "lecturer.h"
#include "researcher.h"

class LecturerResearcher : public Lecturer, public Researcher {
    public:
        LecturerResearcher(std::string name, std::string institute,
            int nr, std::string studies, std::string course,
            std::string researcharea,
            double researchpercentage);

        double researchpercentage() const;
        //const std::string& name() const;
        std::string classname() const override;

    private:
        double m_researchpercentage;
};