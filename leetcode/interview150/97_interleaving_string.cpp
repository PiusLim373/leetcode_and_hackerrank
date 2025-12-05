#include <string>
#include <vector>

bool isInterleave(std::string s1, std::string s2, std::string s3)
{
    if (s1.size() + s2.size() != s3.size())
        return false;
    std::vector<std::vector<bool>> dp(s1.size() + 1, std::vector<bool>(s2.size() + 1, false));
    dp[0][0] = true;
    for (int col = 1; col < s2.size() + 1; col++)
    {
        char check = s3[col - 1];
        if (check == s2[col - 1] && dp[0][col - 1])
            dp[0][col] = true;
    }

    for (int row = 1; row < s1.size() + 1; row++)
    {
        char check = s3[row - 1];
        if (check == s1[row - 1] && dp[row - 1][0])
            dp[row][0] = true;
    }

    for (int row = 1; row < s1.size() + 1; row++)
    {
        for (int col = 1; col < s2.size() + 1; col++)
        {
            int pos = row + col - 1;
            char check = s3[pos];
            if (check == s2[col - 1] && dp[row][col - 1])
                dp[row][col] = true;
            else if (check == s1[row - 1] && dp[row - 1][col])
                dp[row][col] = true;
        }
    }
    return dp[s1.size()][s2.size()];
}

int main()
{
    // std::string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    std::string s1 = "", s2 = "", s3 = "";
    auto ans = isInterleave(s1, s2, s3);
    return 0;
}