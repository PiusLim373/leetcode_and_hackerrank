#include <vector>
#include <unordered_map>
#include <string>

int equalPairs(std::vector<std::vector<int>> &grid)
{
    int size = grid[0].size();
    std::unordered_map<std::string, int> m;

    // loop through all row and populate the map
    for (auto row : grid)
    {
        std::string key;
        for (int i = 0; i < row.size(); i++)
        {

            key += std::to_string(row[i]);
            if (i != row.size() - 1)
                key += ",";
        }
        m[key]++;
    }

    int return_ans = 0;

    // loop through each col
    for (int c = 0; c < size; c++)
    {
        std::string key;
        for (int r = 0; r < size; r++)
        {
            key += std::to_string(grid[r][c]);
            if (r != size - 1)
                key += ",";
        }
        if (m[key])
            return_ans += m[key];
    }

    return return_ans;
}

int main()
{
    std::vector<std::vector<int>> grid = {{3, 2, 1}, {1, 7, 6}, {2, 7, 7}};
    // std::vector<std::vector<int>> grid = {{3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}};

    auto ans = equalPairs(grid);
    return 0;
}