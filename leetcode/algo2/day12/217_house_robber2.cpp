#include <iostream>
#include <vector>

int find_max(std::vector<int> &nums, int start, int end)
{
    int rob1 = 0;
    int rob2 = 0;
    for (int i = start; i < end; i++)
    {
        int temp = std::max(nums[i] + rob1, rob2);
        rob1 = rob2;
        rob2 = temp;
    }
    return rob2;
}

int rob(std::vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    else if (nums.size() == 2)
        return std::max(nums[0], nums[1]);
    return std::max(find_max(nums, 0, nums.size() - 1), find_max(nums, 1, nums.size()));
}
int main()
{
    std::vector<int> nums = {2, 3, 2}; //{2, 3,  }
    std::cout << rob(nums) << std::endl;
}