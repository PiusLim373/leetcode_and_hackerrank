#include <vector>
#include <iostream>
#include <algorithm>
std::vector<std::vector<int>> res;

void search(std::vector<int> &candidates, int target, int pointer, std::vector<int> temp_arr, int temp_sum)
{
    if (temp_sum == target)
        res.push_back(temp_arr);
    if (temp_sum > target)
        return;
    int prev = -1;
    for (int i = pointer; i < candidates.size(); i++)
    {
        if (candidates[i] == prev)
            continue;
        temp_arr.push_back(candidates[i]);
        search(candidates, target, i + 1, temp_arr, temp_sum + candidates[i]);
        temp_arr.pop_back();
        prev = candidates[i];
    }
}

std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target)
{
    std::sort(candidates.begin(), candidates.end());
    std::vector<int> temp_arr;
    int temp_sum = 0;
    int pointer = 0;
    search(candidates, target, pointer, temp_arr, temp_sum);
    return res;
}
int main()
{
    std::vector<int> nums = {10, 1, 2, 7, 6, 1, 5, 8}; // 1,1,2,5,6,7,10
    int target = 8;
    for (auto x : combinationSum2(nums, target))
    {
        for (auto y : x)
            std::cout << y << " ";
        std::cout << std::endl;
    }
}