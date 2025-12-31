#include <string>
#include <vector>

bool isPalindrome(std::string &s)
{
    int left = 0, right = s.size() - 1;
    while (left < right)
    {
        if (s[left++] != s[right--])
            return false;
    }
    return true;
}

void recv(std::vector<std::vector<std::string>> &ans,
          std::vector<std::string> &curr,
          std::string &s,
          int index)
{
    if (index == s.size())
    {
        ans.push_back(curr);
        return;
    }
    for (int i = 1; index + i <= s.size(); i++)
    {
        std::string sub = s.substr(index, i);
        if (isPalindrome(sub))
        {
            curr.push_back(sub);
            recv(ans, curr, s, index + i);
            curr.pop_back();
        }
    }
}

std::vector<std::vector<std::string>> partition(std::string s)
{
    std::vector<std::vector<std::string>> ans;
    std::vector<std::string> curr;
    recv(ans, curr, s, 0);
    return ans;
}
int main()
{
    std::string s = "aab";
    auto ans = partition(s);
    return 0;
}