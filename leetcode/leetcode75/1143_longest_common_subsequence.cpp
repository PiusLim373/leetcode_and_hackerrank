#include <vector>
#include <string>

int longestCommonSubsequence(std::string text1, std::string text2)
{
    std::vector<std::vector<int>> dp(text1.size() + 1, std::vector<int>(text2.size() + 1, 0));
    for (int r = text1.size() - 1; r >= 0; r--)
    {
        for (int c = text2.size() - 1; c >= 0; c--)
        {
            if (text1[r] == text2[c])
                dp[r][c] = dp[r + 1][c + 1] + 1;
            else
                dp[r][c] = std::max(dp[r + 1][c], dp[r][c + 1]);
        }
    }
    return dp[0][0];
}
int main()
{
    std::string text1 = "abcde";
    std::string text2 = "ace";
    auto res = longestCommonSubsequence(text1, text2);
    return 0;
}