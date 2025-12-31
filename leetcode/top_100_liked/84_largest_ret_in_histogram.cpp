#include <vector>
#include <stack>
int largestRectangleArea(std::vector<int> &heights)
{
    std::stack<std::pair<int, int>> st; // index, hright
    int max_area = heights[0];
    st.push({0, heights[0]});
    for (int i = 1; i < heights.size(); i++)
    {
        int st_index = i;
        while (!st.empty() && heights[i] < st.top().second)
        {
            int area = (i - st.top().first) * st.top().second;
            max_area = std::max(max_area, area);
            st_index = st.top().first;
            st.pop();
        }
        st.push({st_index, heights[i]});
    }

    int pos = heights.size();
    while (!st.empty())
    {
        auto [index, height] = st.top();
        int area = (pos - index) * height;
        max_area = std::max(max_area, area);
        st.pop();
    }

    return max_area;
}


int main()
{
    // std::vector<int> heights = {2, 1, 5, 6, 2, 3};
    std::vector<int> heights = {10};
    auto ans = largestRectangleArea(heights);
    return 0;
}