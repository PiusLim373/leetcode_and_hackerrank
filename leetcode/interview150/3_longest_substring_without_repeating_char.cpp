#include <map>
#include <string>
int lengthOfLongestSubstring(std::string s)
{
  if (s.size() == 0 || s.size() == 1)
    return s.size();
  std::map<char, bool> map;
  int left = 0;
  int right = 0;
  int longest = 0;

  while (right < s.size())
  {
    if (!map[s[right]])
    {
      map[s[right]] = true;
    }
    else
    {
      // found the previously saw char
      int length = right - left;
      longest = std::max(longest, length);
      while (map[s[right]])
      {
        map[s[left]] = false;
        left++;
      }
      map[s[right]] = true;
    }
    right++;
  }

  int length = right - left;
  longest = std::max(longest, length);

  return longest;
}

int main()
{
  std::string s = "pwwkew";
  auto ans = lengthOfLongestSubstring(s);
  return 0;
}