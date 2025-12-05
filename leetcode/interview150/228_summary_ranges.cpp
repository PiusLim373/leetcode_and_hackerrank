#include <string>
#include <vector>
std::vector<std::string> summaryRanges(std::vector<int> &nums)
{
    if (nums.size() == 0)
        return {};
    if (nums.size() == 1)
        return {std::to_string(nums[0])};

    std::vector<std::string> ans;
    int start = nums[0];
    int prev = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if ((long long)nums[i] - prev > 1)
        {
            if (start == prev)
                ans.push_back(std::to_string(prev));
            else
            {
                std::string temp = std::to_string(start) + "->" + std::to_string(prev);
                ans.push_back(temp);
            }
            start = nums[i];
            prev = nums[i];
        }
        else
        {
            prev = nums[i];
        }
    }

    if (start == prev)
        ans.push_back(std::to_string(prev));
    else
    {
        std::string temp = std::to_string(start) + "->" + std::to_string(prev);
        ans.push_back(temp);
    }
    return ans;
}
int main()
{
    // std::vector<int> nums = {0, 2, 3, 4, 6, 8, 9};
    // std::vector<int> nums = {0, 1, 2, 4, 5, 7};
    std::vector<int> nums = {-2147483648,0,2,3,4,6,8,9};
    auto ans = summaryRanges(nums);
    return 0;
}