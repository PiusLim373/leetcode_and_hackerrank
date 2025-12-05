#include <string>
#include <stack>
#include <algorithm>
std::string removeStars(std::string s)
{
    std::stack<char> container;
    for (auto c : s)
    {
        if (c == '*')
        {
            container.pop();
        }
        else
        {
            container.push(c);
        }
    }
    std::string ans;
    while (!container.empty())
    {
        ans += container.top();
        container.pop();
    }
    std::reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    // std::string s = "leet**cod*e";
    std::string s = "erase*****";


    
    auto ans = removeStars(s);
    return 0;
}