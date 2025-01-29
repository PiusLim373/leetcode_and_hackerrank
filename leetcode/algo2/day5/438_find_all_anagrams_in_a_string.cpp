#include <iostream>
#include <string>
#include <vector>
#include <map>

std::vector<int> findAnagrams(std::string s, std::string p)
{
    std::map<char, int> fre_s;
    std::map<char, int> fre_p;
    std::vector<int> res;
    for (auto x : p)
        fre_p[x]++;
    for (int i = 0; i < s.size(); i++)
    {
        if (i < p.size())
            fre_s[s[i]]++;
        else
        {
            if (fre_s.count(s[i - p.size()]) && fre_s[s[i - p.size()]] > 1)
                fre_s[s[i - p.size()]]--;
            else
                fre_s.erase(s[i - p.size()]);
            fre_s[s[i]]++;
        }

        if (fre_s == fre_p)
            res.push_back(i - p.size() + 1);
    }
    return res;
}

int main()
{
    std::string s = "cbaebabacd", p = "abc";
    for (auto x : findAnagrams(s, p))
        std::cout << x << " ";

    // std::map<char, int> fre_s;
    // if (fre_s.find('x') != fre_s.end())
    //     std::cout << "found";
    // // fre_s['x']++;
    // // fre_s.erase('x');
    // return 0;
}