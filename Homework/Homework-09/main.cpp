#include <iostream>
#include <stdexcept>
#include <vector>

// Custom Exception
class CustomException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error in nestedFunction";
    }
};

// Division Function
double divide(int numerator, int denominator) {
    if (denominator == 0) {
        throw std::runtime_error("Division by zero is not allowed.");
    }
    return static_cast<double>(numerator) / denominator;
}

// Array Access Function using std::vector
int accessArray(const std::vector<int>& arr, int index) {
    if (index < 0 || index >= static_cast<int>(arr.size())) {
        throw std::out_of_range("Index out of bounds.");
    }
    return arr[index];
}

// Nested Exception Function
void nestedFunction() {
    throw CustomException();
}

// Outer Function with rethrow
void outerFunction() {
    try {
        nestedFunction();
    } catch (const CustomException& e) {
        std::cout << "Caught exception in outerFunction: " << e.what() << std::endl;
        throw;
    }
}

int main() {
    try {
        outerFunction();
    } catch (const CustomException& e) {
        std::cout << "Caught rethrown exception in main: " << e.what() << std::endl;
    }

    int num, denom;
    std::cout << "\nEnter numerator: ";
    std::cin >> num;
    std::cout << "Enter denominator: ";
    std::cin >> denom;

    try {
        double result = divide(num, denom);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    int size;
    std::cout << "\nEnter array size: ";
    std::cin >> size;

    std::vector<int> arr(size);

    std::cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    int index;
    std::cout << "Enter index to access: ";
    std::cin >> index;

    try {
        int value = accessArray(arr, index);
        std::cout << "Value at index " << index << ": " << value << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}