#include <string>
std::string longestPalindrome(std::string s)
{
  std::string ans;
  int longest = -1;
  for (int i = 0; i < s.size(); i++)
  {
    int left = i;
    int right = i;
    while (left >= 0 && right <= s.size() - 1 && s[left] == s[right])
    {
      int length = right - left + 1;
      if (length > longest)

      {
        longest = length;
        ans = s.substr(left, length);
      }
      left--;
      right++;
    }

    left = i;
    right = i + 1;
    while (left >= 0 && right <= s.size() - 1 && s[left] == s[right])
    {
      int length = right - left + 1;
      if (length > longest)

      {
        longest = length;
        ans = s.substr(left, length);
      }
      left--;
      right++;
    }
  }
  return ans;
}
int main()
{
  std::string s = "aa";
  std::string ans = longestPalindrome(s);
  return 0;
}