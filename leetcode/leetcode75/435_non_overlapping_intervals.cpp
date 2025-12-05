#include <vector>
#include <algorithm>
#include <queue>

int eraseOverlapIntervals(std::vector<std::vector<int>> &intervals)
{
    std::sort(intervals.begin(), intervals.end(), [](const std::vector<int> &lhs, const std::vector<int> &rhs)
              { return lhs[0] < rhs[0]; });

    int start = intervals[0][0];
    int end = intervals[0][1];
    int remove = 0;
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] == start)
        {
            if (intervals[i][1] < end)
            {
                // reject the previous one,
                end = intervals[i][1];
                remove++;
            }
            else
            {
                // incoming is longer, dont do anything
                remove++;
            }
        }
        else
        {
            if (intervals[i][0] >= end)
            {
                // incoming start > current end, accepted
                end = intervals[i][1];
            }
            else
            {
                if (intervals[i][1] < end)
                {
                    // incoming end faster than current, accept this and remove prev
                    end = intervals[i][1];
                    remove++;
                }
                else
                {
                    // incoming end later than current end, dont do anything
                    remove++;
                }
            }
        }
    }
    return remove;
}
int main()
{
    // std::vector<std::vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    // std::vector<std::vector<int>> intervals = {{1, 5}, {5,10}, {15, 20}};
    std::vector<std::vector<int>> intervals = {
        {-23, 10},
        {-32, 72},
        {-34, -8},
        {13, 56},
        {-4, 17},
        {-95, 9},
        {99, 100},
        {83, 100},
        {2, 5},
        {-28, -17},
        {19, 91},
        {2, 92},
        {-32, 40},
        {-50, -17},
        {-28, 18},
        {31, 33},
        {-86, 26},
        {-95, 40},
        {96, 98},
        {-50, -36},
        {48, 68},
        {-40, -28},
        {-95, 44},
        {-63, 76},
        {-38, 52},
        {66, 83},
        {12, 45},
        {-89, 65},
        {-78, 34},
        {29, 93},
        {-68, 41},
        {3, 35},
        {9, 83},
        {60, 89},
        {-74, -33},
        {-55, 36},
        {-71, -51},
        {-18, -1},
        {58, 98},
        {4, 17},
        {-73, -36},
        {-63, -36},
        {-73, 5},
        {72, 90},
        {92, 96},
        {-92, -4},
        {37, 73},
        {46, 76},
        {-12, 24},
        {-45, 46},
        {-13, 5},
        {64, 95},
        {44, 58},
        {-87, -70},
        {-15, -11},
        {49, 97},
        {69, 83},
        {-41, 10},
        {5, 21},
        {-83, 97},
        {-33, 86},
        {35, 39},
        {-57, 39},
        {-70, -64},
        {92, 99},
        {-37, 96},
        {49, 87},
        {-37, 15},
        {99, 100},
        {-67, 60},
        {-95, 6},
    };
    auto ans = eraseOverlapIntervals(intervals);
    return 0;
}