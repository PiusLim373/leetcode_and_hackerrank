#include <string>
#include <algorithm>
bool isPalindrome(int x)
{
    std::string x_str = std::to_string(x);
    std::string x_str_reverse = x_str;
    std::reverse(x_str_reverse.begin(), x_str_reverse.end());
    return x_str == x_str_reverse;

}
int main()
{
    int x = 121;
    auto ans = isPalindrome(x);
    return 0;
}