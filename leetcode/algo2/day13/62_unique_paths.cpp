#include <iostream>
#include <map>
#include <utility>
int uniquePaths(int m, int n)
{
    std::map<std::pair<int, int>, int> sol;
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == m - 1 || j == n - 1)
                sol[{i, j}] = 1;
            else
            {
                sol[{i, j}] = sol[{i + 1, j}] + sol[{i, j + 1}];
            }
        }
    }
    return sol[{0, 0}];
}
int main()
{
    int m = 30;
    int n = 30;
    std::cout << uniquePaths(m, n) << std::endl;
}
