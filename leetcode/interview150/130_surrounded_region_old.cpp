#include <vector>
#include <iostream>
#include <queue>
#include <map>
void back_track(std::vector<std::vector<char>>& board, std::map<std::pair<int, int>, std::pair<int, int>> origin_map,
                std::pair<int, int> last_check)
{
  board[last_check.first][last_check.second] = 'X';
  std::pair<int, int> origin = origin_map[last_check];
  while (origin != std::make_pair(-1, -1))
  {
    board[origin.first][origin.second] = 'X';
    origin = origin_map[{ origin.first, origin.second }];
  }
}
void solve(std::vector<std::vector<char>>& board)
{
  std::queue<std::pair<int, int>> q;
  std::map<std::pair<int, int>, std::pair<int, int>> origin_map;
  std::map<std::pair<int, int>, bool> visited;
  std::pair<int, int> last_check = { -1, -1 };

  std::vector<std::pair<int, int>> direction = { { -1, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 } };
  int row = board.size();
  int col = board[0].size();
  int region_count = 0;
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      if (board[i][j] == 'O' && !visited[{ i, j }])
      {
        // backtrack
        if (last_check != std::make_pair(-1, -1))
          back_track(board, origin_map, last_check);

        printf("found a new island at {%d, %d}\n", i, j);
        q.push({ i, j });
        origin_map[{ i, j }] = { -1, -1 };  // newly detected island
        region_count++;
        // might need to backtrack here
      }
      while (!q.empty())
      {
        std::pair<int, int> curr = q.front();
        q.pop();
        if (curr.first == 0 || curr.second == 0 || curr.first == row - 1 || curr.second == col - 1)
        {
          std::cout << "island is at edge, rejecting" << std::endl;
          region_count--;
        }
        visited[{ curr.first, curr.second }] = true;
        for (auto x : direction)
        {
          int check_x = curr.first + x.first;
          int check_y = curr.second + x.second;
          last_check = { curr.first, curr.second };
          if (check_x >= 0 && check_y >= 0 && check_x < row && check_y < col && board[check_x][check_y] == 'O' &&
              !visited[{ check_x, check_y }])
          {
            q.push({ check_x, check_y });
            visited[{ check_x, check_y }] = true;
            origin_map[{ check_x, check_y }] = { curr.first, curr.second };
          }
        }
      }
    }
  }
  std::cout << "region found: " << region_count << std::endl;
}
int main()
{
  //   std::vector<std::vector<char>> grid = {
  //     { 'X', 'X', 'X', 'X' }, { 'X', 'O', 'O', 'X' }, { 'X', 'X', 'O', 'X' }, { 'X', 'O', 'X', 'X' }
  //   };

  std::vector<std::vector<char>> grid = { { 'X', 'X', 'X', 'X', 'X' },
                                          { 'X', 'O', 'O', 'X', 'X' },
                                          { 'X', 'X', 'X', 'O', 'X' },
                                          { 'X', 'O', 'X', 'X', 'X' },
                                          { 'X', 'O', 'X', 'X', 'O' } };
  solve(grid);
  for (auto x : grid)
  {
    for (auto y : x)
      std::cout << y << " ";
    std::cout << std::endl;
  }
  // works up to finding the surrounded region, but not full solution
  // a better way is to loop around the border to find O, then BFS to find all O, mark them T
  // on the next pass, change all T to O, and O to X6rh
}