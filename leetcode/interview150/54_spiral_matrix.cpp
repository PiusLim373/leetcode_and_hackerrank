#include <vector>
#include <string>

std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix)
{
    int right = matrix[0].size();
    int left = 0;
    int btm = matrix.size();
    int top = 0;

    int curr_row = 0;
    int curr_col = 0;
    int curr_dir_index = 0;
    std::string curr_direction = "right";
    std::vector<int> ans;

    while (top < btm && left < right)
    {
        for (int temp = left; temp < right; temp++)
            ans.push_back(matrix[top][temp]);
        top++;

        for (int temp = top; temp < btm; temp++)
            ans.push_back(matrix[temp][right - 1]);
        right--;

        if (!(top < btm && left < right))
            break;

        for (int temp = right - 1; temp >= left; temp--)
            ans.push_back(matrix[btm - 1][temp]);
        btm--;

        for (int temp = btm - 1; temp >= top; temp--)
            ans.push_back(matrix[temp][left]);
        left++;
    }
    return ans;
}

// if (curr_direction == "right")
// {
//     if (curr_col < right_wall - 1)
//         curr_col++;
//     else
//     {
//         curr_direction = "down";
//         curr_row++;
//         right_wall--;
//     }
// }
// else if (curr_direction == "down")
// {
//     if (curr_row < btm_wall - 1)
//         curr_row++;
//     else
//     {
//         curr_direction = "left";
//         curr_col--;
//         btm_wall--;
//     }
// }
// else if (curr_direction == "left")
// {
//     if (curr_col > left_wall + 1)
//         curr_col--;
//     else
//     {
//         curr_direction = "up";
//         curr_row--;
//         left_wall++;
//     }
// }
// else if (curr_direction == "up")
// {
//     if (curr_row > top_wall + 1)
//         curr_row--;
//     else
//     {
//         curr_direction = "right";
//         curr_col++;
//         top_wall++;
//     }
// }
int main()
{
    std::vector<std::vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    auto ans = spiralOrder(matrix);
    return 0;
}