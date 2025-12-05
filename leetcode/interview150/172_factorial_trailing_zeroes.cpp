#include <math.h>

int trailingZeroes(int n)
{
    int count = 0;
    int power = 1;
    while (true)
    {
        int temp = n / pow(5, power);
        count += temp;
        if (!temp)
            break;
        power++;
    }
    return count;
}

int main()
{
    int n = 1001;
    auto ans = trailingZeroes(n);
    return 0;
}