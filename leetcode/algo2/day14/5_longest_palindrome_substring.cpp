#include <iostream>
#include <string>
std::string longestPalindrome(std::string s)
{
    int length = 0;
    std::string str = "";
    for (int i = 0; i < s.size(); i++)
    {
        int left = i, right = i;
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            if (right - left + 1 > length)
            {
                length = right - left + 1;
                str = s.substr(left, length);
            }
            left--;
            right++;
        }
        left = i;
        right = i + 1;
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            if (right - left + 1 > length)
            {
                length = right - left + 1;
                str = s.substr(left, length);
            }
            left--;
            right++;
        }
    }
    return str;
}
int main()
{
    std::string s = "cbbd";
    std::cout << longestPalindrome(s) << std::endl;
}