#include <iostream>
#include <vector>
#include <map>

void recv(std::vector<std::string>& ans, std::string curr_str, int index, std::map<char, std::string>& key,
          std::string digits)
{
  if (curr_str.size() == digits.size())
  {
    ans.push_back(curr_str);
    return;
  }

  for (auto x : key[digits[index]])
    recv(ans, curr_str + x, index + 1, key, digits);
}

std::vector<std::string> letterCombinations(std::string digits)
{
  if (digits == "")
    return {};
  std::vector<std::string> ans;
  std::map<char, std::string> key = { { '2', "abc" }, { '3', "def" },  { '4', "ghi" }, { '5', "jkl" },
                                      { '6', "mno" }, { '7', "pqrs" }, { '8', "tuv" }, { '9', "wxyz" } };
  recv(ans, "", 0, key, digits);
  return ans;
}

int main()
{
  std::string digits = "23";
  std::vector<std::string> ans = letterCombinations(digits);
  for (auto x : ans)
    std::cout << x << std::endl;
  return 0;
}