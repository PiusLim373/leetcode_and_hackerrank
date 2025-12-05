#include <vector>
#include <iostream>
#include <unordered_map>

bool isValidSudoku(std::vector<std::vector<char>> &board)
{
    std::unordered_map<char, int> m;

    // check all col
    for (int col = 0; col < board.size(); col++)
    {
        for (int row = 0; row < board.size(); row++)
        {
            char data = board[row][col];
            if (data != '.')
            {
                m[data]++;
                if (m.count(data) && m[data] > 1)
                    return false;
            }
        }
        m.clear();
    }

    // check all row
    for (int row = 0; row < board.size(); row++)
    {
        for (int col = 0; col < board.size(); col++)
        {
            char data = board[row][col];
            if (data != '.')
            {
                m[data]++;
                if (m.count(data) && m[data] > 1)
                    return false;
            }
        }
        m.clear();
    }

    // check each blocks
    // top left: 0,0 to 2,2   top mid: 0,3 to 2, 5  top right: 0,6 to 2. 8
    // mid left: 3,0 to 5,2   mid mid: 3,3 to 5, 5  mid right: 3,6 to 5. 8
    // bot left: 6,0 to 8,2   bot mid: 6,3 to 8, 5  top right: 6,6 to 8. 8

    std::vector<std::pair<int, int>> start = {{0, 0}, {0, 3}, {0, 6}, {3, 0}, {3, 3}, {3, 6}, {6, 0}, {6, 3}, {6, 6}};
    std::vector<std::pair<int, int>> end = {{2, 2}, {2, 5}, {2, 8}, {5, 2}, {5, 5}, {5, 8}, {8, 2}, {8, 5}, {8, 8}};

    for (int i = 0; i < start.size(); i++)
    {
        auto [row_start, col_start] = start[i];
        auto [row_end, col_end] = end[i];
        for (int row = row_start; row <= row_end; row++)
        {
            for (int col = col_start; col <= col_end; col++)
            {
                char data = board[row][col];
                if (data != '.')
                {
                    m[data]++;
                    if (m.count(data) && m[data] > 1)
                        return false;
                }
            }
        }
        m.clear();
    }
    return true;
}
int main()
{
    // std::vector<std::vector<char>> board = {
    //     {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    //     {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    //     {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    //     {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    //     {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    //     {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    //     {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    //     {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    //     {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    std::vector<std::vector<char>> board = {
        {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    auto ans = isValidSudoku(board);
    return 0;
}