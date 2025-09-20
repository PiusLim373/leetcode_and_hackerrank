#include <map>
#include <string>

bool closeStrings(std::string word1, std::string word2)
{
    if (word1.size() != word2.size())
        return false;
    std::map<char, int> w1, w2, w1_fre, w2_fre;
    for (auto x : word1)
        w1[x]++;
    for (auto x : word2)
        w2[x]++;

    for (auto x : w1)
    {
        if (!w2[x.first])
            return false;
    }

    for (auto x : w1)
        w1_fre[x.second]++;
    for (auto x : w2)
        w2_fre[x.second]++;

    for (auto x : w2_fre)
    {
        if (x.second != w1_fre[x.first])
            return false;
    }
    return true;
}

int main()
{
    std::string word1 = "cabbbadd";
    std::string word2 = "abbcccdd";
    /*
        w1: {c: 1, a: 2, b: 3, d: 2}    {1: 2, 2: 2. 3:1}
        w2: {c: 3, a: 1, b: 2, d: 2}    {1: 2, 2: 2, 3:1}

    */
    auto res = closeStrings(word1, word2);
    return 0;
}