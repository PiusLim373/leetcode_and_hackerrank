#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

int compress(std::vector<char> &chars)
{
    if (chars.size() == 1)
    {
        return 1;
    }
    std::vector<std::unordered_map<char, int>> data;
    char last_char = chars[0];
    int fre = 1;
    for (int i = 1; i < chars.size(); i++)
    {
        if (chars[i] == last_char)
        {
            fre++;
        }
        else
        {
            data.push_back({{last_char, fre}});
            last_char = chars[i];
            fre = 1;
        }

        if (i == chars.size() - 1)
        {
            data.push_back({{last_char, fre}});
            last_char = chars[i];
            fre = 1;
        }
    }

    std::vector<char> ans;
    for (auto x : data)
    {
        for (auto y : x)
        {
            ans.push_back(y.first);
            if (y.second > 1)
            {
                std::string fre = std::to_string(y.second);
                for (auto z : fre)
                    ans.push_back(z);
            }
        }
    }
    chars = ans;
    return ans.size();
}

int main()
{
    // std::vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    std::vector<char> chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    // std::vector<char> chars = {'a'};
    auto ans = compress(chars);
    return 1;
}