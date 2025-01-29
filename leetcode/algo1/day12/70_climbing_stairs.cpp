#include <bits/stdc++.h>
using namespace std;

// map<long long, long long> memo;
map<int, int> stairs_memo;

int climb_stairs_rec(int target, int curr)
{
    if (curr >= target - 1)
        return 1;
    if (stairs_memo.count(curr))
        return stairs_memo[curr];

    return stairs_memo[curr] = climb_stairs_rec(target, curr + 1) + climb_stairs_rec(target, curr + 2);
}

int climbStairs(int n)
{
    return climb_stairs_rec(n, 0);
}

// long long fibo(int n)
// {
//     if (n <= 2)
//         return 1;
//     if (memo.find(n) != memo.end())
//         return memo[n];
//     return memo[n] = fibo(n - 1) + fibo(n - 2);
// }

int main()
{
    int n = 3;

    // long long sol = fibo(n);
    int sol = climbStairs(n);
    cout << sol << endl;
}