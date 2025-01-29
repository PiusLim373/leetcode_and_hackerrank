#include <map>
#include <vector>
#include <string>

std::vector<int> findSubstring(std::string s, std::vector<std::string>& words)
{
  std::map<std::string, int> words_map;
  for (auto x : words)
    words_map[x]++;

  std::map<std::string, int> fre_map;
  std::vector<int> ans = {};

  int n = words.size();
  int word_size = words[0].size();
  int window_size = word_size * words.size();
  for (int start_pos = 0; start_pos < word_size; ++start_pos)
  {
    int start = start_pos;
    do
    {
      fre_map = words_map;
      bool matched = true;
      std::string temp_str;
      for (int i = 0; i < n; ++i)
      {
        temp_str = s.substr(start + i * word_size, word_size);
        if (!fre_map.count(temp_str) || fre_map[temp_str] == 0)
        {
          matched = false;
          break;
        }
        fre_map[temp_str]--;
      }
      if (matched)
        ans.push_back(start);
      start += word_size;
    } while (start + window_size - 1 < s.size());
  }

  return ans;
}

int main()
{
  std::string s = "barfoothefoobarman";
  std::vector<std::string> words = { "foo", "bar" };
  auto ans = findSubstring(s, words);
  return 0;
}