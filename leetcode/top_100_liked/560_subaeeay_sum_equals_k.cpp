#include <vector>
#include <unordered_map>
int subarraySum(std::vector<int> &nums, int k)
{
    std::unordered_map<int, int> fre;
    fre[0] = 1;
    int prefix = 0;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        prefix += nums[i];
        int check = prefix - k;
        if (fre.count(check))
            ans += fre[check];
        fre[prefix]++;
    }
    return ans;
}
int subarraySumNotWorking(std::vector<int> &nums, int k)
{
    std::vector<int> prefix_sum = {0};
    int temp = 0;
    for (auto x : nums)
    {
        temp += x;
        prefix_sum.push_back(temp);
    }

    std::unordered_map<int, int> hashtable;
    for (int i = 0; i < prefix_sum.size(); i++)
    {
        hashtable[prefix_sum[i]] = i;   // bugged becoz compile the full hashtable here will record latest prefix sum, but ans += prefix_sum fre must before current index 
    }

    int ans = 0;
    for (int i = 1; i < prefix_sum.size(); i++)
    {
        int check = prefix_sum[i] - k;
        if (hashtable.count(check) && hashtable[check] < i)
            ans++;
    }
    return ans;
}

int main()
{
    // std::vector<int> nums = {9, 5, 1, 3, 5, 4, 5, 5};
    std::vector<int> nums = {-1, -1, 1};
    int k = 0;
    auto ans = subarraySum(nums, k);
    return 0;
}