#include <string>
#include <algorithm>
#include <bitset>

std::string addBinaryNotworking(std::string a, std::string b)
{
    int a_val = std::stoi(a, nullptr, 2);
    int b_val = std::stoi(b, nullptr, 2);
    int c_val = a_val + b_val;
    std::bitset<32> c(c_val);
    std::string c_str = c.to_string();
    int start = c_str.size() - 1;
    for (int i = 0; i < c_str.size(); i++)
    {
        if (c_str[i] != '0')
        {
            start = i;
            break;
        }
    }
    return c_str.substr(start, c_str.size());
}
std::string addBinary(std::string a, std::string b)
{
    std::string ans;
    if (a.size() > b.size())
        b = std::string(a.size() - b.size(), '0') + b;
    if (b.size() > a.size())
        a = std::string(b.size() - a.size(), '0') + a;

    int carry = 0;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        int a_val = a[i] - '0';
        int b_val = b[i] - '0';
        int sum = a_val + b_val + carry;

        ans += (sum % 2) + '0';
        carry = sum / 2;
    }

    if (carry)
        ans += '1';
    std::reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    std::string a = "1010", b = "1011";
    auto ans = addBinary(a, b);
    return 0;
}