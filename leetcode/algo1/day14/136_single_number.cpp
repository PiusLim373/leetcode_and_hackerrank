#include <bits/stdc++.h>
using namespace std;

// method 1: O(n) time and O(n) space
int singleNumber2(vector<int> &nums)
{
    map<int, int> fre_map;
    for (auto x : nums)
    {
        fre_map[x]++;
        if (fre_map[x] == 2)
            fre_map.erase(x);
    }
    for (auto x : fre_map)
        return x.first;
    return -1;
}

// method 2: O(nlogn) time and O(1) space
// sort then check if 2 same is adjacent

// method 3: O(n) time and O(1) space
// bitwise xor, ie: if 2 items appear even time, will cancel out each other
int singleNumber(vector<int> &nums)
{
    int ans = 0;
    for (auto x : nums)
        ans ^= x;
    return ans;
}

// method 4: O(n) time and O(1) space
// sumtotal *2 and minus the rest
int main()
{
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << singleNumber(nums) << endl;
}