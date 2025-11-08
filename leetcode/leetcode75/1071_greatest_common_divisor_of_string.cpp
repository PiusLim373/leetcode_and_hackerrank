#include <string>
#include <iostream>

int findHCF(int a, int b)
{
    int small, big;
    if (a == b)
        return a;
    else if (a < b)
    {
        small = a;
        big = b;
    }
    else
    {
        small = b;
        big = a;
    }

    while (big != 0)
    {
        int temp = big;
        big = small % big;
        small = temp;
    }
    return small;
}
std::string gcdOfStrings(std::string str1, std::string str2)
{
    int hcf = findHCF(str1.size(), str2.size());
    int ans_length = 0;
    int str1_pointer = 0;
    int str2_pointer = 0;

    std::string ans = "";
    while (ans_length < hcf && str1[str1_pointer] == str2[str2_pointer])
    {
        ans += str1[str1_pointer];
        str1_pointer++;
        str2_pointer++;
        ans_length++;
    }

    while (str1_pointer < str1.size())
    {
        if (str1.substr(str1_pointer, hcf) != ans)
            return "";
        str1_pointer += hcf;
    }

    while (str2_pointer < str2.size())
    {
        if (str2.substr(str2_pointer, hcf) != ans)
            return "";
        str2_pointer += hcf;
    }
    return ans;
}

int main()
{
    std::string str1 = "AAAAABAA";
    std::string str2 = "A";

    std::string ans = gcdOfStrings(str1, str2);
    std::cout << ans;
}