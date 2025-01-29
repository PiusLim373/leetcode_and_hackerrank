#include <iostream>
#include <string>
#include <vector>

int recv(std::string s, int pointer, std::vector<int> &memo)
{
    if (memo[pointer] > -1)
        return memo[pointer];
    if (s[pointer] == '0')
        return memo[pointer] = 0;
    int res = recv(s, pointer + 1, memo);
    if (pointer + 1 < s.size() && (s[pointer] == '1' || (s[pointer] == '2' && s[pointer + 1] < '7')))
        res += recv(s, pointer + 2, memo);
    return memo[pointer] = res;
}

int numDecodings(std::string s)
{
    int n = s.size();
    std::vector<int> memo(n + 1, -1);
    memo[n] = 1;
    if (!s.size())
        return 0;
    else
        return recv(s, 0, memo);
}

int main()
{
    std::string s = "226";
    std::cout << numDecodings(s) << std::endl;
}