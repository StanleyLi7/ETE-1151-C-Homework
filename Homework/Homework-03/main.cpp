#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    const double PI = acos(-1.0);
    double area;

    int choice;
    std::cout << "1. Calculate the area of a square. (1)" << std::endl;
    std::cout << "2. Calculate the area of a rectangle. (2)" << std::endl;
    std::cout << "3. Calculate the area of a circle. (3)" << std::endl;
    std::cout << "4. Calculate the area of a cylinder. (4)" << std::endl;
    std::cout << "Please enter your shape (1-4): " << std::endl;

    std::cin >> choice;

    switch(choice){
        case 1: {
            double sideLength;
            std::cout << "What is the length of the square: ";
            std::cin >> sideLength;
            area = sideLength*sideLength;
            std::cout << "The area of a square with the length of " << sideLength << " is " << area;
            break;
        }

        case 2: {
            double rectangleSideLength, rectangleSideWidth;
            std::cout << "What is the length of the rectangle: ";
            std::cin >> rectangleSideLength;
            std::cout << "What is the width of the rectangle: ";
            std::cin >> rectangleSideWidth;
            area = rectangleSideLength*rectangleSideWidth;
            std::cout << "The area of a square with the length of " << rectangleSideLength << " and width of " << rectangleSideWidth << " is " << area;
            break;
        }

        case 3: {
            double radius;
            std::cout << "What is the radius of the circle: ";
            std::cin >> radius;
            area = radius*radius*PI;
            std::cout << "The area of a circle with the radius of " << radius << " is " << area;
            break;
        }

        case 4: {
            double radius, height;
            std::cout << "What is the radius of the cylinder: ";
            std::cin >> radius;
            std::cout << "What is the height of the cylinder: ";
            std::cin >> height;
            area = (height*2*PI*radius)+(2*PI*radius*radius);
            std::cout << "The surface area of a cylinder with the radius of " << radius << " and height of " << height << " is " << area;
            break;
        }
        default:
        std::cout << "Invalid choice." <<std::endl;
    }




    return 0;
}
