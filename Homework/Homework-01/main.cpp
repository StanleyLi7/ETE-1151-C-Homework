#include <iostream>
#include <cmath>

int main() {
    std::cout << "Enter a value: ";

    float floatVal;
    char ch;
    int intVal;
    
    // INT or FLOAT
    if (std::cin >> floatVal) {

        // Check if input has decimal part
        if (std::floor(floatVal) == floatVal) {
            int intVal = static_cast<int>(floatVal);

            std::cout << "You entered " << intVal
                      << "\nThis is an integer in binary: ";

            for (int i = 31; i >= 0; i--) {
                std::cout << ((intVal >> i) & 1);
            }
            std::cout << std::endl;
        }
        //Is float
        else {
            std::cout << "You entered " << floatVal
                      << "\nThis is a float in binary: ";

            unsigned char* p =
                reinterpret_cast<unsigned char*>(&floatVal);

            for (int i = sizeof(floatVal) - 1; i >= 0; i--) {
                for (int j = 7; j >= 0; j--) {
                    std::cout << ((p[i] >> j) & 1);
                }
            }
            std::cout << std::endl;
        }
    }

    // CHAR
    else {
        std::cin.clear();
        std::cin >> ch;

        std::cout << "You entered " << ch
                  << "\nThis is a char in binary: ";

        for (int i = 7; i >= 0; i--) {
            std::cout << ((ch >> i) & 1);
        }
        std::cout << std::endl;
    }

    return 0;
}
