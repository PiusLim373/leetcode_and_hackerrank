#include <vector>

void combineHelper(int n, int k, int start, std::vector<int>& temp, std::vector<std::vector<int>>& ans)
{
  if (temp.size() >= k)
  {
    ans.push_back(temp);
    return;
  }
  for (int i = start; i <= n; i++)
  {
    temp.push_back(i);
    combineHelper(n, k, i + 1, temp, ans);
    temp.pop_back();
  }
}

std::vector<std::vector<int>> combine(int n, int k)
{
  std::vector<std::vector<int>> ans;
  std::vector<int> temp;
  combineHelper(n, k, 1, temp, ans);

  return ans;
}

int main()
{
  int n = 4, k = 0;
  auto ans = combine(n, k);
  return 0;
}