#include <vector>
#include <string>

int numDistinct(std::string s, std::string t)
{

    // dp[i][j] == num of ways to form string t[0:j-1] with s[0:i-1]
    std::vector<std::vector<long long>> dp(s.size() + 1, std::vector<long long>(t.size() + 1, 0));

    // always has one way for any s to become empty t -> by deleting everyting
    for (int row = 0; row < dp.size(); row++)
        dp[row][0] = 1;

    for (int row = 1; row < dp.size(); row++)
    {
        for (int col = 1; col < dp[0].size(); col++)
        {
            if (s[row - 1] == t[col - 1])
            {
                // matching char, can either skip curr s (row-1, col) or use curr s (row-1, col-1)
                dp[row][col] = dp[row - 1][col] + dp[row - 1][col - 1];
            }
            else
            {
                // curr s and t char not matching, no choice but to delete curr s(row)
                dp[row][col] = dp[row - 1][col];
            }
        }
    }
    return dp[s.size()][t.size()];
}
int main()
{
    // std::string s = "rabbbit", t = "rabbit";
    std::string s = "babgbag", t = "bag";
    auto ans = numDistinct(s, t);
    return 0;
}