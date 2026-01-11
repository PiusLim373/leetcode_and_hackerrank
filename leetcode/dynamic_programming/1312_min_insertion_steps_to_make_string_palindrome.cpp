#include <string>
#include <map>

int recv(int left, int right, std::map<std::pair<int, int>, int> &dp, std::string &s)
{
    if (left >= right)
        return 0;

    // memo to cached previously solved, so the min search can happen faster
    if (dp.contains({left, right}))
        return dp[{left, right}];

    // if the first and last char is same, becomes a subproblem of searching inside, hence left +1, right-1
    if (s[left] == s[right])
        return recv(left + 1, right - 1, dp, s);

    // if not same, then either add one on back (left+1, back) or add one on front (left, right-1), since +1 char so result +1
    else
    {
        int res = std::min(recv(left + 1, right, dp, s), recv(left, right - 1, dp, s)) + 1;
        dp[{left, right}] = res;
        return res;
    }
}

int minInsertions(std::string s)
{
    std::map<std::pair<int, int>, int> dp;
    return recv(0, s.size() - 1, dp, s);
}

int main()
{
    std::string s = "zzazz";
    auto ans = minInsertions(s);
    return 0;
}