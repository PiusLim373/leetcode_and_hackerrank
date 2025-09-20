#include <vector>
#include <string>

int minDistance(std::string word1, std::string word2)
{
    std::vector<std::vector<int>> dp(word1.size() + 1, std::vector<int>(word2.size() + 1, 0));
    int r = word1.size();
    for (int c = word2.size(); c >= 0; c--)
        dp[r][c] = word2.size() - c;
    int c = word2.size();
    for (int r = word1.size(); r >= 0; r--)
        dp[r][c] = word1.size() - r;

    for (int r = word1.size() - 1; r >= 0; r--)
    {
        for (int c = word2.size() - 1; c >= 0; c--)
        {
            if (word1[r] == word2[c])
            {
                dp[r][c] = dp[r + 1][c + 1];
            }
            else
            {
                dp[r][c] = 1 + std::min(dp[r + 1][c + 1], std::min(dp[r][c + 1], dp[r + 1][c]));
            }
        }
    }
    return dp[0][0];
}

int main()
{
    std::string word1 = "horse";
    std::string word2 = "ros";
    auto res = minDistance(word1, word2);
    return 0;
}