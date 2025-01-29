#include <vector>
#include <iostream>
#include <set>
// bit mask, review this
// std::vector<std::vector<int>> subsets(std::vector<int> &nums)
// {
//     std::vector<std::vector<int>> res;
//     std::vector<bool> bit_mask(nums.size(), false);
//     int mask = 1;
//     int loop = nums.size();
//     while (loop--)
//     {
//         std::cout << mask << std::endl;
//         mask = mask << 1;
//         std::vector<std::vector<int>> subs(mask);
//     }
//     return res;
// }

// iterative
std::vector<std::vector<int>> subsets(std::vector<int> &nums)
{
    std::vector<std::vector<int>> res = {{}};

    for (int i = 0; i < nums.size(); i++)
    {
        int res_size = res.size();
        for (int j = 0; j < res_size; j++)
        {
            std::vector<int> temp = res[j];
            temp.push_back(nums[i]);
            res.push_back(temp);
        }
    }
    return res;
}
int main()
{

    std::vector<int> nums = {1, 2, 3, 4};
    for (auto x : subsets(nums))
    {
        for (auto y : x)
            std::cout << y << " ";
        std::cout << std::endl;
    }
}