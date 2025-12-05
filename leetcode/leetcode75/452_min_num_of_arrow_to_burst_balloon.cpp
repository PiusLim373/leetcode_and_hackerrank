#include <vector>
#include <algorithm>

struct compareBalloon
{
    bool operator()(const std::vector<int> &lhs, const std::vector<int> &rhs)
    {
        return lhs[0] < rhs[0];
    }
};
int findMinArrowShots(std::vector<std::vector<int>> &points)
{
    std::sort(points.begin(), points.end(), compareBalloon());
    int start = points[0][0];
    int end = points[0][1];
    int arrow = 1;
    for (int i = 1; i < points.size(); i++)
    {
        if (points[i][0] == start)
        {
            // overlap, no need new arrows, but update new end;
            if (points[i][1] < end)
                end = points[i][1];
        }
        else
        {
            if (points[i][0] > end)
            {
                // new balloon no overlap, increase arrow by 1
                arrow++;
                start = points[i][0];
                end = points[i][1];
            }
            else
            {
                // start diff, choose bigger start and smaller end
                start = points[i][0];
                end = std::min(end, points[i][1]);
            }
        }
    }
    return arrow;
}
int main()
{
    // std::vector<std::vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    // std::vector<std::vector<int>> points = {{1,2}, {2,3}, {3, 4}, {4, 5}, {1, 10}};
    std::vector<std::vector<int>> points = {{9, 12}, {1, 10}, {4, 11}, {8, 12}, {3, 9}, {6, 9}, {6, 7}};

    auto ans = findMinArrowShots(points);
    return 0;
}