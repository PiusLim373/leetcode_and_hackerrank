#include <vector>
std::vector<int> productExceptSelf(std::vector<int>& nums)
{
  
  std::vector<int> pre(nums.size());
  std::vector<int> post(nums.size());
  int prev = 1;
  for (int i = 0; i < nums.size(); i++)
  {
    pre[i] = prev * nums[i];
    prev = pre[i];
  }

  prev = 1;
  for (int i = nums.size() - 1; i >= 0; i--)
  {
    post[i] = prev * nums[i];
    prev = post[i];
  }

  std::vector<int> ans(nums.size());
  for (int i = 0; i < nums.size(); i++)
  {
    if (i == 0)
      ans[i] = post[1];
    else if (i == nums.size() - 1)
      ans[i] = pre[nums.size() - 2];
    else
      ans[i] = pre[i - 1] * post[i + 1];
  }
  return ans;
}
int main()
{
  std::vector<int> nums = { 1, 2 };
  auto ans = productExceptSelf(nums);
  return 0;
}