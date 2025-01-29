#include <set>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

std::vector<std::vector<int>> intervalIntersection(std::vector<std::vector<int>> &firstList, std::vector<std::vector<int>> &secondList)
{
    int p1 = 0, p2 = 0;
    std::vector<std::vector<int>> res;
    while (p1 < firstList.size() && p2 < secondList.size())
    {
        int low = std::max(firstList[p1][0], secondList[p2][0]);
        int high = std::min(firstList[p1][1], secondList[p2][1]);
        if (low <= high)
            res.push_back({low, high});
        if (firstList[p1] == secondList[p2])
        {
            p1++;
            p2++;
        }
        else
        {
            int c = firstList[p1][0], d = firstList[p1][1], e = secondList[p2][0], f = secondList[p2][1];
            if (d == f)
            {
                if (c > e)
                    p1++;
                else
                    p2++;
            }
            else if (d > f)
                p2++;
            else
                p1++;
        }
    }
    return res;
}

std::vector<std::vector<int>> intervalIntersectionTimedOut(std::vector<std::vector<int>> &firstList, std::vector<std::vector<int>> &secondList)
{
    int p1 = 0, p2 = 0;
    std::vector<std::vector<int>> res;
    while (p1 < firstList.size() && p2 < secondList.size())
    {
        std::set<int> a, b;
        std::vector<int> intersec;
        for (int i = firstList[p1][0]; i <= firstList[p1][1]; i++)
        {
            a.insert(i);
        }

        for (int i = secondList[p2][0]; i <= secondList[p2][1]; i++)
        {
            b.insert(i);
        }
        std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(intersec));
        if (intersec.size())
            res.push_back({intersec[0], intersec[intersec.size() - 1]});
        if (firstList[p1] == secondList[p2])
        {
            p1++;
            p2++;
        }
        else
        {
            int c = firstList[p1][0], d = firstList[p1][1], e = secondList[p2][0], f = secondList[p2][1];
            if (d == f)
            {
                if (c > e)
                    p1++;
                else
                    p2++;
            }
            else if (d > f)
                p2++;
            else
                p1++;
        }
    }
    return res;
}

std::vector<std::vector<int>> intervalIntersectionbugged(std::vector<std::vector<int>> &firstList, std::vector<std::vector<int>> &secondList)
{
    std::set<int> a, b;
    std::vector<int> intersec;
    for (auto x : firstList)
    {
        for (int i = x[0]; i <= x[1]; i++)
        {
            a.insert(i);
        }
    }
    for (auto x : secondList)
    {
        for (int i = x[0]; i <= x[1]; i++)
        {
            b.insert(i);
        }
    }
    std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(intersec));
    return {{}};
}

int main()
{
    std::vector<std::vector<int>> firstList = {{0, 2},
                                               {5, 10},
                                               {13, 23},
                                               {24, 25}};

    std::vector<std::vector<int>> secondList = {{1, 5},
                                                {8, 12},
                                                {15, 24},
                                                {25, 26}};

    for (auto x : intervalIntersection(firstList, secondList))
    {
        for (auto y : x)
            std::cout << y << " ";
        std::cout << std::endl;
    }
}