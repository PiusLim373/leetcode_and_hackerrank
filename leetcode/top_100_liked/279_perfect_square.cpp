#include <vector>

int numSquares(int n)
{
    std::vector<int> dp(n + 1, 0);
    for (int i = 0; i < dp.size(); i++)
        dp[i] = i;

    for (int target = 1; target < dp.size(); target++)
    {
        for (int i = 1; i < target + 1; i++)
        {
            int sq = i * i;
            if (sq > target)
                break;
            dp[target] = std::min(dp[target], 1+ dp[target - sq]);
        }
    }

    return dp[n];
}
int main()
{
    int n = 1;
    auto ans = numSquares(n);
    return 0;
}