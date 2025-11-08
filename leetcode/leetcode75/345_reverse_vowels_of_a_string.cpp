#include <iostream>
#include <string>
bool isVowel(char c)
{
    c = tolower(c);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}
std::string reverseVowels(std::string s)
{
    int left = 0;
    int right = s.size() - 1;
    while (left < right)
    {
        while (!isVowel(s[left]) && left < right)
            left++;
        while (!isVowel(s[right]) && left < right)
            right--;
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
    return s;
}
int main()
{
    std::string s = "ab";
    auto ans = reverseVowels(s);
    return 0;
}