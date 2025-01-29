#include <bits/stdc++.h>

using namespace std;

int alternatingCharacters(string s)
{
    int deletion = 0;
    return 0;
}
int alternatingCharacters(string s)
{
    int deletion = 0;
    char last_read = s[0];
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == last_read)
        {
            deletion++;
        }
        last_read = s[i];
    }
    return deletion;
}

int main()
{
    string s = "AAAA";
    int result = alternatingCharacters(s);
    cout << result << endl;
    return 0;
}