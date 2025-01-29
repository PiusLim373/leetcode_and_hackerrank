#include <iostream>
#include <vector>
int maxArea(std::vector<int> &h)
{
    int left = 0, right = h.size() - 1;
    int max_area = 0;
    while (left < right)
    {
        int low = std::min(h[left], h[right]);
        int area = (right - left) * low;
        if (area >= max_area)
            max_area = area;

        if (h[left] < h[right])
            left++;
        else if (h[left] > h[right])
            right--;
        else
        {
            left++;
            right--;
        }
    }
    return max_area;
}
int main()
{
    std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::cout << maxArea(height) << std::endl;
}