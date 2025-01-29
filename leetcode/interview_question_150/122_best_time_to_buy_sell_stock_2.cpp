
#include <vector>

int maxProfit(std::vector<int>& prices)
{
  if (prices.size() == 1)
    return 0;
  std::vector<int> profit;
  for (int i = 1; i < prices.size(); i++)
  {
    profit.push_back(prices[i] - prices[i - 1]);
  }
  int max_profit = 0;
  for (auto x : profit)
  {
    if (x > 0)
      max_profit += x;
  }
  return max_profit;
}
int main()
{
  std::vector<int> prices = { 1, 10 };
  int ans = maxProfit(prices);
  return 0;
}