#include <bits/stdc++.h>

using namespace std;

map<int, int> memoization;
int fibonacci_with_memoization(int n)
{
    if (n == 0 || n == 1)
        return n;
    else
    {
        if (memoization.find(n) != memoization.end())
            return memoization[n];
        else
            return (memoization[n] = fibonacci_with_memoization(n - 1) + fibonacci_with_memoization(n - 2));
    }
}

int fibonacci(int n)
{
    // Complete the function.
    if ((n == 1) || (n == 0))
        return (n);
    else
        return (fibonacci(n - 1) + fibonacci(n - 2));
}

int main()
{
    int n;

    // cout << fibonacci(46) << endl;
    cout << fibonacci_with_memoization(46) << endl;
    return 0;
}