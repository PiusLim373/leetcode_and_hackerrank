#include <vector>
#include <iostream>
int maxProfit_timeout(std::vector<int> &prices)
{
    int profit = 0;
    for (int buy_ptr = 0; buy_ptr < prices.size() - 1; buy_ptr++)
    {
        for (int sell_ptr = buy_ptr + 1; sell_ptr < prices.size(); sell_ptr++)
        {
            int diff = prices[sell_ptr] - prices[buy_ptr];
            if (diff > profit)
                profit = diff;
        }
    }
    return profit;
}

int maxProfit(std::vector<int> &prices)
{
    int profit = 0;
    int buy_price = prices[0];
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] < buy_price)
        {
            buy_price = prices[i];
        }
        else if (prices[i] - buy_price > profit)
        {
            profit = prices[i] - buy_price;
        }
    }
    return profit;
}
int main()
{
    std::vector<int> a = {7, 6, 4, 3, 1};
    std::cout << maxProfit(a);
}