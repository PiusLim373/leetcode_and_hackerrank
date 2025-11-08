#include <string>
#include <iostream>

std::string mergeAlternately(std::string word1, std::string word2)
{
    int l1 = word1.size();
    int l2 = word2.size();
    int w1_pointer = 0;
    int w2_pointer = 0;
    std::string ans = "";
    while (w1_pointer < l1 && w2_pointer < l2)
    {
        ans += word1[w1_pointer];
        w1_pointer++;
        ans += word2[w2_pointer];
        w2_pointer++;
    }
    if (w1_pointer < l1)
        ans += word1.substr(w1_pointer, l1-w1_pointer);

    if (w2_pointer < l2)
        ans += word2.substr(w2_pointer, l2-w2_pointer);

    return ans;
}
int main()
{
    // std::string word1 = "abc";
    // std::string word2 = "pqr";

    std::string word1 = "";
    std::string word2 = "pq";

    std::string ans = mergeAlternately(word1, word2);
    std::cout << ans << std::endl;
}