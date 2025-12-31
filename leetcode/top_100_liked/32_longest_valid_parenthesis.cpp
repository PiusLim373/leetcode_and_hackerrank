#include <string>
#include <vector>
int longestValidParentheses(std::string s)
{
    if (!s.size())
        return 0;
    std::vector<int> dp(s.size(), 0);
    for (int i = 1; i < s.size(); i++)
    {
        char check = s[i];

        // encounter an open
        if (check == '(')
        {
            // copy the prev value if prev is valid
            if (s[i - 1] == ')')
                dp[i] = dp[i - 1];
        }

        // encounter a close
        else
        {
            // simple case, prev is an open
            if (s[i - 1] == '(')
            {
                dp[i] = dp[i - 1] + 2;
            }

            // nested case, prev is close
            else
            {
                // jump to last valid pos
                int check_pos = i - 1 - dp[i - 1];

                // if last valid pos is open, means this block is valid, update the dp
                if (check_pos >= 0 && s[check_pos] == '(')
                    dp[i] = 2 + dp[i - 1] + dp[check_pos];
            }
        }
    }

    return *std::max_element(dp.begin(), dp.end());
}

int main()
{
    // std::string s = "()()(()))()";
    std::string s = "())";
    auto ans = longestValidParentheses(s);
    return 0;
}