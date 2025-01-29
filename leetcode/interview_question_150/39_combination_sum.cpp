#include <vector>

void combinationSumHelper(std::vector<int>& candidates, int index, int target, std::vector<int>& temp,
                          std::vector<std::vector<int>>& ans)
{
  if (index >= candidates.size() || target < 0)
    return;
  if (target == 0)
  {
    ans.push_back(temp);
    return;
  }

  temp.push_back(candidates[index]);
  combinationSumHelper(candidates, index, target - candidates[index], temp, ans);
  temp.pop_back();
  combinationSumHelper(candidates, index + 1, target, temp, ans);
}

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target)
{
  if (target == 0 || !candidates.size())
    return {};
  std::vector<std::vector<int>> ans;
  std::vector<int> temp;
  combinationSumHelper(candidates, 0, target, temp, ans);
  return ans;
}
int main()
{
  int target = 1;
  std::vector<int> candidates = {};
  auto ans = combinationSum(candidates, target);
  return 0;
}