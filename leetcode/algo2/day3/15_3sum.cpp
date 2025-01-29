#include <vector>
#include <iostream>
#include <algorithm>
std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
{
    std::vector<std::vector<int>> result;
    if (nums.size() < 3)
        return result;
    std::sort(nums.begin(), nums.end()); // -4, -1, -1, 0, 1, 2
    for (int i = 0; i < nums.size() - 2; i++)
    {
        if (i > 0 && (nums[i] == nums[i - 1]))
            continue;
        int j = i + 1;
        int k = nums.size() - 1;
        int target = 0 - nums[i];
        while (j < k)
        {
            int sum_jk = nums[j] + nums[k];
            if (sum_jk == target)
            {
                result.push_back({nums[i], nums[j], nums[k]});
                std::cout << i << " " << j << " " << k << std::endl;
                j++;
                k--;
            }
            else if (sum_jk < target)
                j++;
            else
                k--;
        }
    }
    return result;
}
int main()
{
    std::vector<int> nums = {0, 0, 0, 0};
    for (auto x : threeSum(nums))
    {
        for (auto y : x)
            std::cout << y << " ";
        std::cout << std::endl;
    }
}