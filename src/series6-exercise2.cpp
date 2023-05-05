#include <iostream>
using namespace std;

namespace bar {

class Alpha {
public:
    void set(double value = 0.0) {
        cout << "set double: value " << value << endl;
        m_value = value;
    }

    ~Alpha() {
        cout << "Alpha : destructor" << endl;
    }

    operator double() const {
        return m_value;
    }

protected:
    double m_value{-1.0};
};

class Beta : public Alpha {
public:
    using Alpha::set;

    void set(int value) {
        cout << "set int: value " << value << endl;
        m_value = value;
    }

    ~Beta() {
        cout << "Beta : destructor" << endl;
    }
};

}


int main(int argc, char *argv[])
{
    cout << "************* Begin **************" << endl;
    bar::Alpha ak;
    double v1 = ak;
    cout << "v1 = "<< v1 << endl;
    ak.set(4.5);
    cout << "ak = " << (double) ak << endl;
    ak.set(4);
    cout << "ak = " << (double) ak << endl;
    ak.set();
    cout << "ak = " << (double) ak << endl;
    bar::Beta bk;
    double v2 = bk;
    cout << "v2 = "<< v2 << endl;
    bk.set(4.5);
    cout << "bk = " << (double) bk << endl;
    bk.set(4);
    cout << "bk = " << (double) bk << endl;
    bk.set();
    cout << "bk = " << (double) bk << endl;
    bar::Alpha* ptr2{new bar::Beta};
    delete ptr2;
    cout << "************* End **************" << endl;
}
