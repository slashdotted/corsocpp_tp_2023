#include "mylist.h"

int main() {
    MyList<int> l{10};
    l[5] = 42;
    MyList<double> l2{10};
    l[5] = 3.14;
}