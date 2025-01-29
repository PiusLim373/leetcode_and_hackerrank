#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
int coinChange(std::vector<int>& coins, int amount)
{
  std::vector<int> dp(amount + 1, amount + 1);
  dp[0] = 0;

  for (int a = 1; a < amount + 1; a++)
  {
    for (auto c : coins)
    {
      if (a - c >= 0)
        dp[a] = std::min(dp[a], 1 + dp[a - c]);
    }
  }
  if (dp[amount] == amount + 1)
    return -1;
  return dp[amount];
}
int main()
{
  std::vector<int> coins = { 1, 2, 5 };
  int amount = 11;

  std::cout << coinChange(coins, amount);
  return 0;
}