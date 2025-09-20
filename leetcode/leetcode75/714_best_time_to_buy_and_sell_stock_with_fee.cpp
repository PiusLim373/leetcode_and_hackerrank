#include <vector>

int maxProfit(std::vector<int> &prices, int fee)
{
    int hold = -prices[0];
    int cash = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        hold = std::max(hold, cash - prices[i]);
        cash = std::max(cash, hold + prices[i] - fee);
    }
    return cash;
}
int main()
{
    std::vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    auto res = maxProfit(prices, fee);
    return 0;
}