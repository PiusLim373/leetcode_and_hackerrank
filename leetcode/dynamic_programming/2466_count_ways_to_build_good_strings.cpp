#include <vector>
#include <unordered_map>

int recv(int &low, int &high, int &zero, int &one, int length, std::unordered_map<int, int> &memo)
{
    // if curr str length > high, invalid 
    if (length > high)
        return 0;
    
    // use memo to cache
    if (memo.contains(length))
        return memo[length];

    int res = 0;
    // if str length greater than low, its considered a solution alr
    if (length >= low)
        res = 1;
    // sum up left tree and right tree, save to cache and return
    res += recv(low, high, zero, one, length + zero, memo) + recv(low, high, zero, one, length + one, memo);
    memo[length] = res % 1'000'000'007 ;
    return res  % 1'000'000'007;
}
int countGoodStrings(int low, int high, int zero, int one)
{
    std::unordered_map<int, int> memo;
    return recv(low, high, zero, one, 0, memo);
}

int main()
{
    int low = 200, high = 200, zero = 10, one = 1;
    auto ans = countGoodStrings(low, high, zero, one);
    return 0;
}