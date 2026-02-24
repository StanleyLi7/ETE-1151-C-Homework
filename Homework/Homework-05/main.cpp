#include <iostream>
#include <string>

int main() {
    std::string message;
    int vowel_count = 0;

    std::cout << "Enter a message: ";
    std::getline(std::cin, message);

    for (int i = 0; i < message.length(); i++) {
        if (message[i] == 'a' || message[i] == 'e' || message[i] == 'i' || message[i] == 'o' || message[i] == 'u' ||
            message[i] == 'A' || message[i] == 'E' || message[i] == 'I' || message[i] == 'O' || message[i] == 'U') {
            vowel_count++;
        }
    }

    std::cout << "Number of vowels: " << vowel_count << std::endl;

    return 0;
}