#include <vector>
#include <algorithm>

struct compare
{
    bool operator()(const std::vector<int> &lhs, const std::vector<int> &rhs)
    {
        return lhs[0] < rhs[0];
    }
};

std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
{
    std::vector<std::vector<int>> ans;
    std::sort(intervals.begin(), intervals.end(), compare());
    int start = intervals[0][0];
    int end = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++)
    {
        int incoming_start = intervals[i][0];
        int incoming_end = intervals[i][1];
        if (incoming_start == start)
            end = std::max(incoming_end, end);
        else
        {
            if (incoming_start > end)
            {
                // push to ans
                ans.push_back({start, end});
                start = incoming_start;
                end = incoming_end;
            }
            else
                end = std::max(incoming_end, end);
        }
    }
    ans.push_back({start, end});
    return ans;
}
int main()
{
    // std::vector<std::vector<int>> intervals = {{15, 18}, {1, 3}, {8, 10}, {2, 6}};
    std::vector<std::vector<int>> intervals = {{4, 7}, {1, 4}};
    auto ans = merge(intervals);
    return 0;
}