#include <string>
int lengthOfLastWord(std::string s)

{
  if (!s.size())
    return 0;
  int first_alpha = -1;
  for (int i = s.size() - 1; i >= 0; i--)
  {
    if (first_alpha == -1 && s[i] != ' ')
      first_alpha = i;
    if (s[i] == ' ' && first_alpha != -1)
    {
      return first_alpha - i;
    }
  }
  if (first_alpha != -1)
    return first_alpha + 1;
  return s.size();
}
int main()
{
  std::string s = " fdddd";
  auto ans = lengthOfLastWord(s);
  return 0;
}