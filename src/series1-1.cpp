#include <string>
#include <iostream>
#include <limits>

int main() {
    using namespace std;
    const int THISYEAR{2023};
    string yourName;
    string yourSurname;
    int birthYear{1};

    cout << "What is your name? "  << flush;
    //cin >> yourName;
    getline(cin, yourName);

    cout << "What year were you born? " ;
    cin >> birthYear;
    if (cin.fail()) { // Checks if we are in an error/fail state
        cerr << "Invalid input\n";
        cin.clear(); // This clears the error/fail state
        // Ignore as many characters as possible from the
        // cin buffer, up until newline is found
        // (newline is ALSO ignored)
        cin.ignore(numeric_limits<int>::max(),'\n');
        //return 1;
    }

    cout << "What is your surname? "  << flush;
    cin >> yourSurname;

    cout << "Your name is " << yourName << "," << yourSurname
            << " and you are approximately " 
            << (THISYEAR - birthYear)
            << " years old. " << endl;
}
