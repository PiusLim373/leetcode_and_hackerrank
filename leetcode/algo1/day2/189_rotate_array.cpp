#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> nums, int k)
{

    // vector<int> temp;
    // int fre = k % nums.size();
    // while (fre--)
    // {
    //     temp.push_back(nums[nums.size() - 1]);
    //     nums.pop_back();
    // }
    // reverse(temp.begin(), temp.end());
    // nums.insert(nums.begin(), temp.begin(), temp.end());
    // for (auto x : nums)
    //     cout << x << " ";

    // best solution
    rotate(nums.rbegin(), nums.rbegin() + k % nums.size(), nums.rend());
    for (auto x : nums)
        cout << x << " ";
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 10;
    rotate(nums, k);
}