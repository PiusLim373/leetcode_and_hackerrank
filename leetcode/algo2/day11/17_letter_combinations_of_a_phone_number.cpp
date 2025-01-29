#include <vector>
#include <iostream>
#include <string>
#include <map>

std::map<char, std::vector<char>> keypad;
std::vector<std::string> res;

void populate(std::string digits, std::string temp_str, int pointer)
{
    if (temp_str.size() == digits.size())
        res.push_back(temp_str);
    if (pointer >= digits.size())
        return;
    for (auto x : keypad[digits[pointer]])
    {
        temp_str.push_back(x);
        populate(digits, temp_str, pointer + 1);
        temp_str.pop_back();
    }
}

std::vector<std::string> letterCombinations(std::string digits)
{

    if (!digits.size())
        return res;
    keypad['2'] = {'a', 'b', 'c'};
    keypad['3'] = {'d', 'e', 'f'};
    keypad['4'] = {'g', 'h', 'i'};
    keypad['5'] = {'j', 'k', 'l'};
    keypad['6'] = {'m', 'n', 'o'};
    keypad['7'] = {'p', 'q', 'r', 's'};
    keypad['8'] = {'t', 'u', 'v'};
    keypad['9'] = {'w', 'x', 'y', 'z'};

    std::string temp_str;
    int pointer = 0;
    populate(digits, temp_str, pointer);
    return res;
}

int main()
{

    std::string digits = "233";
    int target = 8;
    for (auto x : letterCombinations(digits))
    {
        std::cout << x << " ";
        std::cout << std::endl;
    }
}