#include <bitset>

int minFlips(int a, int b, int c)
{
    std::string a_str = std::bitset<32>(a).to_string();
    std::string b_str = std::bitset<32>(b).to_string();
    std::string c_str = std::bitset<32>(c).to_string();
    int count = 0;
    for (int i = 0; i < a_str.size(); i++)
    {
        if (c_str[i] == '1')
        {
            if (a_str[i] == '1' || b_str[i] == '1')
            {
            }
            else
                count++;
        }
        else
        {
            if (a_str[i] == '0' && b_str[i] == '0')
            {
            }
            else if (a_str[i] == '1' && b_str[i] == '1')
                count += 2;
            else
                count ++;
        }
    }
    return count;
}

int main()
{
    int a = 1;
    int b = 2;
    int c = 3;
    auto ans = minFlips(a, b, c);
    return 0;
}