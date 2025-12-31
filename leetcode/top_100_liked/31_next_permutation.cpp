#include <vector>
#include <unordered_map>
#include <algorithm>

void recv(int size, std::vector<std::vector<int>> &ans, std::vector<int> &curr, std::unordered_map<int, bool> &used_map)
{
    if (curr.size() == size)
    {
        ans.push_back(curr);
        return;
    }

    for (auto x : used_map)
    {
        if (!x.second)
        {
            used_map[x.first] = true;
            curr.push_back(x.first);
            recv(size, ans, curr, used_map);
            curr.pop_back();
            used_map[x.first] = false;
        }
    }
}

std::vector<std::vector<int>> generatePermutation(std::vector<int> &nums)
{
    std::vector<std::vector<int>> ans;
    std::unordered_map<int, bool> used_map;
    for (auto n : nums)
        used_map[n] = false;
    std::vector<int> curr;
    recv(nums.size(), ans, curr, used_map);
    return ans;
}

void nextPermutation(std::vector<int> &nums)
{
    if (nums.size() == 2)
    {
        std::swap(nums[0], nums[1]);
        return;
    }

    // find first descreasing position
    int curr = nums[nums.size() - 1];
    int decrease_pos = -1;
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (nums[i] < curr)
        {
            decrease_pos = i;
            break;
        }
        curr = nums[i];
    }

    if (decrease_pos == -1)
    {
        std::sort(nums.begin(), nums.end());
        return;
    }

    // find next highest num in remaining
    int swap_pos = -1;
    int diff = 100;
    curr = nums[decrease_pos];
    for (int i = decrease_pos + 1; i < nums.size(); i++)
    {
        if (nums[i] > curr)
        {
            int curr_diff = nums[i] - curr;
            if (curr_diff < diff)
            {
                diff = curr_diff;
                swap_pos = i;
            }
        }
    }

    // swap the first descreasing pos and next highest
    std::swap(nums[decrease_pos], nums[swap_pos]);

    // sort the remaining in acending order
    std::sort(nums.begin() + decrease_pos + 1, nums.end());

    return;
}

int main()
{
    // std::vector<int> nums = {1, 1, 5, 4, 1};
    std::vector<int> nums = {3, 2, 1};
    // auto perms = generatePermutation(nums);
    nextPermutation(nums);

    return 0;
}