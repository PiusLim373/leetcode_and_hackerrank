#include <bits/stdc++.h>

using namespace std;

long minimumPasses(long m, long w, long p, long n)
{
    long candies_remaining = m * w;
    long day_count = 1;
    while (candies_remaining < n)
    {
        while (candies_remaining >= p)
        {
            if (m < w)
                m++;
            else
                w++;
            candies_remaining -= p;
        }
        candies_remaining += m * w;
        day_count++;
    }
    return day_count;
}

int main()
{
    long m = 1;
    long w = 1;
    long p = 6;
    long n = 45;
    cout << minimumPasses(m, w, p, n) << endl;
}