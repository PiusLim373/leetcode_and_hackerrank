#include <vector>
#include <algorithm>

int maxProduct(std::vector<int> &nums)
{
    int global_max = nums[0];
    int prev_min, prev_max;
    int new_min = nums[0], new_max = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        prev_min = new_min;
        prev_max = new_max;
        std::vector<int> temp = {nums[i], prev_min * nums[i], prev_max * nums[i]};
        new_max = *std::max_element(temp.begin(), temp.end());
        new_min = *std::min_element(temp.begin(), temp.end());
        global_max = std::max(global_max, new_max);
    }
    return global_max;
}
int main()
{
    std::vector<int> nums = {2, 3, -2, 4};
    auto ans = maxProduct(nums);
    return 0;
}