#include <bits/stdc++.h>
using namespace std;
uint32_t reverseBits(uint32_t n)
{
    vector<int> result;
    uint32_t result_ans = 0;
    uint32_t mask = 1;

    for (int i = 0; i < 32; i++)
    {
        if (n & mask)
            result.push_back(1);
        else
            result.push_back(0);
        mask = mask << 1;
    }
    for (int i = 0; i < result.size(); i++)
    {
        if (result[i])
            result_ans += pow(2, 32 - i - 1);
    }
    return result_ans;
}

// better solution, link: https://www.youtube.com/watch?v=-5z9dimxxmI
uint32_t reverseBits(uint32_t n)
{
    n = (n >> 16) | (n << 16);
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
    return n;
}
int main()
{
    uint64_t n = 10000000001110000000000100001111;
    cout << reverseBits(n) << endl;
}