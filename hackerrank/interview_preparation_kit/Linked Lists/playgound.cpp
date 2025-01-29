#include <bits/stdc++.h>
using namespace std;

bool x()
{
    cout << "func x" << endl;
    return true;
}
bool y()
{
    cout << "func y" << endl;
    return false;
}
int main()
{
    if (x() && y())
        cout << "ok" << endl;
}