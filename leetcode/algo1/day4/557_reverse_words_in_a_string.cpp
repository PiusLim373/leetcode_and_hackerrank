#include <bits/stdc++.h>
using namespace std;
string reverseWords(string s)
{
    vector<string> s2;
    stringstream ss(s);
    string temp;
    string return_val;
    while (ss >> temp)
    {
        reverse(temp.begin(), temp.end());
        return_val.append(temp + " ");
    }
    return_val.erase(return_val.end() - 1, return_val.end());
    return return_val;
}

int main()
{
    string s = "Let's take LeetCode contest";

    cout << reverseWords(s) << endl;
}