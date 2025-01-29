#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    map<int, int> index_map;
    index_map[numbers[0]] = 0;

    for (int i = 1; i < numbers.size(); i++)
    {
        int diff = target - numbers[i];
        if (index_map.count(diff))
        {
            return {index_map[diff] + 1, i + 1};
        }
        else
        {
            index_map[numbers[i]] = i;
        }
    }
    return {-1, -1};

    // int left = 0;
    // int right = numbers.size() - 1;

    // while (left <= right)
    // {
    //     int sum = numbers[left] + numbers[right];
    //     if (sum == target)
    //         return {left + 1, right + 1};
    //     else if (sum < target)
    //         left++;
    //     else if (sum > target)
    //         right--;
    // }
    // return {-1, -1};
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    //{}
    int target = 26;
    for (auto x : twoSum(nums, target))
        cout << x << " ";
}