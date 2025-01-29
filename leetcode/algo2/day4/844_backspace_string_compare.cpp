#include <string>
#include <iostream>
bool backspaceCompare(std::string s, std::string t)
{
    std::string ss = "", tt = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '#')
            ss.push_back(s[i]);
        else if (ss.size())
            ss.pop_back();
    }

    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] != '#')
            tt.push_back(t[i]);
        else if (tt.size())
            tt.pop_back();
    }

    return ss == tt;
}
int main()
{
    std::string s = "ab###", t = "c#d#";
    std::cout << backspaceCompare(s, t) << std::endl;
}
