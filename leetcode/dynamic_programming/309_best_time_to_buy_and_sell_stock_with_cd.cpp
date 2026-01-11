#include <vector>
int maxProfit(std::vector<int> &prices)
{
    // max profit at day i if i do this action
    std::vector<int> hold(prices.size(), 0);
    std::vector<int> sold(prices.size(), 0);
    std::vector<int> rest(prices.size(), 0);

    // hold starts from - day1 price, pay to buy, hence negative
    hold[0] = -prices[0];

    // sold[0] must be very neg so it wont get choose, also becoz it is invalid to choose
    sold[0] = -__INT32_MAX__;

    for (int i = 1; i < prices.size(); i++)
    {
        // keep holding or buy after rest, which one better
        hold[i] = std::max(hold[i - 1], rest[i - 1] - prices[i]);

        // hold max logic alr process if should buy or keep hold, sold only keep track the profit one get if sell today
        sold[i] = hold[i - 1] + prices[i];

        // alr resting or just hold, see which one better
        rest[i] = std::max(rest[i - 1], sold[i - 1]);
    }

    // return the most profit between rest and sold, but not hold
    return std::max(sold[prices.size() - 1], rest[prices.size() - 1]);
}

int main()
{
    std::vector<int> prices = {1};
    auto ans = maxProfit(prices);
    return 0;
}