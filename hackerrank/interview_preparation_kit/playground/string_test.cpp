#include <bits/stdc++.h>
using namespace std;

class Box
{
private:
    int b, l, h;

public:
    Box(int x, int y, int z)
    {
        l = x;
        b = y;
        h = z;
    }
    Box()
    {
        l = 0;
        b = 0;
        h = 0;
    }
    int getLength()
    {
        return l;
    }
    int getBreadth()
    {
        return b;
    }
    int getheight()
    {
        return h;
    }
    int CalculateVolume()
    {
        return b * l * h;
    }
    friend ostream &operator<<(ostream &os, Box &box)
    {
        os << box.l << " " << box.b << " " << box.h << endl;
        return os;
    }
    friend bool operator<(Box &ba, Box &bb)
    {
        if (ba.l < bb.l)
            return true;
        else if (ba.l == bb.l && ba.b < bb.b)
            return true;
        else if (ba.l == bb.l && ba.b == bb.b and ba.h < bb.h)
            return true;
        return false;
    }
};

class Person
{
public:
    string name;
    int age;
    virtual void getdata() {}
    virtual void putdata() {}
};

class Professor : public Person
{
public:
    static int cur_id;
    int publications;
    void getdata()
    {
        cin >> name >> age >> publications;
        cur_id++;
    }
    void putdata()
    {
        cout << cur_id;
    }
};

class Student : public Person
{
    int marks[6];
    static int cur_id;
    void getdata()
    {
        cin >> name >> age;
        for (int i = 0; i < 6; i++)
            cin >> marks[i];
        cur_id++;
    }
    void putdata()
    {
        int sum = 0;
        for (auto x : marks)
            sum += x;
        cout << name << age << sum << cur_id;
    }
};

int Student::cur_id = 1;
int Professor::cur_id = 1;

int main()
{
    int a = 10;
    int *ptr = &a;
    int &b = a;
    cout << *(&b) << endl;
    // cout << *b << endl;
}