#include <vector>
int maxSubArray(std::vector<int> &nums)
{
    int curr_sum = 0;
    int max_sum = nums[0];
    for (auto x: nums)
    {
        if (curr_sum < 0)
            curr_sum = 0;
        curr_sum += x;
        max_sum = std::max(max_sum, curr_sum);
    }
    return max_sum;
}
int maxSubArrayKadane(std::vector<int> &nums)
{
    int max_sum = nums[0];
    int max_curr = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        max_curr = std::max(nums[i], max_curr + nums[i]);
        max_sum = std::max(max_sum, max_curr);
    }
    return max_sum;
}
int main()
{
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    auto ans = maxSubArray(nums);
    return 0;
}