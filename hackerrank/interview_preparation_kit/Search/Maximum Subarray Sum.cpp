#include <iostream>
#include <vector>
#include <algorithm>
std::vector<std::vector<int>> res = {{}};

void generate_subarr(std::vector<int> &a, std::vector<int> temp2, int pointer)
{
    int start;
    for (int i = 0; i < a.size(); i++)
    {
        if (i == 0 || a[i] != a[i - 1])
            start = 0;
        for (int end = res.size(); start < end; start++)
        {
            std::vector<int> temp = res[start];
            temp.push_back(a[i]);
            res.push_back(temp);
        }
    }
}

int get_max_modulo(int m)
{
    int max_modulo = -1;
    for (auto x : res)
    {
        int sum = 0;
        for (auto y : x)
            sum += y;
        if (sum % m > max_modulo)
            max_modulo = sum % m;
        if (max_modulo == m - 1)
            return max_modulo;
    }
    return max_modulo;
}

int main()
{
    std::vector<int> a = {3, 3, 9, 9, 5};
    int m = 7;
    std::sort(a.begin(), a.end());
    generate_subarr(a, {}, 0);
    for (auto x : res)
    {
        for (auto y : x)
            std::cout << y << " ";
        std::cout << std::endl;
    }
    std::cout << get_max_modulo(m);
}