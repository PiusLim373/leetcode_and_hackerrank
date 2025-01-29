#include <bits/stdc++.h>
using namespace std;
// int rob(vector<int> &nums)
// {
// int money = 0;
// vector<int> selected;
// map<int, set<int>> index_map;
// for (int i = 0; i < nums.size(); i++)
//     index_map[nums[i]].insert(i);
// for (auto it = index_map.rbegin(); it != index_map.rend(); it++)
// {
//     if(!selected.size()) selected.push_back(it->second[0]);
//     for(auto x: selected) if(abs(it->second -x)  )
// }

// return 0;}
int rob(vector<int> &nums)
{
    int rob1 = 0;
    int rob2 = 0;
    for (auto x : nums)
    {
        int temp = max(x + rob1, rob2);
        rob1 = rob2;
        rob2 = temp;
    }
    return rob2;
}

int main()
{
    vector<int> nums = {1, 2, 3, 1};

    int sol = rob(nums);
    cout << sol << endl;
}