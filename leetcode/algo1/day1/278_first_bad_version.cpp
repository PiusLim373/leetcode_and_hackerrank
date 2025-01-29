#include <bits/stdc++.h>
using namespace std;

int answer = 2;

bool isBadVersion(int n)
{
    if (n < answer)
        return true;
    else
        return false;
}

int firstBadVersion(int n)
{
    int left = 1;
    int right = n;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (isBadVersion(mid) && (!isBadVersion(mid - 1) || mid - 1 == 0))
            return mid;
        else if (isBadVersion(mid))
        {
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return -1;
}

int main()
{
    int n = 2;
    cout << firstBadVersion(n) << endl;
}