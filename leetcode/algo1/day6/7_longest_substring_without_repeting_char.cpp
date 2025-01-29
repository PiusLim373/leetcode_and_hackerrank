#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    // int length = 0;
    // int max_length = 0;
    // map<char, int> fre;
    // for (auto x : s)
    // {
    //     if (fre[x]++)
    //     {
    //         if (length > max_length)
    //             max_length = length;
    //         length = 1;
    //         for (auto x : fre)
    //             if (fre[x.first])
    //                 fre[x.first]--;
    //     }
    //     else
    //     {
    //         length++;
    //     }
    // }
    // if (length > max_length)
    //     max_length = length;
    // return max_length;

    int i = 0;
    int j = 0;
    int length = 0;
    set<char> lib;
    while (i < s.size() && j < s.size())
    {
        if (lib.find(s[j]) == lib.end())
        {
            // cant find
            lib.insert(s[j++]);
            length = max(length, j - i);
        }
        else
        {
            // found in set
            lib.erase(s[i++]);
        }
    }
    return length;
}
int main()
{
    string s = "dvdf";

    cout << lengthOfLongestSubstring(s) << endl;
}