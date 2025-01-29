#include <vector>

void permuteHelper(std::vector<int>& nums, std::vector<bool>& visited, std::vector<int>& temp,
                   std::vector<std::vector<int>>& ans)
{
  if (temp.size() == nums.size())
  {
    ans.push_back(temp);
    return;
  }

  for (int i = 0; i < nums.size(); i++)
  {
    if (!visited[i])
    {
      temp.push_back(nums[i]);
      visited[i] = true;
      permuteHelper(nums, visited, temp, ans);
      temp.pop_back();
      visited[i] = false;
    }
  }
}

std::vector<std::vector<int>> permute(std::vector<int>& nums)
{
  std::vector<std::vector<int>> ans;
  std::vector<int> temp;
  std::vector<bool> visited(nums.size(), false);

  permuteHelper(nums, visited, temp, ans);
  return ans;
}

int main()
{
  std::vector<int> nums = {  };
  auto ans = permute(nums);
  return 0;
}