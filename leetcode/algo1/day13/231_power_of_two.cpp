#include <bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(int n)
{
    if (n <= 0)
        return false;
    double log_2 = log2(n);
    cout << log_2 << endl;
    return (int)log_2 == log2(n);
}
int main()
{
    int n = -16;

    cout << isPowerOfTwo(n) << endl;
}