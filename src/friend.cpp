#include <iostream>


struct Engine {
    void start() {};
    void stop() {};

private:
    friend std::ostream& operator<<(std::ostream& o, const Engine& e);
    friend void inspect(const Engine& e);
    friend struct Modder;

    int m_value{42};
    void tune(int value) {
        m_value = value;
    }
};

void inspect(const Engine& e) {
    std::cout << e.m_value;
}

std::ostream& operator<<(std::ostream& o, const Engine& e) {
    o << e.m_value;
    return o;
}

struct Modder {
    void adjust(Engine& e) {
        e.tune(100);
    }
};

int main() {
    Engine e1;
    e1.start();
    e1.stop();


    Modder m;
    m.adjust(e1);
    std::cout << e1 << '\n';
}