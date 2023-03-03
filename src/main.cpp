#include <iostream>
#include <string>

// Forward declarations
double average(double a, double b);
double average(double a, double b, double c);
// Default values
// --> always in the declaration!
double sum(double a, double b = 0, double c = 0);
// This will clash with double sum(double a, double b, double c = 0)
/*double sum(double a, double b) {

}*/

void fun(int a, double b);
void fun(double a, int b);

double average(int a, int b) {
    std::cout << "Average int,int\n";
    return (a+b)/2;
}

double sum(double a, double b, double c) {
    return a+b+c;
}
int f(int) {
    return 3;
}

double f(double) {
    return 3;
}


// NOT a valid overload (cannot overload on the return value)
/*int average(double a, double b) {
    return (a+b)/2;
}*/

int main() {
    using namespace std;
    cout << "The average of 2 and 5 is " << average(2, 5) << "\n";
    cout << "The average of 2.5 and 5.1 is " << average(2.5, 5.1) << "\n";
    cout << "The sum of 3.14 and 2 and 1 is " << sum(3.14, 2, 1) << "\n";
    cout << "The sum of 3.14 and 2 is " << sum(3.14, 2) << "\n";
    cout << "The sum of 3.14 is " << sum(3.14) << "\n";
    //fun(3,double(4));
    //fun(int(3.5),5.6);
    f(3);

    //int pi = 3.14;
    //int pi2(3.14);
    double e{2.6}; // C++ 11 way of initializing things
    // e{2.62}; // This will not compile
    auto pi{3.14};

    auto x{f(5.5)};

    string message = "Hello world";
    cout << message << ", " << "Length: " << message.length() << " is empty?" << message.empty() << "\n";
    string message2 = message + "!";
    cout << message2 << ", " << "Length: " << message2.length() << " is empty?" << message2.empty() << "\n";
    cout << message2[0] << message[1] << "\n";

    
}

double average(double a, double b) {
    std::cout << "Average double,double\n";
    return (a+b)/2;
}

double average(double a, double b, double c) {
    std::cout << "Average double,double,double\n";
    return (a+b+c)/3;
}