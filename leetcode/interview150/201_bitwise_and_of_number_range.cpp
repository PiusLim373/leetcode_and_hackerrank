#include <string>
#include <bitset>
int rangeBitwiseAnd(int left, int right)
{
    int i = 0;
    while (left != right)
    {
        left = left >> 1;
        right = right >> 1;
        i ++;
    }
    return left << i;
    
}
int rangeBitwiseAndTimedOut(int left, int right)
{
    int ans = left;
    for (int i = left + 1; i <= right; i++)
    {
        ans &= i;
    }
    return ans;
}

int main()
{
    int left = 5, right = 7;
    auto ans = rangeBitwiseAnd(left, right);
    return 0;
}