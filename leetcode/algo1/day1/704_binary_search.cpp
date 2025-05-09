#include <bits/stdc++.h>
using namespace std;

int search(vector<int> nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = right - left / 2;
        if (target == nums[mid])
            return mid;
        else if (target > nums[mid])
        {
            left = mid + 1;
        }
        else if (target < nums[mid])
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    // vector<int> nums = {-1, 0, 3, 5, 9, 12};
    // int target = 12;

    vector<int> nums = {12};
    int target = 12;
    cout << search(nums, target) << endl;
}