#include <iostream>
#include <vector>

int findPeakElement(std::vector<int>& nums)
{
  if (nums.size() == 1)
    return 0;
  if (nums.size() == 2)
  {
    if (nums[0] > nums[1])
      return 0;
    return 1;
  }

  int low = 0;
  int high = nums.size() - 1;
  while (high >= low)
  {
    int mid = low + (high - low) / 2;
    bool left_ok = false;
    if((mid - 1) < 0 || nums[mid] > nums[mid - 1])
        left_ok = true;
    bool right_ok = false;
    if ((mid + 1) > nums.size() - 1 || nums[mid] > nums[mid + 1])
        right_ok = true;
        
    if (left_ok && right_ok)
      return mid;
    else if (nums[mid] < nums[mid + 1])
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}
int main()
{
//   std::vector<int> nums = { 1, 2, 1, 3, 5, 6, 4 };
  std::vector<int> nums = { 6,5,4,3,2,3,2 };
  std::cout << findPeakElement(nums);
  return 0;
}