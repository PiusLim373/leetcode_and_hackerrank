#include <vector>
#include <iostream>
int numSubarrayProductLessThanK(std::vector<int> &nums, int k)
{
    std::vector<int> debug;
    int res = 0;
    if (k <= 1)
        return 0;

    int left = 0;
    int product = 1;
    for (int right = 0; right < nums.size(); right++)
    {
        product *= nums[right];
        while (product >= k)
        {
            product /= nums[left++];
        }
        res += right - left + 1;
    }
    return res;
}
int main()
{
    std::vector<int> nums = {1, 1, 1};
    int k = 1;
    std::cout << numSubarrayProductLessThanK(nums, k) << std::endl;
}