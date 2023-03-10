#include <iostream>

int main() {
    using namespace std;

    int data[] = {1,2,3,4,5};

    cout << "Iteration like in C\n";
    for (int i{0}; i<5;++i) {
        data[i] *= 2; // Can modify the array
        cout << data[i] << endl;
    }

    cout << "Iteration using C++11 ('foreach'): COPY\n";
    for (int x : data) {
        x *= 2; // x is a COPY of an element in the array
        cout << x << endl;
    }

    cout << "Iteration using C++11 ('foreach'): COPY\n";
    for (auto x : data) {
        x *= 2; // x is a COPY of an element in the array
        cout << x << endl;
    }

    cout << "Iteration using C++11 ('foreach'): reference\n";
    for (int& x : data) {
        x *= 2;
        cout << x << endl;
    }

    cout << "Iteration using C++11 ('foreach'): reference\n";
    for (auto& x : data) {
        x *= 2;
        cout << x << endl;
    }

    cout << "Iteration using C++11 ('foreach'): const reference\n";
    for (const auto& x : data) {
        // x *= 2; // ERROR: x is const
        cout << x << endl;
    }

    cout << "Iteration using C++11 ('foreach'): const reference\n";
    for (const int& x : data) {
        // x *= 2; // ERROR: x is const
        cout << x << endl;
    }

}