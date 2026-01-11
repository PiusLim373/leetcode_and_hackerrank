#include <vector>
#include <string>
int longestPalindromeSubseq(std::string s)
{
    std::vector<std::vector<int>> dp(s.size(), std::vector<int>(s.size(), 0));
    for (int row = s.size() - 1; row >= 0; row--)
    {
        for (int col = 0; col < s.size(); col++)
        {
            // negative string length, not valid hence zero
            if (col < row)
                continue;

            // single char also a palindrome, so 1
            else if (row == col)
                dp[row][col] = 1;

            else
            {
                char check = s[row];
                
                // curr char same as starting char, so take internal valid + 2 char
                if (s[col] == check)
                {
                    dp[row][col] = dp[row + 1][col - 1] + 2;
                }

                // not same, either take 1 one char from front or dont include current char
                else
                {
                    dp[row][col] = std::max(dp[row][col - 1], dp[row + 1][col]);
                }
            }
        }
    }
    return dp[0][s.size() - 1];
}


int main()
{
    std::string s = "bbbab";
    auto ans = longestPalindromeSubseq(s);
    return 0;
}