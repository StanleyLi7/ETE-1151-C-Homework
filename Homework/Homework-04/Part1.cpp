#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int mapWidth;
int mapHeight;

void createRandomMap()
{
    mapWidth = (rand() % 20) + 1;
    mapHeight = (rand() % 20) + 1;

    cout << "\n--- Map Generated ---\n";
    cout << "Width: " << mapWidth << endl;
    cout << "Height: " << mapHeight << endl;
    cout << "Map boundaries:\n";
    cout << "Bottom Left: (" << -mapWidth/2 << ", " << -mapHeight/2 << ")\n";
    cout << "Top Right: (" << mapWidth/2 << ", " << mapHeight/2 << ")\n";
}

bool isLocationValid(int x, int y)
{
    int left   = -mapWidth / 2;
    int right  =  mapWidth / 2;
    int bottom = -mapHeight / 2;
    int top    =  mapHeight / 2;

    if (x >= left && x <= right && y >= bottom && y <= top)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    srand(time(0)); 

    string name;
    int x, y;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your X coordinate (Max 20): ";
    cin >> x;

    cout << "Enter your Y coordinate (Max 20): ";
    cin >> y;

    createRandomMap();

    if (isLocationValid(x, y))
    {
        cout << "\nWelcome " << name << "! Your location is inside the map!\n";
    }
    else
    {
        cout << "\nSorry " << name << ", you are outside the map boundaries!\n";
    }

    return 0;
}
