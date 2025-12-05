#include <algorithm>
#include <math.h>

int mySqrt(int x)
{
    if (x < 2)
        return x;
    int left = 1;
    int right = x / 2;
    int ans = 1;
    while (left <= right)
    {
        unsigned long long mid = left + (right - left) / 2;
        unsigned long long sq = mid * mid;

        if (sq == x)
            return mid;
        else if (sq > x)
            right = mid - 1;
        else
        {
            ans = mid;
            left = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int n = 4;
    auto ans = mySqrt(n);
    return 0;
}