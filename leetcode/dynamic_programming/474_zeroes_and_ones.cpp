#include <vector>
#include <string>
int findMaxForm(std::vector<std::string> &strs, int m, int n)
{
    // convert the input to arrays for pair, each entry represent {num of 1, nums of 0}
    std::vector<std::pair<int, int>> nums;
    for (auto x : strs)
    {
        int ones = 0, zeroes = 0;
        for (auto y : x)
        {
            if (y == '0')
                zeroes++;
            else
                ones++;
        }
        nums.push_back({ones, zeroes});
    }

    // database, dp[i][j] means max string with i amount of zeros and j amount of 1
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    for (auto x : nums)
    {
        // loop backwards becoz this is a 0/1 knapsack problem, stop at zeros / one to be subtracted so we can omot checking if within matrix bound
        for (int row = dp.size() - 1; row >= x.second; row--)
        {
            for (int col = dp[0].size() - 1; col >= x.first; col--)
            {
                // a choice to include curr or not, if to include, then check prior i-x.second j-x.first position
                dp[row][col] = std::max(dp[row][col], dp[row - x.second][col - x.first] + 1);
            }
        }
    }
    return dp[m][n];
}
int main()
{
    // std::vector<std::string> strs = {"10", "0001", "111001", "1", "0"};
    std::vector<std::string> strs = {"10", "0", "1"};
    int m = 1, n = 1;
    auto ans = findMaxForm(strs, m, n);
    return 0;
}