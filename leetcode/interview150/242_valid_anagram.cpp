#include <map>
#include <vector>
#include <string>
bool isAnagram(std::string s, std::string t)
{
  if (s.size() != t.size())
    return false;
  std::map<char, int> s_map;
  std::map<char, int> t_map;
  for (auto x : s)
    s_map[x]++;
  for (auto x : t)
    t_map[x]++;

  for (auto x : s_map)
  {
    if (t_map[x.first] != x.second)
      return false;
  }

  return true;
}
int main()
{
  std::string s = "anagram";
  std::string t = "nagaram";
  bool ans = isAnagram(s, t);
  return 0;
}