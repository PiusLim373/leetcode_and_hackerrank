#include <vector>

int maxProfit(int k, std::vector<int> &prices)
{
    if (prices.size() <= k / 2)
    {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            int diff = prices[i] - prices[i - 1];
            if (diff > 0)
                profit += diff;
        }
        return profit;
    }

    else
    {
        std::vector<std::vector<int>> buy_sell(k, std::vector<int>(2, 0));
        for (int i = 0; i < k; i++)
            buy_sell[i][0] = -__INT32_MAX__;

        for (auto x : prices)
        {
            for (int i = 0; i < buy_sell.size(); i++)
            {
                if (i == 0)
                    buy_sell[i][0] = std::max(buy_sell[i][0], -x);
                else
                    buy_sell[i][0] = std::max(buy_sell[i][0], buy_sell[i - 1][1] - x);
                buy_sell[i][1] = std::max(buy_sell[i][1], x + buy_sell[i][0]);
            }
        }
        return buy_sell[k - 1][1];
    }

    return 0;
}

int main()
{
    std::vector<int> prices = {2};
    int k = 2;
    auto ans = maxProfit(k, prices);
    return 0;
}