#include <vector>

struct Drawable {
    virtual void draw() = 0;
    virtual ~Drawable() {}
};

struct Square : Drawable {
    void draw() override {        
    }
};

struct Circle : Drawable {
    void draw() override {        
    }
};

struct Texture { int data; };

struct Cube : Drawable {
    Cube() : t{new Texture} {}
    Cube(const Cube& c) : t{new Texture{*c.t}} {}
    Cube& operator=(const Cube& c) {
        *t = *c.t;
        return *this;
    }
    ~Cube() override {
        delete t;
    }
    void draw() override {        
    }
private:
    Texture *t;
};

int main() {
    std::vector<Drawable*> drawables;
    drawables.push_back(new Circle);
    drawables.push_back(new Square);
    drawables.push_back(new Cube);

    // ...
    for(auto d : drawables) {
        d->draw();
    }

    // ...
    for(auto d : drawables) {
        delete d;
    }
}