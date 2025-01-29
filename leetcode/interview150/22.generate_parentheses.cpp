#include <vector>
#include <string>
#include <iostream>
void generateParenthesisHelper(std::string curr, std::vector<std::string>& ans, int open, int close, int& pair)
{
  if (curr.size() == 2 * pair)
  {
    ans.push_back(curr);
    return;
  }

  if (open == pair)  // can choose only close
  {
    curr += ")";
    generateParenthesisHelper(curr, ans, open, close + 1, pair);
  }
  else if (open > close)  // can choose to open or close
  {
    curr += "(";
    generateParenthesisHelper(curr, ans, open + 1, close, pair);
    curr.pop_back();
    curr += ")";
    generateParenthesisHelper(curr, ans, open, close + 1, pair);
  }
  else if (open == close)  // can only choose open
  {
    curr += "(";
    generateParenthesisHelper(curr, ans, open + 1, close, pair);
  }
  else
    std::cout << "i shouldnt reach here";
}
std::vector<std::string> generateParenthesis(int n)
{
  if (n == 0)
    return {};
  std::vector<std::string> ans;
  std::string curr = "";
  generateParenthesisHelper(curr, ans, 0, 0, n);
  return ans;
}
int main()
{
  int n = 8;
  auto ans = generateParenthesis(n);
  return 0;
}