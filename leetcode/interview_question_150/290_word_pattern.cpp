#include <vector>
#include <iostream>
#include <map>

bool wordPattern(std::string pattern, std::string s)
{
  std::map<char, std::string> pattern_to_s;
  std::map<std::string, char> s_to_pattern;
  std::string buffer;
  int pattern_index = 0;
  for (int i = 0; i < s.size() + 1; i++)
  {
    if (i != s.size() && s[i] != ' ')
      buffer += s[i];
    else
    {
      if ((s_to_pattern[buffer] != '\0' && s_to_pattern[buffer] != pattern[pattern_index]) ||
          (pattern_to_s[pattern[pattern_index]] != "" && pattern_to_s[pattern[pattern_index]] != buffer))
      {
        return false;
      }
      s_to_pattern[buffer] = pattern[pattern_index];
      pattern_to_s[pattern[pattern_index]] = buffer;
      pattern_index++;
      buffer = "";
    }
  }
  if (pattern_index != pattern.size())
    return false;
  return true;
}
int main()
{
  std::string pattern = "ab", s = "jquery";
  std::cout << wordPattern(pattern, s);
}