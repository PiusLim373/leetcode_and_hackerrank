#include <unordered_map>

int tribonacci(int n)
{
    std::unordered_map<int, int> t;
    t[0] = 0;
    t[1] = 1;
    t[2] = 1;
    if (n <= 2)
        return t[n];
    for (int i = 3; i <= n; i++)
    {
        t[i] = t[i-1] + t[i-2] + t[i-3];
    }
    return t[n];
}
int main()
{
    int n = 25;
    auto res = tribonacci(n);
    return 0;
}