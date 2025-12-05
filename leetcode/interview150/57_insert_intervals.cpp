#include <vector>
#include <algorithm>

std::vector<std::vector<int>> insert(std::vector<std::vector<int>> &intervals, std::vector<int> &newInterval)
{
    intervals.push_back(newInterval);
    std::vector<std::vector<int>> ans;
    std::sort(intervals.begin(), intervals.end(), [](const std::vector<int> &lhs, const std::vector<int> &rhs)
              { return lhs[0] < rhs[0]; });
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
    // std::vector<std::vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    std::vector<std::vector<int>> intervals = {{1, 3}, {6, 9}};
    std::vector<int> newinterval = {2, 5};
    auto ans = insert(intervals, newinterval);
    return 0;
}