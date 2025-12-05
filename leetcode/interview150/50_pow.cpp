#include <unordered_map>

double dfs2(double x, int n, std::unordered_map<int, double> &memo)
{
    if (n <= 1)
        return memo[n];
    else
    {
        if (n % 2)
        {
            if (!memo.count(n / 2))
                memo[n / 2] = dfs2(x, n / 2, memo);
            return memo[n / 2] * memo[n / 2] * x;
        }
        else
        {
            if (!memo.count(n / 2))
                memo[n / 2] = dfs2(x, n / 2, memo);
            return memo[n / 2] * memo[n / 2];
        }
    }
}

double myPowWithMemo(double x, int n)
{
    std::unordered_map<int, double> memo;
    memo[0] = 1.0;
    memo[1] = x;
    if (x == 0.0)
        return 0.0;
    else if (n == 0)
        return 1.0;
    else if (n == 1)
        return x;
    else if (n < 0)
        return 1 / dfs2(x, abs(n), memo);
    double data = dfs2(x, n, memo);
    return data;
}

double dfs(double x, long long n)
{

    if (n == 0)
        return 1;
    else if (n == 1)
        return x;
    else
    {
        double data = dfs(x, n / 2);
        if (n % 2)
            return data * data * x;
        else
            return data * data;
    }
}

double myPow(double x, int n)
{
    long long N = n;
    if (N < 0)
        N = -N;
    if (x == 0.0)
        return 0.0;
    if (x == 1.0)
        return 1.0;
    if (n < 0)
        return 1 / dfs(x, N);
    else
        return dfs(x, N);
}
int main()
{
    double x = 1.0;
    int n = -2147483648;
    auto ans = myPow(x, n);
    return 0;
}