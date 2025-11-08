#include <iostream>
#include <string>
#include <vector>
bool isVowel(char c)
{
    c = tolower(c);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}
int maxVowels(std::string s, int k)
{
    std::vector<int> filtered;
    for (auto x : s)
    {
        if (isVowel(x))
            filtered.push_back(1);
        else
            filtered.push_back(0);
    }
    int count = 0;
    for (int i = 0; i < k; i++)
    {
        count += filtered[i];
    }
    int temp = count;
    for (int i = k; i < filtered.size(); i++)
    {
        temp -= filtered[i - k];
        temp += filtered[i];
        if (temp > count)
            count = temp;
    }
    return count;
}
int main()
{
    std::string s = "a";
    int k = 3;
    auto ans = maxVowels(s, k);
    return 0;
}