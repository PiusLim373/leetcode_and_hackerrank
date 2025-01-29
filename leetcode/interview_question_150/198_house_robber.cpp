#include <vector>
#include <algorithm>

int rob(std::vector<int>& nums)
{
  if (!nums.size())
    return 0;
  if (nums.size() == 1)
    return nums[0];
  int prev2 = 0;
  int prev1 = nums[0];

  for (int i = 1; i < nums.size(); i++)
  {
    int curr = std::max(prev2 + nums[i], prev1);
    prev2 = prev1;
    prev1 = curr;
  }

  return prev1;
}
int main()
{
//   std::vector<int> nums = { 1, 2, 3, 1 };
  std::vector<int> nums = { 100, 2, 3, 300, 300, 300 };
  int ans = rob(nums);
  return 0;
}