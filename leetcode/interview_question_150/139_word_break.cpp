#include <iostream>
#include <vector>
#include <map>
#include <string>

bool wordBreak(std::string s, std::vector<std::string>& wordDict)
{
  std::map<int, bool> dp;
  dp[s.size()] = true;

  for (int i = s.size(); i >= 0; i--)
  {
    for (auto x : wordDict)
    {
      if (i + x.size() <= s.size() && s.substr(i, x.size()) == x)
        dp[i] = dp[i + x.size()];
      if (dp[i])
        break;
    }
  }

  return dp[0];
}

int main()
{
  std::string s = "leetcode";
  std::vector<std::string> wordDict = { "leet", "code" };
  std::cout << wordBreak(s, wordDict);
  return 0;
}
