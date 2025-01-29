#include <iostream>
#include <vector>

int searchInsert_longer(std::vector<int>& nums, int target)
{
  if (!nums.size())
    return 0;
  int start = 0;
  int end = nums.size() - 1;

  if (target > nums[end])
    return end + 1;
  if (target < nums[start])
    return 0;

  while (end >= start)
  {
    if (target == nums[start])
      return start;
    if (target == nums[end])
      return end;
    if ((end - start == 1))
      return start + 1;
    int mid = (end + start) / 2;
    if (target == nums[mid])
      return mid;
    if (target > nums[mid])
      start = mid;
    else
      end = mid;
  }
  std::cout << "shouldnt reach here" << std::endl;
  return -1;
}

int searchInsert(std::vector<int>& nums, int target)
{
  int high = nums.size() - 1;
  int low = 0;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (nums[mid] == target)
      return mid;
    else if (target > nums[mid])
      low = mid + 1;
    else
      high = mid - 1;
  }
  return low;
}

int main()
{
  std::vector<int> nums = { 1 };
  //   std::vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 10 };
  int target = 1;
  std::cout << searchInsert(nums, target);
  return 0;
}