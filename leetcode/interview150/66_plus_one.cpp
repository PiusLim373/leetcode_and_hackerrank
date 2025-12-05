#include <vector>
#include <math.h>
#include <string>

std::vector<int> plusOne(std::vector<int> &digits)
{
    std::vector<int> ans;
    int carry = 1;
    for (int i = (int)digits.size() - 1; i >= 0; i--)
    {
        int sum = digits[i] + carry;
        ans.push_back(sum % 10);
        carry = sum / 10;
    }
    if (carry)
        ans.push_back(1);
    std::reverse(ans.begin(), ans.end());
    return ans;
}
std::vector<int> plusOneNotWorking(std::vector<int> &digits)
{
    unsigned long long temp = 0;
    for (int i = digits.size() - 1; i >= 0; i--)
    {
        temp += digits[i] * (unsigned long long)std::pow(10, digits.size() - 1 - i);
    }
    temp++;
    std::string data = std::to_string(temp);

    std::vector<int> ans;
    for (auto x : data)
        ans.push_back(x - '0');
    return ans;
}
int main()
{
    std::vector<int> digits = {6, 1, 4, 5, 3, 9, 0, 1, 9, 5, 1, 8, 6, 7, 0, 5, 5, 4, 9};
    auto ans = plusOne(digits);
    return 0;
}