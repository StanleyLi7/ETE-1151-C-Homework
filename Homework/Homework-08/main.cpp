#include <iostream>
#include <string>
using namespace std;

class System {
public:
    // No parameters
    void attack() {
        cout << "Performing default action." << endl;
    }

    // One parameter
    void attack(int damage) {
        cout << "Performing action with value: " << damage << endl;
    }

    // Two parameters
    void attack(string type, int damage) {
        cout << "Performing " << type << " action with value: "
             << damage << endl;
    }
};

int main() {
    System obj;

    obj.attack();                 // calls attack()
    obj.attack(25);               // calls attack(int)
    obj.attack("special", 50);    // calls attack(string, int)

    return 0;
}