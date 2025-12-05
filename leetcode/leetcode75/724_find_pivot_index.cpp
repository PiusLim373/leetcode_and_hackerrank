#include <vector>

int pivotIndex(std::vector<int> &nums)
{

    std::vector<int> left, right;
    left.resize(nums.size(), 0);
    left[0] = nums[0];
    right.resize(nums.size(), 0);
    right[nums.size() - 1] = nums[nums.size() - 1];

    for (int i = 1; i < nums.size(); i++)
    {
        left[i] = left[i - 1] + nums[i];
    }

    for (int i = nums.size() - 2; i >= 0; i--)
    {
        right[i] = right[i + 1] + nums[i];
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (left[i] == right[i])
            return i;
    }
    return -1;
}

int main()
{
    // std::vector<int> nums = {1, 7, 3, 6, 5, 6};
    std::vector<int> nums = {0, 1};
    auto ans = pivotIndex(nums);
    return 0;
}