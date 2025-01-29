#include <vector>
#include <iostream>

void search(std::vector<int> &candidates, int pointer, int &target, std::vector<int> temp, int temp_sum, std::vector<std::vector<int>> &res)
{
    if (temp_sum == target)
    {
        res.push_back(temp);
        return;
    }
    if (pointer >= candidates.size() || temp_sum > target)
        return;
    temp.push_back(candidates[pointer]);
    search(candidates, pointer, target, temp, temp_sum + candidates[pointer], res);
    temp.pop_back();
    search(candidates, pointer + 1, target, temp, temp_sum, res);
}

std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target)
{
    int pointer = 0;
    std::vector<int> temp = {};
    int temp_sum = 0;
    std::vector<std::vector<int>> res;
    search(candidates, pointer, target, temp, temp_sum, res);
    return res;
}

int main()
{
    std::vector<int> nums = {2, 3, 6, 7};
    int target = 6;
    for (auto x : combinationSum(nums, target))
    {
        for (auto y : x)
            std::cout << y << " ";
        std::cout << std::endl;
    }
}