#include <vector>
#include <unordered_map>
int longestArithSeqLength(std::vector<int> &nums)
{
    // a database to store max length at pos i for common diff
    std::vector<std::unordered_map<int, int>> dp(nums.size());
    for (int i = 1; i < nums.size(); i++)
    {
        // coz we cant chg the sequence, so need to check all elements in front curr
        for (int j = 0; j < i; j++)
        {
            // compute diff for each element and if prev exists, +1 else start by 2 
            int diff = nums[i] - nums[j];
            if (dp[j].contains(diff))
                dp[i][diff] = dp[j][diff] + 1;
            else
                dp[i][diff] = 2;
        }
    }

    // loop through the database to find the max length
    int max_length = -1;
    for (auto x : dp)
    {
        for (auto y : x)
            max_length = std::max(max_length, y.second);
    }
    return max_length;
}

int main()
{
    // std::vector<int> nums = {20, 1, 15, 3, 10, 5, 8};
    std::vector<int> nums = {9,4,7,2,10};
    auto ans = longestArithSeqLength(nums);
    return 0;
}