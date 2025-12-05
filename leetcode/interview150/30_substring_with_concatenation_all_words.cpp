#include <unordered_map>
#include <map>
#include <vector>
#include <string>
#include <iostream>
std::vector<int> findSubstring(std::string s, std::vector<std::string> &words)
{
  std::vector<int> ans;
  if (!s.size() || !words.size())
    return ans;

  int word_size = words[0].size();
  if (s.size() < word_size * words.size())
    return {};

  std::unordered_map<std::string, int> m;
  for (auto w : words)
    m[w]++;

  for (int offset = 0; offset < word_size; offset++)
  {
    std::unordered_map<std::string, int> window;
    int start = offset;
    int match_count = 0;

    for (int right = offset; right + word_size <= s.size(); right += word_size)
    {
      std::string curr_str = s.substr(right, word_size);
      if (!m.count(curr_str))
      {
        // not valid sub string
        window.clear();
        match_count = 0;
        start = right + word_size;
        continue;
      }
      match_count++;
      window[curr_str]++;

      while (window[curr_str] > m[curr_str])
      {
        std::string prev_str = s.substr(start, word_size);
        match_count--;
        window[prev_str]--;
        start += word_size;
      }
      if (match_count == words.size())
        ans.push_back(start);
    }
  }
  return ans;
}

std::vector<int> findSubstringTLE(std::string s, std::vector<std::string> &words)
{
  std::unordered_map<std::string, int> m;
  int total_word = words.size();
  for (auto w : words)
    m[w]++;

  std::vector<int> ans;
  int word_size = words[0].size();
  if (s.size() < word_size)
    return {};
  for (int offset = 0; offset < word_size; offset++)
  {
    int start = offset;
    // std::cout << "starting: " << s[left] << std::endl;
    while (s.size() - start >= total_word * word_size)
    {
      std::unordered_map<std::string, int> curr_m = m;
      bool success = true;
      for (int i = 0; i < total_word; i++)
      {
        std::string curr_str = s.substr(start + i * word_size, word_size);
        std::cout << "testing: " << curr_str << std::endl;
        if (!curr_m.count(curr_str) || curr_m[curr_str] == 0)
        {
          std::cout << curr_str << " failed!" << std::endl;
          success = false;
          break;
        }
        curr_m[curr_str]--;
      }
      if (success)
      {
        std::cout << "success! " << start << std::endl;
        ans.push_back(start);
      }
      start += word_size;
    }
  }
  return ans;
}

int main()
{
  // std::string s = "barfoothefoobarman";
  // std::vector<std::string> words = { "foo", "bar" };
  // std::string s = "barfoofoobarthefoobarman";
  // std::vector<std::string> words = {"bar", "foo", "the"};

  std::string s = "wordgoodgoodgoodbestword";
  std::vector<std::string> words = {"word", "good", "best", "good"};

  auto ans = findSubstring(s, words);
  return 0;
}