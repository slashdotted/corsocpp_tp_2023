#ifndef TODOCONTAINER_H
#define TODOCONTAINER_H

#include <iostream>
#include <vector>
#include "TodoElement.h"


namespace supsi
{

class TodoContainer
{
public:
    TodoContainer();
    virtual ~TodoContainer();

    // Copy constructor (deep copy)
    TodoContainer(const TodoContainer& other);

    // Copy assignment operator (deep copy)
    TodoContainer& operator=(const TodoContainer& other);

    // Move constructor
    TodoContainer(TodoContainer&& other);

    // Move assignment operator
    TodoContainer& operator=(TodoContainer&& other);

    // Access operator
    TodoElement& operator[](unsigned int index);

    // Empties the container
    void clear();
    // Serialization
    void write(ostream& out) const;
    // Deserialization
    void read(istream& in);

    // Insert element at the end
    TodoElement& push_back(TodoElement* e);
    // Delete element at index
    void erase(unsigned int index);
    // Element count
    int size() const;

    friend std::ostream& operator << (std::ostream& o, const TodoContainer& c);

protected:
    void copyFrom(const TodoContainer& other);
    std::vector<TodoElement*> m_vector;


};

}

#endif // TODOCONTAINER_H
