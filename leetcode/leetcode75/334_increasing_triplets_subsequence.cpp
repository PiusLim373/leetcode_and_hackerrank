#include <vector>
bool increasingTriplet(std::vector<int> &nums)
{
    std::vector<int> subsequence = {nums[0]};
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > subsequence[subsequence.size() - 1])
            subsequence.push_back(nums[i]); // 1, 8,
        else
        {
            auto it = std::lower_bound(subsequence.begin(), subsequence.end(), nums[i]);
            *it = nums[i];
        }
        if (subsequence.size() >= 3)
            return true;
    }
    return false;
}

int main()
{

    std::vector<int> nums = {1};
    auto ans = increasingTriplet(nums);
    return 1;
}