#pragma once

#include <string>
#include "Hireable.h"

class AbstractEmployee : public Hirable {
public:
    virtual void doWork() = 0; // pure virtual method

    virtual std::string classname() const {
        return "AbstractEmployee";
    }

    void hire() override {
    }

    void fire() override {
    }
};