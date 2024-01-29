#include <iostream>

using namespace std;

class Cookie
{
private:
    string color;

public:
    Cookie(string color)
    {
        this->color = color;
    }
    string getColor()
    {
        return color;
    }
    void setColor(string color)
    {
        this->color = color;
    }
};

int main()
{

    Cookie *cookieOne = new Cookie("green");
    Cookie *cookieTwo = new Cookie("blue");

    cookieOne->setColor("yellow");

    cout << "C1: " << cookieOne->getColor() << endl;
    cout << "C2: " << cookieTwo->getColor() << endl;
}
