#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
{
  std::vector<std::vector<std::string>> res;
  if (strs.size() < 2)
  {
    res.push_back(strs);
    return res;
  }
  std::vector<std::string> sorted_vec = strs;
  for (std::string& str : sorted_vec)
    std::sort(str.begin(), str.end());

  std::map<std::string, std::vector<int>> index_map;
  for (int i = 0; i < sorted_vec.size(); i++)
    index_map[sorted_vec[i]].push_back(i);

  for (auto x: index_map)
  {
    std::vector<std::string> sub_res;
    for(auto index: x.second)
        sub_res.push_back(strs[index]);
    res.push_back(sub_res);
  }
  return res;
}
int main()
{
//   std::vector<std::string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
  std::vector<std::string> strs = { {"a"} };
  std::vector<std::vector<std::string>> res = groupAnagrams(strs);
  for (auto x : res)
  {
    for (auto y : x)
      std::cout << y << " ";
    std::cout << std::endl;
  }
}