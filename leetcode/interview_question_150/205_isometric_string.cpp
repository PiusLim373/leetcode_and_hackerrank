#include <string>
#include <map>
#include <iostream>

bool isIsomorphic(std::string s, std::string t)
{
  std::map<char, char> conversion;
  for (int i = 0; i < s.size(); i++)
  {
    if (conversion[s[i]] == '\0')
    {
      conversion[s[i]] = t[i];
    }
    else if (conversion[s[i]] != t[i])
    {
      return false;
    }
  }

  std::map<char, char> back_conversion;
  for (int i = 0; i < s.size(); i++)
  {
    if (back_conversion[t[i]] == '\0')
    {
      back_conversion[t[i]] = s[i];
    }
    else if (back_conversion[t[i]] != s[i])
    {
      return false;
    }
  }
  return true;
}

int main()
{
  //   std::string s = "paper";
  //   std::string t = "title";
  //   std::string s = "bbbaaaba";
  //   std::string t = "aaabbbba";

  std::string s = "badc";
  std::string t = "baba";
  bool ans = isIsomorphic(s, t);
  std::cout << ans;
  return 0;
}