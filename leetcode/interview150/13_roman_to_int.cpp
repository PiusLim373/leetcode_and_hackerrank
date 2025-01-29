#include <map>
#include <string>
#include <iostream>

int romanToInt(std::string s)
{
  std::map<char, int> dict;
  dict['I'] = 1;
  dict['V'] = 5;
  dict['X'] = 10;
  dict['L'] = 50;
  dict['C'] = 100;
  dict['D'] = 500;
  dict['M'] = 1000;

  int ans = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == 'I' && i + 1 < s.size() && s[i + 1] == 'V')
    {
      ans += 4;
      i++;
    }
    else if (s[i] == 'I' && i + 1 < s.size() && s[i + 1] == 'X')
    {
      ans += 9;
      i++;
    }
    else if (s[i] == 'X' && i + 1 < s.size() && s[i + 1] == 'L')
    {
      ans += 40;
      i++;
    }
    else if (s[i] == 'X' && i + 1 < s.size() && s[i + 1] == 'C')
    {
      ans += 90;
      i++;
    }
    else if (s[i] == 'C' && i + 1 < s.size() && s[i + 1] == 'D')
    {
      ans += 400;
      i++;
    }
    else if (s[i] == 'C' && i + 1 < s.size() && s[i + 1] == 'M')
    {
      ans += 900;
      i++;
    }
    else
    {
      std::cout << dict[s[i]] << std::endl;
      ans += dict[s[i]];
    }
  }
  return ans;
}
int main()
{
  std::string s = "MCMXCIV";
  auto ans = romanToInt(s);
  return 0;
}