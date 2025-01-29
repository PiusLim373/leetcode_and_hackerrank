#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> memoization;

int stepPerms(int n)
{
    if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else if (n == 3)
        return 4;
    else
    {
        if (memoization.find(n) != memoization.end())
            return memoization[n];
        else
            return (memoization[n] = stepPerms(n - 1) + stepPerms(n - 2) + stepPerms(n - 3));
    }
}

int main()
{
    cout << stepPerms(7) << endl;
    return 0;
}