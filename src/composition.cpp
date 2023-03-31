#include <iostream>

using std::cout;

struct Light {
    Light() {
        cout << "Light constructed\n";
    }

    ~Light() {
        cout << "Light destructed\n";
    }

    double power;
    bool state;
};

struct Door {
    Door() {
        cout << "Door constructed\n";
    }

    ~Door() {
        cout << "Door destructed\n";
    }

    int number;
};

struct Table {
    Table() {
        cout << "Table constructed\n";
    }

    ~Table() {
        cout << "Table destructed\n";
    }

    int number;
};

struct Room {
    Room() : l{new Light} {
        ++rooms;
        cout << "Room constructed\n";
    }

    // Copy constructor 
    Room(const Room& o) : t{o.t}, d{o.d}, l{new Light{*o.l}} {
        ++rooms;
        cout << "Room copy-constructed\n";
    }

    // Copy assignment operator
    Room& operator=(const Room& o) {
        cout << "Room copy-assigment\n";
        t = o.t;
        d = o.d;
        *l = *o.l;
        return *this;
    }

    ~Room() {
        --rooms;
        delete l;
        cout << "Room destructed\n";
    }

    Table t;
    Door d;
    Light* l;

    static unsigned int getRoomCount() {
        return rooms;
    }

private:
    static unsigned int rooms;

};

unsigned int Room::rooms = 0; // initialize the static field rooms inside Room


void check(Room r) {
    cout << "Checking room\n";
    // here r is destroyed
}

int main() {
    {
        Room a;
        cout << "Calling check\n";
        check(a); // we pass-by-value, creating a copy of a
        cout << "Exiting scope\n";

        Room z;
        cout << "Doing z=a\n";
        z = a; // here we copy a into z
        // z.operator=(a);
    }


    /*Room *b{new Room};
    check(*b);
    delete b;*/
}