#include <vector>
int maxSubarraySumCircular(std::vector<int> &nums)
{
    int global_max = nums[0];
    int global_min = nums[0];
    int curr_max = 0;
    int curr_min = 0;
    int total_sum = 0;
    for (auto x : nums)
    {
        total_sum += x;

        curr_max = std::max(x, curr_max + x);
        global_max = std::max(global_max, curr_max);

        curr_min = std::min(x, curr_min + x);
        global_min = std::min(global_min, curr_min);
    }

    if (global_max < 0)
        return global_max;
    else
    {
        int temp = total_sum - global_min;
        return std::max(global_max, temp);
    }
}

int main()
{
    std::vector<int> nums = {-3, -2, -3};
    // std::vector<int> nums = {1, -2, 3, -2};
    auto ans = maxSubarraySumCircular(nums);
    return 0;
}