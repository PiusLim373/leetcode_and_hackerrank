#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
int longestConsecutive(std::vector<int>& nums)
{
  if (!nums.size())
    return 0;
  std::map<int, int> map;
  for (auto x : nums)
    map[x]++;

  int max_count = 0;
  int count = 1;
  bool start = true;
  int prev;
  for (auto x : map)
  {
    if (start)
    {
      start = false;
      prev = x.first;
    }
    else
    {
      if (x.first - prev == 1)
      {
        count++;
        prev = x.first;
      }
      else
      {
        max_count = std::max(count, max_count);
        count = 1;
        prev = x.first;
      }
    }
  }
  if (count == 1)
    return 0;
  max_count = std::max(count, max_count);
  return max_count;
}
int main()
{
  std::vector<int> nums = { 9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6 };
  std::cout << longestConsecutive(nums);
}