#include <iostream>
#include <vector>
#include <algorithm>
std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
{
  std::vector<std::vector<int>> return_data;
  std::sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size(); i++)
  {
    if (i > 0 && nums[i] == nums[i - 1])
      continue;
    int target = 0 - nums[i];
    int left = i + 1;
    int right = nums.size() - 1;
    while (left < right)
    {
      int temp_sum = nums[left] + nums[right];
      int last_left = nums[left];
      int last_right = nums[right];
      if (temp_sum == target)
      {
        std::vector<int> temp = { nums[i], nums[left], nums[right] };
        return_data.push_back(temp);
        do
        {
          left++;
        } while (nums[left] == last_left && left < right);
      }
      else if (temp_sum < target)
      {
        left++;
      }
      else
      {
        right--;
      }
    }
  }
  return return_data;
}
int main()
{
  std::vector<int> nums = { -1, 0, 1, 2, -1, -4 };
  for (auto x : threeSum(nums))
  {
    for (auto y : x)
      std::cout << y << ", ";
    std::cout << std::endl;
  }
  return 0;
}