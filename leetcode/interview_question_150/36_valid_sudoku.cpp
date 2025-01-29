#include <vector>
#include <iostream>
#include <map>

bool isValidSudoku(std::vector<std::vector<char>> &board)
{
    std::map<char, int> row_map;
    std::map<int, std::map<char, int>> col_map;
    std::map<char, int> block_map;
    for (int row = 0; row < board.size(); row++)
    {
        
        for (int col = 0; col < board[row].size(); col++)
        {
            row_map[board[row][col]] ++;
            if (row_map[board[row][col]] > 1 && board[row][col] != '.')
                return false;

            col_map[col][board[row][col]] ++;
            if (col_map[col][board[row][col]] > 1 && board[row][col] != '.')
                return false;
            // if (row == )
        }
    }
    return true;
}
int main()
{
    std::vector<std::vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    std::cout << isValidSudoku(board);
}