#include <vector>
int maxUncrossedLines(std::vector<int> &nums1, std::vector<int> &nums2)
{
    // init a matrix that store the longest common subsequenct for nums1 :i and nums2 : j at dp[i][j]
    std::vector<std::vector<int>> dp(nums1.size() + 1, std::vector<int>(nums2.size() + 1, 0));
    for (int row = 1; row < nums1.size() + 1; row++)
    {
        for (int col = 1; col < nums2.size() + 1; col++)
        {
            // if num1[i] == nums2[j], increase diagonally
            if (nums1[row - 1] == nums2[col - 1])
            {
                dp[row][col] = dp[row - 1][col - 1] + 1;
            }

            // take the max from top or from left
            else
            {
                dp[row][col] = std::max(dp[row - 1][col], dp[row][col - 1]);
            }
        }
    }

    // return btm right
    return dp[nums1.size()][nums2.size()];
}

int main()
{
    // std::vector<int> nums1 = {2, 5, 1, 2, 5};
    // std::vector<int> nums2 = {10, 5, 2, 1, 5, 2};


    std::vector<int> nums1 = {1,4,2};
    std::vector<int> nums2 = {1,2,4};
    auto ans = maxUncrossedLines(nums1, nums2);
    return 0;
}