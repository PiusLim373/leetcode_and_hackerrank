#include <bits/stdc++.h>
using namespace std;
class Entity
{
    int a;
    int b;
    int c;

public:
    Entity(int a, int b, int c) : a(a), b(b), c(c) {}
    Entity(int a)
    {
        this->a = a;
    }
    bool operator<(Entity &b)
    {
        return a < b.a;
    }
    friend ostream &operator<<(ostream &os, const Entity &s);
};

ostream &operator<<(ostream &os, const Entity &s)
{
    os << s.b << s.a << s.c;
    return os;
}

void printFunction(int x)
{
    cout << x << endl;
}

void Foreach(vector<int> &nums, void (*func1)(int val))
{
    for (auto x : nums)
        func1(x);
}
int main()
{
    // Entity s1(6, 2, 3);
    // Entity s2(4, 2, 3);
    // if (s2 < s1)
    //     cout << "s2 smaller" << endl;
    // cout << s1 << endl;

    // vector<int> nums = {4, 5, 6, 7, 3};
    // Foreach(nums, [](int val)
    //         { cout << val << " " << endl; });
    // void (*fun2)(int) = printFunction;
    // auto fun1 = printFunction;
    // fun2(34);
    // fun1(43);
}
