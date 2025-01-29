#include <bits/stdc++.h>
using namespace std;

vector<string> letterCasePermutation(string s)
{
    deque<string> q;
    q.push_back(s);
    for (int i = 0; i < s.size(); i++)
    {
        if (isalpha(s[i]))
        {
            int size = q.size();
            while (size--)
            {
                string curr = q.front();
                q.pop_front();

                string temp = curr;
                temp[i] = toupper(curr[i]);
                q.push_back(temp);

                temp[i] = tolower(curr[i]);
                q.push_back(temp);
            }
        }
    }
    vector<string> sol;
    for (auto x : q)
        sol.push_back(x);
    return sol;
}
int main()
{
    string s = "a1b2C1";

    vector<string> sol = letterCasePermutation(s);
    for (auto x : sol)
    {
        cout << x << endl;
    }
}