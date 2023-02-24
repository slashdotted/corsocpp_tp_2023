#include "hello.h"
#include <iostream>

void sayHi() {
    std::cout << "Hi moon\n";
}

//namespace supsi {
//    namespace cppcourse {
// ===
namespace supsi::cppcourse {
    void sayHi() {
        std::cout << "Hi jupyter\n";
        ::sayHi(); // This calls sayHi from the global namespace
        hellolib::sayHi(); // This calls sayHi from the hellolib namespace
    }

    void sayHello() {
        std::cout << "Hello again\n";
    }
}

namespace hellolib {
    void sayCiao() {
        std::cout << "Ciao\n";
    }
}

namespace debug {
    void sayHello() {
        std::cout << "Calling sayHello\n";
        hellolib::sayHello();
    }

    void sayHi() {
        std::cout << "Calling sayHi\n";
        hellolib::sayHi();
    }
}

// Namespace Alias 
namespace mn = debug;



int main()
{
    //mn::sayHello();
    //mn::sayHi();

    using hellolib::sayHello;
    sayHello();

    using namespace std;
    cout << "End of this class\nHave a nice weekend\n";
}


