#include <vector>
#include <unordered_set>

bool canPartition(std::vector<int> &nums)
{
    int sum = 0;
    for (auto x : nums)
        sum += x;
    if (sum % 2)
        return false;
    int target = sum / 2;

    std::unordered_set<int> s;
    s.insert(0);
    s.insert(nums[nums.size() - 1]);
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        std::vector<int> s_temp;
        for (auto x : s)
        {
            int temp = x + nums[i];
            if (temp == target)
                return true;
            s_temp.push_back(temp);
        }
        for (auto x : s_temp)
            s.insert(x);
    }
    return false;
}

int main()
{
    std::vector<int> nums = {1, 5, 11, 3};
    auto ans = canPartition(nums);
    return 0;
}