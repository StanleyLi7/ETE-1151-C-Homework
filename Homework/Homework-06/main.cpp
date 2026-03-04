#include <iostream>

void swapArrays(int arr1[], int size1, int arr2[], int size2)
{
    int minSize = (size1 < size2) ? size1 : size2;

    for (int i = 0; i < minSize; i++)
    {
        int temp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = temp;
    }
}

void findMatches(int arr1[], int size1, int arr2[], int size2)
{
    std::cout << "Matching values:\n";

    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                std::cout << arr1[i] << " ";
            }
        }
    }

    std::cout << std::endl;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int data[]  {1, 3, 6, 7, 9};
    int data1[] {5, 3, 3, 11};

    int size1 = sizeof(data) / sizeof(data[0]);
    int size2 = sizeof(data1) / sizeof(data1[0]);

    std::cout << "Before Swap:\n";
    printArray(data, size1);
    printArray(data1, size2);

    swapArrays(data, size1, data1, size2);

    std::cout << "\nAfter Swap:\n";
    printArray(data, size1);
    printArray(data1, size2);

    std::cout << std::endl;
    findMatches(data, size1, data1, size2);

    return 0;
}