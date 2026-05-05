#include <iostream>
#include <map>

int main() {
    // Initialize the two maps
    std::map<int, int> numbers1 = {
        {1,1},{2,2},{3,3},{4,4},{5,5},{6,6},{7,7},{8,8},{9,9}
    };

    std::map<int, int> numbers2 = {
        {1,10},{2,20},{3,30},{4,40},{5,50},{6,60},{7,70},{8,80},{9,90}
    };

    // Interlace the maps using iterators
    auto it1 = numbers1.begin();
    auto it2 = numbers2.begin();

    std::cout << "Interlaced map (numbers1): ";

    while (it1 != numbers1.end() && it2 != numbers2.end()) {
        std::cout << it1->first << ": "
                  << it1->second << ", "
                  << it2->second << " ";

        ++it1;
        ++it2;
    }

    std::cout << std::endl;

    return 0;
}