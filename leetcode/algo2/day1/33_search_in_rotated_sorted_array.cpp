#include <bits/stdc++.h>
int search(std::vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] > nums[right])
            left = mid + 1;
        else
            right = mid;
    }
    int rotation = left; // 4

    left = 0;
    right = nums.size() - 1;

    // int actual_mid = (rotation + right / 2) % nums.size();
    // std::cout << actual_mid;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        // int actual_mid = (rotation + right / 2) % nums.size();
        int actual_mid = (mid + rotation) % nums.size();
        if (target == nums[actual_mid])
            return actual_mid;
        else if (target > nums[actual_mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// please review this again, not understand 100%

int main()
{
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2}; // {4, 5, 6, 7, 0, 1, 2, 4, 5, 6, 7}
    // std::vector<int> nums = {0, 1, 2, 4, 5, 6, 7};
    int target = 6;
    std::cout << search(nums, target) << std::endl;
}