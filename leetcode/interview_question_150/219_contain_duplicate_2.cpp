#include <vector>
#include <map>
bool containsNearbyDuplicate(std::vector<int>& nums, int k)
{
  std::map<int, int> map;
  for (int i = 0; i < nums.size(); i++)
  {
    if (!map.count(nums[i]))
    {
      map[nums[i]] = i;
    }
    else
    {
      if (i - map[nums[i]] <= k)
        return true;
      map[nums[i]] = i;
    }
  }
  return false;
}

int main()
{
  std::vector<int> nums = { 1, 0, 1, 1 };
  int k = 1;
  bool ans = containsNearbyDuplicate(nums, k);
  return 0;
}