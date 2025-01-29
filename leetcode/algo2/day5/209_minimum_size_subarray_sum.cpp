#include <vector>
#include <iostream>
int minSubArrayLen(int target, std::vector<int> &nums)
{
    int left = 0;
    int res = INT_MAX;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        while (sum >= target)
        {
            res = std::min(res, i - left + 1);
            sum -= nums[left++];
        }
    }
    if (res == INT_MAX)
        return 0;
    else
        return res;
}
int main()
{
    std::vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    std::cout << minSubArrayLen(target, nums) << std::endl;
}