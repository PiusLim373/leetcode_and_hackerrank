#include <iostream>
#include <vector>

bool canJump(std::vector<int> &nums)
{
    int goal = nums.size() - 1;
    for (int i = goal; i >= 0; i--)
    {
        if (i + nums[i] >= goal)
            goal = i;
    }
    if (!goal)
        return true;
    return false;
}
bool canJump_bugged(std::vector<int> &nums)
{
    int curr = 0;

    while (nums[curr] != 0)
    {
        int max = -1;
        int max_index = -1;
        for (int i = curr + 1; i <= curr + nums[curr]; i++)
        {
            if (i >= nums.size() - 1)
                return true;
            else
            {
                if (nums[i] > max)
                {
                    max = nums[i];
                    max_index = i;
                }
            }
        }
        curr = max_index;
    }
    if (curr == nums.size() - 1)
        return true;
    else
        return false;
}
int main()
{
    // std::vector<int> nums = {5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0};
    std::vector<int> nums = {3, 2, 1, 0, 4};
    std::cout << canJump(nums) << std::endl;
}