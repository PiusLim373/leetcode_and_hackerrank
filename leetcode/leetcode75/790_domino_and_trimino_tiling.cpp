#include <unordered_map>
int numTilings(int n)
{
    int MOD = 1e9 + 7;
    std::unordered_map<long long, long long> f;
    std::unordered_map<long long, long long> p;

    f[1] = 1;
    f[2] = 2;
    p[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        p[i] = (p[i - 1] + f[i - 2]) % MOD;
        f[i] = (f[i - 1] + f[i - 2] + 2 * p[i - 1]) % MOD;
    }
    return f[n] % MOD;
}
int main()
{
    int n = 5;
    auto ans = numTilings(n);
    return 0;
}