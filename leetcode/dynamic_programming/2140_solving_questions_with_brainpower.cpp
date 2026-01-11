#include <vector>
long long mostPoints(std::vector<std::vector<int>> &questions)
{
    // dp[i] = max points to get at pos i
    std::vector<long long> dp(questions.size(), 0);
    dp[questions.size() - 1] = questions[questions.size() - 1][0];

    for (int i = dp.size() - 2; i >= 0; i--)
    {
        // option 1: dont solve curr and solve next
        // option 2: solve and jump forwards
        long long score = questions[i][0];
        if (i + questions[i][1] + 1 <= dp.size() - 1)
            score += dp[i + questions[i][1] + 1];
        dp[i] = std::max(dp[i + 1], score);
    }

    return dp[0];
}
int main()
{
    // std::vector<std::vector<int>> questions = {{3, 2}, {4, 3}, {4, 4}, {2, 5}};
    std::vector<std::vector<int>> questions = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    auto ans = mostPoints(questions);
    return 0;
}