#include <bits/stdc++.h>
using namespace std;
int hammingWeight(uint32_t n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}
int main()
{
    uint32_t n = 10000000001110000000000100001111;
    unsigned long a = 4294967295;
    // uint32_t n = 100;
    cout << hammingWeight(n) << endl;
}