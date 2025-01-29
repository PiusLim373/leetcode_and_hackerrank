#include <bits/stdc++.h>
std::vector<int> searchRange(std::vector<int> &nums, int target)
{
    int l = 0;
    int r = nums.size() - 1;
    while (l <= r)
    {
        if (nums[l] == target && nums[r] == target)
            return {l, r};
        if (nums[l] < target)
            l++;
        if (nums[r] > target)
            r--;
    }
    return {-1, -1};
}

int main()
{
    std::vector<int> nums = {};
    int target = 6;
    for (auto x : searchRange(nums, target))
        std::cout << x << std::endl;
}