#include <iostream>
#include <string>

// Base class
class Pokemon {
protected:
    std::string name;
    int level;
    std::string type;

public:
    Pokemon(std::string n, int l, std::string t)
        : name(n), level(l), type(t) {}

    virtual ~Pokemon() {}

    void displayInfo() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Level: " << level << std::endl;
        std::cout << "Type: " << type << std::endl;
    }

    // Polymorphic functions
    virtual void attack() const = 0;
    virtual void defend() const = 0;
    virtual void evolve() = 0;
};

// Intermediate type class
class ElectricPokemon : public Pokemon {
public:
    ElectricPokemon(std::string n, int l)
        : Pokemon(n, l, "Electric") {}
};

// Derived class
class Pikachu : public ElectricPokemon {
public:
    Pikachu(int l) : ElectricPokemon("Pikachu", l) {}

    void attack() const override {
        std::cout << name << " uses Thunderbolt!" << std::endl;
    }

    void defend() const override {
        std::cout << name << " dodges the attack!" << std::endl;
    }

    void evolve() override {
        if (level >= 20) {
            std::cout << name << " evolves into Raichu!" << std::endl;
            name = "Raichu";
        } else {
            std::cout << name << " is not ready to evolve." << std::endl;
        }
    }
};

int main() {
    Pikachu pikachu(10);

    pikachu.displayInfo();
    pikachu.attack();
    pikachu.defend();
    pikachu.evolve();

    return 0;
}