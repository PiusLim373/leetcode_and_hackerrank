#include <iostream>
#include <vector>

int numberOfArithmeticSlices(std::vector<int> &nums)
{
    if (nums.size() < 3)
        return 0;
    std::vector<int> count(nums.size(), 0);
    int last_diff = -999;
    int diff_count = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        int curr_diff = nums[i] - nums[i - 1];
        if (curr_diff == last_diff)
        {
            diff_count++;
        }
        else
            diff_count = 0;
        if (diff_count >= 1)
        {
            count[i] = count[i - 1] + 1;
        }

        last_diff = curr_diff;
    }
    int res = 0;
    for (auto x : count)
        res += x;
    return res;
}
int main()
{
    // std::vector<int> nums = {1, 2, 3, 4, 8, 10, 12, 14};
    std::vector<int> nums = {7, 7, 7};
    std::cout << numberOfArithmeticSlices(nums) << std::endl;
}