#include <vector>
int maxProfit(std::vector<int> &prices)
{
    int buy1 = -__INT32_MAX__;
    int sell1 = 0;
    int buy2 = -__INT32_MAX__;
    int sell2 = 0;

    for (auto p : prices)
    {
        buy1 = std::max(buy1, -p);
        sell1 = std::max(sell1, p + buy1);
        buy2 = std::max(buy2, sell1 - p);
        sell2 = std::max(sell2, p + buy2);
    }
    return sell2;
}
int maxProfitSolution1(std::vector<int> &prices)
{
    // left to right pass, track min price and calculate profit[i] = price[i] - min price, buy low, keep track of min price and cal profit by assumming seeling on day i
    int min_price = prices[0];
    int max_profit = 0;
    std::vector<int> left;
    for (int i = 0; i < prices.size(); i++)
    {
        min_price = std::min(min_price, prices[i]);
        max_profit = std::max(prices[i] - min_price, max_profit);
        left.push_back(max_profit);
    }

    // right to left pass, track max selling price and calculate profit[i] = max selling proce - price[i], sell high, keep track of highest price from right and calculate profit at at day i
    int max_price = prices[prices.size() - 1];
    max_profit = 0;
    std::vector<int> right(prices.size(), 0);
    for (int i = prices.size() - 1; i >= 0; i--)
    {
        max_price = std::max(max_price, prices[i]);
        max_profit = std::max(max_price - prices[i], max_profit);
        right[i] = max_profit;
    }

    // final pass from left to right, sum both arr and get max profit
    max_profit = 0;
    for (int i = 0; i < left.size(); i++)
    {
        max_profit = std::max(max_profit, left[i] + right[i]);
    }
    return max_profit;
}
int main()
{
    std::vector<int> prices = {5,4,3,1};
    auto ans = maxProfit(prices);
    return 0;
}