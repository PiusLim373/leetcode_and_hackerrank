#include <vector>
#include <iostream>
#include <math.h>
#include <map>
#include <unordered_map>
int maxPoints(std::vector<std::vector<int>> &points)
{
    int ans = 1;
    for (int i = 0; i < points.size(); i++)
    {
        int x1 = points[i][0];
        int y1 = points[i][1];
        std::unordered_map<double, int> slope_map;
        for (int j = i + 1; j < points.size(); j++)
        {
            int x2 = points[j][0];
            int y2 = points[j][1];
            double slope = INT32_MAX;
            if(x1 != x2)
                slope = 1.0 * (y2 - y1) / (x2 - x1);
            slope_map[slope]++;
            ans = std::max(ans, slope_map[slope] + 1);
        }
    }
    return ans;
}
int maxPointsNotWorking(std::vector<std::vector<int>> &points)
{
    std::sort(points.begin(), points.end(), [](std::vector<int> &lhs, std::vector<int> &rhs)
              {
        if(lhs[0] == rhs[0])
        {
            return lhs[1] < rhs[1];
        }
        else return lhs[0] < rhs[0]; });
    // y = mx +c
    std::map<std::pair<double, double>, int> mc_map;
    for (int i = 1; i < points.size(); i++)
    {
        int y2 = points[i][1];
        int y1 = points[i - 1][1];
        int x2 = points[i][0];
        int x1 = points[i - 1][0];
        double m = 1.0 * (y2 - y1) / (x2 - x1);
        double c = y2 - m * x2;

        std::cout << "m: " << m << std::endl;
        std::cout << "c: " << c << std::endl;
        mc_map[{m, c}]++;
    }

    int max_fre = -1;
    for (auto x : mc_map)
    {
        if (x.second > max_fre)
            max_fre = x.second;
    }

    std::vector<std::pair<int, int>> pairs;
    for (auto x : mc_map)
    {
        if (x.second == max_fre)
            pairs.push_back(x.first);
    }

    int ans = -1;
    for (auto pair : pairs)
    {
        int temp = 0;
        double m = pair.first;
        double c = pair.second;
        for (auto point : points)
        {
            if (std::fabs(point[1] - (m * point[0] + c)) < 1e-7)
                temp++;
        }
        if (temp > ans)
            ans = temp;
    }
    return ans;
}
int main()
{
    std::vector<std::vector<int>> points = {
        {1, 1},
        {3, 2},
        {5, 3},
        {4, 1},
        {2, 3},
        {1, 4},
    };

    // std::vector<std::vector<int>> points = {
    //     {1, 1},
    //     {2, 2},
    //     {3, 3},
    // };

    // std::vector<std::vector<int>> points = {{0, 1}, {0, 0}, {0, 4}, {0, -2}, {0, -1}, {0, 3}, {0, -4}};
    auto ans = maxPoints(points);
    return 0;
}