#include <string>
#include <vector>
int strStr(std::string haystack, std::string needle)
{
  std::vector<int> search;
  for (int i = 0; i < haystack.size(); i++)
  {
    if (haystack[i] == needle[0])
      search.push_back(i);
  }
  if (!search.size())
    return -1;
  if (needle.size() == 1)
    return search[0];
  for (auto x : search)
  {
    std::string sub_str = haystack.substr(x, needle.size());
    if (sub_str == needle)
      return x;
  }
  return -1;
}
int strStrEdgeCaseNotWorking(std::string haystack, std::string needle)
{
  int hay_pointer = 0;
  int nee_pointer = 0;

  while (hay_pointer < haystack.size())
  {
    if (haystack[hay_pointer] == needle[nee_pointer])
    {
      nee_pointer++;

      if (nee_pointer >= needle.size())
        return hay_pointer - needle.size() + 1;
    }
    else
    {
      if (haystack[hay_pointer] == needle[0])
        nee_pointer = 1;
      else
        nee_pointer = 0;
    }
    hay_pointer++;
  }

  return -1;
}
int main()
{
  std::string haystack = "mississippi";
  std::string needle = "issip";
  int ans = strStr(haystack, needle);
  return 0;
}