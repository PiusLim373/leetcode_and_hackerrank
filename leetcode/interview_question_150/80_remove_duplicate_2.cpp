#include <vector>
#include <iostream>

int removeDuplicates(std::vector<int>& nums)
{
  int left = 0;
  int right = 0;

  while (right < nums.size())
  {
    
  }

  //   for (int right = 1; right < nums.size(); right++)
  //   {
  //     if (nums[right] == prev)
  //     {
  //       encounter_counter++;
  //       if (encounter_counter > 2)
  //       {
  //         while (nums[right] == prev)
  //           right++;
  //         nums[left] = nums[right];
  //         prev = nums[right];
  //         encounter_counter = 1;
  //       }
  //       else
  //       {
  //         left++;
  //       }
  //     }
  //     else
  //     {
  //       prev = nums[right];
  //       left++;
  //     }
  //   }
  //   return left;
}
int removeDuplicatesNotInPlace(std::vector<int>& nums)
{
  if (nums.size() == 0 || nums.size() == 1)
  {
    return nums.size();
  }
  std::vector<int> temp;
  int last_num = nums[0];
  temp.push_back(last_num);
  int frequency = 1;
  int unique_counter = 1;
  for (int i = 1; i < nums.size(); i++)
  {
    if (last_num == nums[i])
    {
      frequency++;
      if (frequency >= 3)
      {
        // need to remove this element
      }
      else
      {
        temp.push_back(last_num);
        unique_counter++;
      }
    }
    else
    {
      frequency = 1;
      unique_counter++;
      temp.push_back(nums[i]);
    }
    last_num = nums[i];
  }
  nums = temp;
  return unique_counter;
}
int main()
{
  std::vector<int> nums = { 1, 1, 1, 2, 2, 3 };
  int k = removeDuplicates(nums);
  std::cout << k << std::endl;
  for (auto x : nums)
    std::cout << x << " ";
}