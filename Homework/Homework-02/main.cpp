#include <iostream>
#include <string>

int main() {
    std::string userInput;
    std::cout << "Which Country do you live in?" << std::endl;
    std::cin >> userInput;
    std::cout << "I've heard that " << userInput << " is a great place to live! I'd love to visit!" << std::endl;
    return 0;
}