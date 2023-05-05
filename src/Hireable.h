#pragma once

struct Hirable {
    virtual void hire() = 0; // pure virtual
    virtual void fire() = 0; // pure virtual;
};