#include "TodoElement.h"
#include <sstream>

namespace supsi
{

TodoElement::TodoElement(const string& title, const string& description, Urgency urgency)
    : m_title{title}, m_description{description}, m_urgency{urgency}
{
    //ctor
}

string TodoElement::title() const
{
    return m_title;
}

void TodoElement::title(const string& v)
{
    m_title = v;
}

string TodoElement::description() const
{
    return m_description;
}

void TodoElement::description(const string& v)
{
    m_description = v;
}

Urgency TodoElement::urgency() const
{
    return m_urgency;
}

void TodoElement::urgency(Urgency v)
{
    m_urgency = v;
}

std::ostream& operator << (std::ostream& o, const TodoElement& c)
{
    o << c.m_title << "," << c.m_description << ",";
    switch(c.m_urgency)
    {
    case Urgency::LOW:
        o << "LOW";
        break;
    case Urgency::NORMAL:
        o << "NORMAL";
        break;
    case Urgency::HIGH:
        o << "HIGH";
        break;
    default:
        o << "DONE";
    };
    return o;
}

}
