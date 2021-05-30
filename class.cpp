#include <bits/stdc++.h>
using namespace std;

class Room
{
    int length;
    int breadth;

public:
    Room(Room &r)
    {
        cout << "Inside Copy constructor" << endl;
        (*this).length = r.length;
        (*this).breadth = r.breadth;
    }
    Room(int length, int breadth)
    {
        cout << "Inside Parameterised constructor" << endl;
        (*this).length = length;
        (*this).breadth = breadth;
    }
    void display()
    {
        cout << "Length of the room " << length << endl;
        cout << "Breadth of the room " << breadth << endl;
    }
    ~Room()
    {
        cout << "Destructor called" << endl;
    }
};

int main()
{
    Room r1(10, 6);
    r1.display();
    Room r2 = r1;
    r2.display();
    return 0;
}