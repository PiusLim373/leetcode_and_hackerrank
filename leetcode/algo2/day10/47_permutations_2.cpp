#include <vector>
#include <iostream>
#include <map>

std::vector<std::vector<int>> res{};
std::map<int, int> fre;
std::vector<int> temp;
int target_length;

void dfs()
{
    if (temp.size() == target_length)
    {
        res.push_back(temp);
        return;
    }
    for (auto x : fre)
    {
        if (fre[x.first] > 0)
        {
            temp.push_back(x.first);
            fre[x.first]--;
            dfs();
            fre[x.first]++;
            temp.pop_back();
        }
    }
}
std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums)
{
    target_length = nums.size();
    for (auto x : nums)
        fre[x]++;
    dfs();
    return res;
}

int main()
{
    std::vector<int> nums = {1, 1, 2, 2};
    for (auto x : permuteUnique(nums))
    {
        for (auto y : x)
            std::cout << y << " ";
        std::cout << std::endl;
    }
}