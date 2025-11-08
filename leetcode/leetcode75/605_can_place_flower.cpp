#include <vector>

bool canPlaceFlowers(std::vector<int> &flowerbed, int n)
{
    if (n == 0)
        return true;
    if (flowerbed.size() == 1)
    {
        if (flowerbed[0])
        {
            return n == 0;
        }
        else
            return n == 1;
    }
    for (int p = 0; p < flowerbed.size(); p++)
    {
        if (p == 0)
        {
            if (flowerbed[p] == 0 && flowerbed[p + 1] == 0)
            {
                flowerbed[p] = 1;
                n--;
            }
        }
        else if (p == flowerbed.size() - 1)
        {
            if (flowerbed[p - 1] == 0 && flowerbed[p] == 0)
            {
                flowerbed[p] = 1;
                n--;
            }
        }
        else
        {
            if (flowerbed[p - 1] == 0 && flowerbed[p] == 0 && flowerbed[p + 1] == 0)
            {
                flowerbed[p] = 1;
                n--;
            }
        }
        if (n == 0)
            return true;
    }
    return false;
}

int main()
{
    std::vector<int> flowerbed = {0};
    // std::vector<int> flowerbed = {1, 0, 0, 0, 0, 1}; // ans = 1
    int n = 0;
    auto ans = canPlaceFlowers(flowerbed, n);
    return 0;
}