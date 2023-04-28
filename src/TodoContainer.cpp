#include "TodoContainer.h"
#include <stdexcept>
#include <cassert>
#include <sstream>

namespace supsi
{

TodoContainer::TodoContainer()
{
}

TodoContainer::~TodoContainer()
{
    clear();
}

TodoContainer::TodoContainer(const TodoContainer& other)
{
    copyFrom(other);
}

void TodoContainer::copyFrom(const TodoContainer& other)
{
    for (const auto& e : other.m_vector)
    {
        m_vector.push_back(new TodoElement{*e});
    }
}

TodoContainer& TodoContainer::operator=(const TodoContainer& rhs)
{
    if (this != &rhs)
    {
        clear();
        copyFrom(rhs);
    }
    return *this;
}

TodoElement& TodoContainer::operator[](unsigned int index)
{
    if (m_vector.empty() || index >= m_vector.size())
    {
        throw out_of_range("Invalid index");
    }
    return *m_vector[index];
}

TodoElement& TodoContainer::push_back(TodoElement* e)
{
    m_vector.push_back(e);
    return *e;
}

void TodoContainer::erase(unsigned int index)
{
    if (m_vector.empty() || index >= m_vector.size())
    {
        throw out_of_range("Invalid index");
    }
    delete m_vector[index];
    m_vector.erase(m_vector.begin() + index);
}

void TodoContainer::clear()
{
    for (const auto& e : m_vector) {
        delete e;
    }
    m_vector.clear();
}

void TodoContainer::write(ostream& out) const
{
    for (const auto& e : m_vector)
    {
        out << e->title() << endl;
        out << e->description() << endl;
        switch(e->urgency())
        {
        case Urgency::LOW:
            out << 1;
            break;
        case Urgency::NORMAL:
            out << 2;
            break;
        case Urgency::HIGH:
            out << 3;
            break;
        default:
            out << 4;
        }
    }
}

void TodoContainer::read(istream& in)
{
    while(!in.eof() && !in.fail())
    {
        string title;
        string description;
        Urgency i;
        int imp;
        getline(in, title);
        if (in.eof()) break;
        getline(in, description);
        if (in.eof()) break;
        in >> imp;
        switch(imp)
        {
        case 1:
            i = Urgency::LOW;
            break;
        case 2:
            i = Urgency::NORMAL;
            break;
        case 3:
            i = Urgency::HIGH;
            break;
        default:
            i = Urgency::DONE;
        }
        TodoElement* e{new TodoElement{title, description, i}};
        push_back(e);
    }
}

int TodoContainer::size() const
{
    return m_vector.size();
}

TodoContainer::TodoContainer(TodoContainer&& other)
{
    m_vector = std::move(other.m_vector);
}

TodoContainer& TodoContainer::operator=(TodoContainer&& other)
{
    clear();
    m_vector = std::move(other.m_vector);
    return *this;
}

std::ostream& operator << (std::ostream& o, const TodoContainer& c)
{
    unsigned int index{0};
    for (const auto& e : c.m_vector)
    {
        o << ++index << ". " << *e << endl;
    }
    return o;
}

}


