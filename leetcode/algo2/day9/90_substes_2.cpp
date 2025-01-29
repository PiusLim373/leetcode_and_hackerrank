#include <vector>
#include <iostream>
#include <algorithm>
std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums)
{
    std::vector<std::vector<int>> res = {{}};
    std::sort(nums.begin(), nums.end());
    int start;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i == 0 || nums[i] != nums[i - 1])
            start = 0;
        for (int end = res.size(); start < end; start++)
        {
            std::vector<int> temp = res[start];
            temp.push_back(nums[i]);
            res.push_back(temp);
        }
    }
    return res;
}
int main()
{

    // std::vector<int> nums = {1, 2, 2};
    std::vector<int> nums = {3, 3, 5, 9, 9};
    for (auto x : subsetsWithDup(nums))
    {
        for (auto y : x)
            std::cout << y << " ";
        std::cout << std::endl;
    }
}