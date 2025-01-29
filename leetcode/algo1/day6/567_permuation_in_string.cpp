#include <bits/stdc++.h>
using namespace std;
bool are_map_equal(map<char, int> a, map<char, int> b)
{
    for (auto x : a)
    {
        if (a[x.first] != b[x.first])
            return false;
    }
    return true;
}
bool checkInclusion(string s1, string s2)
{

    if (s1.size() > s2.size())
        return false;
    map<char, int> s1_map, sub_map;
    for (int i = 0; i < s1.size(); i++)
    {
        s1_map[s1[i]]++;
        sub_map[s2[i]]++;
    }
    if (s1_map == sub_map)
        return true;
    for (int j = s1.size(); j < s2.size(); j++)
    {
        sub_map[s2[j]]++;
        sub_map[s2[j - s1.size()]]--;
        if (are_map_equal(s1_map, sub_map))
            return true;
    }
    return false;
}
int main()
{
    string s1 = "ab";
    string s2 = "eidbaooo";
    // map<char, int> s1_map, sub_map;
    // s1_map['a']++;
    // sub_map['a']++;
    // s1_map['b']++;
    // sub_map['b']++;

    // if (s1_map == sub_map)
    //     cout << "equal" << endl;
    // s1_map['c']++;
    // if (s1_map == sub_map)
    //     cout << "equal" << endl;
    // s1_map['c']--;
    // if (s1_map == sub_map)
    //     cout << "equal" << endl;
    cout << checkInclusion(s1, s2) << endl;
}