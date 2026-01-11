#include <unordered_map>
#include <chrono>
#include <iostream>
int recv(int n, std::unordered_map<int, int> &memo)
{
    if (!memo.contains(n))
    {
        memo[n] = recv(n - 1, memo) + recv(n - 2, memo);
    }
    return memo[n];
}

int fib(int n)
{

    // if (n <= 1)
    //     return n;
    // return fib(n - 1) + fib(n - 2);

    std::unordered_map<int, int> memo;
    memo[1] = 1;
    memo[0] = 0;
    return recv(n, memo);
}
int main()
{
    int n = 40;
    auto start = std::chrono::high_resolution_clock::now();
    auto ans = fib(n);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "ran for: " << elapsed.count() << std::endl;
    return 0;
}