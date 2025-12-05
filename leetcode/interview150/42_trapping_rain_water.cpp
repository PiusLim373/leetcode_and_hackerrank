#include <vector>
int trap(std::vector<int> &height)
{
    if (height.size() < 3)
        return 0;
    std::vector<int> max_left = {0};
    std::vector<int> max_right = {0};

    int max = 0;
    for (int i = 1; i < height.size(); i++)
    {
        if (height[i - 1] > max)
            max = height[i - 1];
        max_left.push_back(max);
    }

    max = 0;
    for (int i = height.size() - 2; i >= 0; i--)
    {
        if (height[i + 1] > max)
            max = height[i + 1];
        max_right.push_back(max);
    }
    std::reverse(max_right.begin(), max_right.end());

    int water = 0;
    for (int i = 0; i < max_left.size(); i++)
    {
        int temp = std::min(max_left[i], max_right[i]) - height[i];
        if (temp > 0)
            water += temp;
    }
    return water;
}

int main()
{
    std::vector<int> height = {2, 2, 2};
    auto ans = trap(height);
    return 0;
}