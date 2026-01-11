#include <vector>
#include <string>
int minimumDeleteSum(std::string s1, std::string s2)
{
    // create an matrix of horizontal (0 + s2) and vertical (0 + s1) hence size +1
    // dp[i][j] == min score to make s1[i:] == s2[j:]
    std::vector<std::vector<int>> dp(s1.size() + 1, std::vector<int>(s2.size() + 1, 0));

    // populate the 0th row and col by summing the string acsii value, eg: match an empty string by delete the opp string
    for (int col = 1; col < s2.size() + 1; col++)
        dp[0][col] = dp[0][col - 1] + int(s2[col - 1]);
    for (int row = 1; row < s1.size() + 1; row++)
        dp[row][0] = dp[row - 1][0] + int(s1[row - 1]);

    // populate remaining matrix
    for (int row = 1; row < s1.size() + 1; row++)
    {
        for (int col = 1; col < s2.size() + 1; col++)
        {
            // if s1[i] == s2[j], move diag
            if (s1[row - 1] == s2[col - 1])
                dp[row][col] = dp[row - 1][col - 1];

            // if not the either from left + delete curr s2 or from top delete curr s1, whoever cheaper
            else
                dp[row][col] = std::min(dp[row - 1][col] + int(s1[row - 1]), dp[row][col - 1] + int(s2[col - 1]));
        }
    }

    // return the last slot of the matrix, eg: min score to make s1 == s2
    return dp[s1.size()][s2.size()];
}
int main()
{
    // std::string s1 = "sea";
    // std::string s2 = "eat";

    std::string s1 = "delete";
    std::string s2 = "leet";
    auto ans = minimumDeleteSum(s1, s2);
    return 0;
}