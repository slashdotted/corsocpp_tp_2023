#include <iostream>
#include <fstream>
#include <limits>
#include <sstream>
#include <assert.h>
#include "TodoContainer.h"

using namespace supsi;

/* Forward declarations */
void showElement(const TodoElement& e);
TodoElement* newTodo();
void listTodo(const TodoContainer& c);
void removeTodo(TodoContainer& c);
void editTodo(TodoContainer& c);
void saveToFile(const TodoContainer& c);
void readFromFile(TodoContainer& c);
void test();
TodoContainer test_sub();
TodoContainer test_subsub();

TodoElement* newTodo()
{
    string title, description;
    unsigned int urgency;
    Urgency imp;
    char conferma;

    cout << "Title? ";
    getline(cin, title);
    cout << "Description? ";
    getline(cin, description);
    do
    {
        cout << "Urgency? [1 Low, 2 Normal, 3 High, 4 Done] ";
        if (!(cin >> urgency))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    while(urgency < 1 || urgency > 4);
    switch(urgency)
    {
    case 1:
        imp = Urgency::LOW;
        break;
    case 2:
        imp = Urgency::NORMAL;
        break;
    case 3:
        imp = Urgency::HIGH;
        break;
    case 4:
        imp = Urgency::DONE;
    }

    cout << "Proceed? [Y/N] ";
    cin >> conferma;
    if (conferma == 'Y' || conferma == 'y')
    {
        TodoElement* t = new TodoElement(title, description, imp);
        return t;
    }
    else
    {
        return nullptr;
    }
}

void listTodo(const TodoContainer& c)
{
    cout << c;
}

void removeTodo(TodoContainer& c)
{
    cout << "========== Delete element ==========" << endl;
    listTodo(c);
    cout << "=====================================" << endl;
    int index;
    do
    {
        cout << "Which element do you want to delete? (0 to cancel) ";
        if (!(cin >> index))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (index == 0) return;
    }
    while(index < 1 || index > c.size());
    char conferma;
    cout << "Do you really want to delete " << c[index-1]<< "? [Y/N] ";
    cin >> conferma;
    if (conferma == 'Y' || conferma == 'y')
    {
        c.erase(index - 1);
        cout << "Element deleted" << endl;
    }
}

void editTodo(TodoContainer& c)
{
    cout << "========== Edit element ==========" << endl;
    listTodo(c);
    cout << "=====================================" << endl;
    int index;
    do
    {
        cout << "Which element do you want to edit? (0 to cancel) ";
        if (!(cin >> index))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (index == 0) return;
    }
    while(index < 1 || index > c.size());
    cout << "Insert new data" << endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    TodoElement* e = newTodo();
    if (e != nullptr)
    {
        c[index-1] = *e;
        cout << "Data was modified" << endl;
    }
    delete e;
}

void saveToFile(const TodoContainer& c)
{
    ofstream ofile;
    ofile.open("todolist.dat");
    c.write(ofile);
    ofile.close();
}

void readFromFile(TodoContainer& c)
{
    ifstream ifile;
    ifile.open("todolist.dat");
    c.read(ifile);
    ifile.close();
}

TodoContainer test_subsub()
{
    TodoContainer e;
    e.push_back(new TodoElement{"This", "is a test", Urgency::LOW});
    e.push_back(new TodoElement{"This", "is a test", Urgency::LOW});
    e.push_back(new TodoElement{"This", "is a test", Urgency::LOW});
    return e;
}

TodoContainer test_sub()
{
    return test_subsub();
}

void test()
{
    TodoContainer c;
    TodoContainer d;
    assert(c.size() == d.size());
    assert(c.size() == 0);
    c.push_back(new TodoElement{"This", "is a test", Urgency::LOW});
    assert(c.size() == 1);
    c.push_back(new TodoElement{"This", "is a test", Urgency::NORMAL});
    assert(c.size() == 2);
    c.push_back(new TodoElement{"This", "is a test", Urgency::HIGH});
    assert(c.size() == 3);
    c.push_back(new TodoElement{"This", "is a test", Urgency::DONE});
    assert(c.size() == 4);
    d = c;
    assert(c.size() == 4);
    assert(d.size() == 4);
    c.erase(0);
    assert(c.size() == 3);
    assert(d.size() == 4);
    c.erase(0);
    assert(c.size() == 2);
    assert(d.size() == 4);
    d.clear();
    assert(d.size() == 0);
    assert(c.size() == 2);
    ostringstream os;
    c.write(os);
    string result = os.str();
    istringstream is{result};
    d.read(is);
    ostringstream os2;
    d.write(os2);
    string result2 = os2.str();
    assert(result == result2);
    d = test_sub();
    assert(d.size() == 3);
    {
        TodoContainer f{test_sub()};
        assert(f.size() == 3);
        TodoContainer g{f};
        assert(g.size() == 3);
        TodoContainer e{std::move(g)};
    }
    cout << "All good!" << endl;
}

int main()
{
    TodoContainer c;
    TodoElement* e;
    char command;
    readFromFile(c);
    while (1)
    {
        cout << "[A]dd, [R]emove, [L]ist, [M]odify, [E]xit, [T]est ";
        cin >> command;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch(command)
        {
        case 'a':
        case 'A':
            e = newTodo();
            if (e != nullptr)
            {
                c.push_back(e);
            }
            break;
        case 'r':
        case 'R':
            removeTodo(c);
            break;
        case 'l':
        case 'L':
            listTodo(c);
            break;
        case 'm':
        case 'M':
            editTodo(c);
            break;
        case 'e':
        case 'E':
            saveToFile(c);
            return 0;
            break;
        case 't':
        case 'T':
            test();
            break;
        default:
            cout << "Invalid command" << endl;
        }
    }
    return 0;
}
