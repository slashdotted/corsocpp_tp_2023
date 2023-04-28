#ifndef TODOELEMENT_H
#define TODOELEMENT_H
#include <string>

namespace supsi
{

enum class Urgency { LOW, NORMAL, HIGH, DONE};

using namespace std;

class TodoElement final
{
public:
    TodoElement(const string& title = "Title", const string& description = "Description", Urgency urgency = Urgency::LOW);

    string title() const;
    void title(const string& v);
    string description() const;
    void description(const string& v);
    Urgency urgency() const;
    void urgency(Urgency v);

private:
    string m_title;
    string m_description;
    Urgency m_urgency;

    friend std::ostream& operator << (std::ostream& o, const TodoElement& c);
};

}

#endif // TODOELEMENT_H
