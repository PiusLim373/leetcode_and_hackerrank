#include <bits/stdc++.h>
using namespace std;
void moveZeroes(vector<int> &nums)
{
    vector<int> temp(nums.size(), 0);
    int temp_counter = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
            temp[temp_counter++] = nums[i];
    }
    nums = temp;
}

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);
    for (auto x : nums)
        cout << x << " ";
}