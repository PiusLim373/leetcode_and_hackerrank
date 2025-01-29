#include <string>
#include <algorithm>

std::string reverseWords(std::string s)
{
  // remove space everything
  int write = 0;
  bool encountered_word = false;
  bool space_encountered = false;
  for (auto read = 0; read < s.size(); read++)
  {
    if (s[read] != ' ')
    {
      encountered_word = true;
      space_encountered = false;
    }
    if (encountered_word)
    {
      if (s[read] == ' ')
      {
        if (space_encountered)
          continue;
        space_encountered = true;
      }
      s[write++] = s[read];
    }
  }

  s.resize(write);
  if (s[s.size() - 1] == ' ')
    s.resize(s.size() - 1);

  std::reverse(s.begin(), s.end());
  int left = 0;
  int right = 0;
  while (right < s.size())
  {
    if (s[right] != ' ')
    {
      right++;
    }
    else
    {
      std::reverse(s.begin() + left, s.begin() + right);
      right++;
      left = right;
    }
  }
  std::reverse(s.begin() + left, s.begin() + right);
  return s;
}

int main()
{
  std::string s = "     ";
  auto ans = reverseWords(s);
  return 0;
}