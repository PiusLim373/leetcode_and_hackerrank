#include <vector>
#include <algorithm>

int calculateTime(std::vector<int> piles, int speed)
{
    int time = 0;
    for (auto x : piles)
    {
        time += x / speed;
        if (x % speed)
            time++;
    }
    return time;
}

int minEatingSpeed(std::vector<int> &piles, int h)
{
    piles.push_back(0);
    std::sort(piles.begin(), piles.end());

    int left = piles[0];
    int right = piles[piles.size() - 1];

    int last_valid = right;
    while (left <= right)
    {
        int middle = left + (right - left) / 2;
        if (middle == 0)
            return 1;
        int time_required = calculateTime(piles, middle);
        if (time_required <= h)
        {
            right = middle - 1;
            last_valid = middle;
        }
        else
            left = middle + 1;
    }
    return last_valid;
}

int main()
{
    // std::vector<int> piles = {30,11,23,4,20};
    std::vector<int> piles = {3, 6, 7, 11};
    int h = 18;
    auto ans = minEatingSpeed(piles, h);
    return 0;
}