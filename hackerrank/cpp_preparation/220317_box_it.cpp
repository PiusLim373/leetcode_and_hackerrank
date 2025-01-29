#include <iostream>

class Box
{
    int b, l, h;

public:
    Box() : b(0), h(0), l(0) {}
    Box(int l, int b, int h) : l(l), b(b), h(h) {}
    int getLength()
    {
        return this->l;
    }
    int getheight()
    {
        return this->h;
    }
    int getBreadth()
    {
        return this->b;
    }
    int CalculateVolume()
    {
        return (this->b * this->h * this->l);
    }
    bool operator<(Box &b2)
    {
        if (b2.l > this->l)
            return true;
        else if (b2.l == this->l)
        {
            if (b2.b > this->b)
                return true;
        }
        return false;
    }
    friend std::ostream &operator<<(std::ostream &os, Box &b);
};

std::ostream &operator<<(std::ostream &os, Box &b)
{
    os << b.b << " " << b.l << " " << b.h;
    return os;
}

// std::ostream &operator<<(Box &b, std::ostream &os)
// {
//     std::cout << this->b << " " << this->l << " " << this->h << std::endl;
// }

int main()
{

    Box b1(2, 2, 4);      // Should set b1.l = b1.b = b1.h = 0;
    Box b2(2, 3, 4);      // Should set b1.l = 2, b1.b = 3, b1.h = 4;
    b2.getLength();       // Should return 2
    b2.getBreadth();      // Should return 3
    b2.getheight();       // Should return 4
    b2.CalculateVolume(); // Should return 24
    bool x = (b1 < b2);   // Should return true based on the conditions given
    if (x)
        std::cout << b2; // Should print 2 3 4 in order.
}