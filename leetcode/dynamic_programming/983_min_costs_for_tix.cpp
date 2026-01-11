#include <vector>
#include <unordered_set>
int mincostTickets(std::vector<int> &days, std::vector<int> &costs)
{
    // convert days to a set to allow O(1) times to check if travelling on the day
    std::unordered_set<int> travel;
    for (auto x : days)
        travel.insert(x);

    // init a dp[i] means max cost for day i, index 1 based
    std::vector<int> dp(days[days.size() - 1] + 1, 0);

    for (int i = dp.size(); i > 0; i--)
    {
        // if need to buy ticket, then compare the min cost of buy 3 diff tic, skip forward x days
        if (travel.contains(i))
        {
            int two_day_cost = costs[0];
            if ((i + 1) < dp.size())
                two_day_cost += dp[i + 1];
            int seven_day_cost = costs[1];
            if ((i + 7) < dp.size())
                seven_day_cost += dp[i + 7];
            int thirty_day_cost = costs[2];
            if ((i + 30) < dp.size())
                thirty_day_cost += dp[i + 30];
            std::vector<int> compare = {
                two_day_cost,
                seven_day_cost,
                thirty_day_cost,
            };
            dp[i] = *std::min_element(compare.begin(), compare.end());
        }

        // if not travelling that day, inhereit from the day after
        else
            dp[i] = dp[i + 1];
    }

    // return first days as it is index 1 based
    return dp[1];
}

int main()
{
    std::vector<int> days = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
    std::vector<int> costs = {2, 7, 15};
    auto ans = mincostTickets(days, costs);
    return 0;
}