#include <vector>

int firstMissingPositive(std::vector<int> &nums)
{
    int n = nums.size();
    int i = 0;
    while (i < nums.size())
    {
        if (nums[i] > 0 &&               // inbound
            nums[i] <= n &&              // inbound
            nums[i] != i + 1 &&          // not at correct place
            nums[nums[i] - 1] != nums[i] // duplicates no need swap, to escape keep swapping duplicated input and end up stuck in inifity
        )
            std::swap(nums[i], nums[nums[i] - 1]);
        else
            i++;
    }

    int missing = 1;
    for (auto x : nums)
    {
        if (x == missing)
        {
            missing++;
        }
    }
    return missing;
}
int main()
{
    // std::vector<int> nums = {100000, 3, 4000, 2, 15, 1, 99999};
    std::vector<int> nums = {2, 2};
    auto ans = firstMissingPositive(nums);
    return 0;
}