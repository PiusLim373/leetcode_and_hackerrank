#include <bits/stdc++.h>
using namespace std;
void recursive_perm(vector<int> &nums, int left, int right, vector<vector<int>> &result)
{
    if (left == right)
    {
        result.push_back(nums);
        return;
    }
    for (int i = left; i <= right; i++)
    {
        swap(nums[left], nums[i]);
        recursive_perm(nums, left + 1, right, result);
        swap(nums[left], nums[i]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> sol;
    recursive_perm(nums, 0, nums.size() - 1, sol);
    return sol;
}
int main()
{
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> sol = permute(nums);
    for (auto x : sol)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}