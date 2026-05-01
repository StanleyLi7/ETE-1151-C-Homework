#include <iostream>
#include <vector>

int main() {
    // Initialize the two vectors
    std::vector<int> numbers1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> numbers2 = {10, 20, 30, 40, 50, 60, 70, 80, 90};

    // Optional: resize numbers1 to avoid repeated reallocations
    numbers1.resize(numbers1.size() + numbers2.size());

    // Reset numbers1 to original values (since resize adds default 0s)
    numbers1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Iterators
    auto it1 = numbers1.begin();
    auto it2 = numbers2.begin();

    // Interlace elements
    while (it1 != numbers1.end() && it2 != numbers2.end()) {
        ++it1; // move past current element in numbers1

        // insert element from numbers2 into numbers1
        it1 = numbers1.insert(it1, *it2);

        ++it1; // move past inserted element
        ++it2;
    }

    // If numbers2 is longer, append remaining elements
    while (it2 != numbers2.end()) {
        numbers1.insert(numbers1.end(), *it2);
        ++it2;
    }

    // Print the interlaced vector
    std::cout << "Interlaced vector (numbers1): ";
    for (int num : numbers1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}