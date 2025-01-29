#include <vector>
#include <iostream>
void gameOfLife(std::vector<std::vector<int>> &board)
{
    std::vector<std::vector<int>> result(board.size(), std::vector<int>(board[0].size(), 0));
    std::vector<std::pair<int, int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            int curr_state = board[i][j];
            int nums_of_ones = 0;
            for (auto x : dir)
            {
                int check_x = i + x.first;
                int check_y = j + x.second;
                if (check_x >= 0 && check_y >= 0 && check_x < board.size() && check_y < board[i].size() && board[check_x][check_y] == 1)
                    nums_of_ones++;
            }
            if (curr_state)
            {
                if (nums_of_ones < 2 || nums_of_ones > 3)
                    curr_state = 0;
            }
            else
            {
                if (nums_of_ones == 3)
                    curr_state = 1;
            }
            result[i][j] = curr_state;
        }
    }
    board = result;
}
int main()
{
    std::vector<std::vector<int>> board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    gameOfLife(board);
    for (auto x : board)
    {
        for (auto y : x)
            std::cout << y << " ";
        std::cout << std::endl;
    }
}