#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<vector<int>> result;
void recursive_comb(int startnum, int n, int k)
{
    int i = startnum;
    while (i <= (n - k + 1))
    {
        v[v.size() - k] = i;
        i++;
        if (k > 1)
            recursive_comb(i, n, k - 1);
        else
            result.push_back(v);
    }
}
vector<vector<int>> combine(int n, int k)
{
    if (n < k || n == 0 || k == 0)
        return result;
    v.resize(k);
    recursive_comb(1, n, k);
    return result;
}
int main()
{
    int n = 4;
    int k = 2;

    vector<vector<int>> sol = combine(n, k);
    for (auto x : sol)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}