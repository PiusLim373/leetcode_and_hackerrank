#include <vector>
#include <algorithm>

int maxOperations(std::vector<int> &nums, int k)
{
    if (nums.size() == 1)
    {
        if (nums[0] == k)
            return 1;
        return 0;
    }
    std::sort(nums.begin(), nums.end());
    int left = 0;
    int right = nums.size() - 1;
    int count = 0;
    while (left < right)
    {
        int sum = nums[left] + nums[right];
        if (sum == k)
        {
            left++;
            right--;
            count++;
        }
        else if (sum < k)
            left++;
        else
            right--;
    }

    return count;
}
int main()
{
    std::vector<int> nums = {5};
    // std::vector<int> nums = {3, 1, 3, 4, 3}; // 1,3,3,3,4
    int k = 5;

    auto ans = maxOperations(nums, k);
    return 1;
}