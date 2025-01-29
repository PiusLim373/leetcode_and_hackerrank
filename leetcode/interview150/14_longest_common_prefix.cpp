#include <vector>
#include <string>

std::string longestCommonPrefix(std::vector<std::string>& strs)
{
  if (!strs.size())
    return "";
  if (strs.size() == 1)
    return strs[0];
  bool ended = false;
  std::string ans;
  std::string shortest = "";
  int shortest_size = 999;
  for (auto x : strs)
  {
    if (x.size() <= shortest_size)
    {
      shortest = x;
      shortest_size = x.size();
    }
  }
  for (int i = 0; i < shortest.size(); i++)
  {
    char check = shortest[i];
    for (auto x : strs)
    {
      if (x[i] != check)
      {
        return ans;
      }
    }
    ans += check;
  }
  return ans;
}
int main()
{
  std::vector<std::string> strs = { "dog", "racecar", "car" };
  auto ans = longestCommonPrefix(strs);
  return 0;
}