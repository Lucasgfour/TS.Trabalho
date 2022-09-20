#include <iostream>

class Animal {
    public:
        virtual void EmitirSom() const = 0;
};

class Cachorro : public Animal {

    virtual void EmitirSom() const override {
        std::cout << "Au Au \n";
    }
};

class AnimalNulo : public Animal {

    virtual void EmitirSom() const override { 
        std::cout << "... \n";
    }
};

int main() {
    Animal* a1 = new Cachorro();
    Animal* a2 = new AnimalNulo();

    a1->EmitirSom();
    a2->EmitirSom();
}
