#include <vector>
#include <set>
#include <algorithm>

int lengthOfLIS(std::vector<int>& nums)
{
  std::vector<int> ans;
  for (auto x: nums)
  {
    if (!ans.size()) ans.push_back(x);
    else
    {
      if (x > ans[ans.size() - 1])
        ans.push_back(x);
      else
      {
        auto it = std::lower_bound(ans.begin(), ans.end(), x);
        *it = x;
      }
    }
  }
  return ans.size();
}

int lengthOfLIS_N_Square(std::vector<int>& nums)
{
  std::vector<int> lis(nums.size(), 1);

  for (int i = nums.size() - 1; i >= 0; i--)
  {
    for (int j = i + 1; j < nums.size(); j++)
    {
      if (nums[i] < nums[j])
        lis[i] = std::max(lis[i], 1+lis[j]);
    }
  }
  return *std::max_element(lis.begin(), lis.end());
}
int main()
{
  std::vector<int> nums = { 10, 9, 2, 5, 3, 7, 101, 18 };
  int ans = lengthOfLIS(nums);
  return 0;
}
