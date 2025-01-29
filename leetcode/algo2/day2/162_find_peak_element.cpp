#include <vector>
#include <iostream>
#include <algorithm>

int findPeakElement(std::vector<int> &nums)
{
    if (nums.size() <= 2)
    {
        return std::distance(nums.begin(), std::max_element(nums.begin(), nums.end()));
    }

    if (nums[0] > nums[1])
        return 0;
    if (nums[nums.size() - 1] > nums[nums.size() - 2])
        return nums.size() - 1;

    int left = 0;
    int right = nums.size() - 1;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            return mid;
        else if (nums[mid] < nums[mid - 1])
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

// explanation: https://leetcode.com/problems/find-peak-element/discuss/1290642/intuition-behind-conditions-complete-explanation-diagram-binary-search
int main()
{
    std::vector<int> nums = {6, 5, 4, 3, 2, 3, 2};
    std::cout << findPeakElement(nums) << std::endl;
}