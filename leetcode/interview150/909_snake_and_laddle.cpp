#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>

int snakesAndLadders(std::vector<std::vector<int>>& board)
{
  std::vector<int> all_nodes;
  std::reverse(board.begin(), board.end());
  for (int row = 0; row < board.size(); row++)
  {
    std::vector<int> temp = board[row];
    if (row % 2)
    {
      std::reverse(temp.begin(), temp.end());
    }
    for (auto x : temp)
      all_nodes.push_back(x);
  }

  int total_size = all_nodes.size();
  std::vector<bool> visited(total_size, false);
  std::queue<std::pair<int, int>> q;
  q.push({ 0, 0 });  // pos and move

  while (!q.empty())
  {
    auto [pos, moves] = q.front();
    q.pop();
    visited[pos] = true;
    if (pos == total_size - 1)
      return moves;

    for (int i = 1; i <= 6; i++)
    {
      int next_pos = pos + i;

      if (next_pos >= total_size)
        break;

      if (all_nodes[next_pos] != -1)
      {
        next_pos = all_nodes[next_pos] - 1;
      }
      if (!visited[next_pos])
      {
        q.push({ next_pos, moves + 1 });
        visited[next_pos] = true;
      }
    }
  }
  return -1;
}
// didnt account for dice rolls
int snakesAndLadders_not_working(std::vector<std::vector<int>>& board)
{
  std::vector<int> all_nodes;
  std::reverse(board.begin(), board.end());
  for (int row = 0; row < board.size(); row++)
  {
    std::vector<int> temp = board[row];
    if (row % 2)
    {
      std::reverse(temp.begin(), temp.end());
    }
    for (auto x : temp)
      all_nodes.push_back(x);
  }

  std::map<int, std::vector<int>> graph;
  for (int i = 0; i < all_nodes.size(); i++)
  {
    if (all_nodes[i] != -1)
    {
      graph[i].push_back(all_nodes[i] - 1);
    }
    graph[i].push_back(i + 1);
  }

  std::queue<int> q;
  std::map<int, bool> visited;
  std::map<int, int> steps;
  q.push(0);
  steps[0] = 0;

  while (!q.empty())
  {
    int curr = q.front();
    q.pop();
    visited[curr] = true;

    for (auto x : graph[curr])
    {
      if (!visited[x])
      {
        q.push(x);
        steps[x] = steps[curr] + 1;
        if (x == all_nodes.size() - 1)
          return steps[x];
      }
    }
  }
  return -1;
}

int main()
{
  std::vector<std::vector<int>> board = { { -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1 },
                                          { -1, -1, -1, -1, -1, -1 }, { -1, 35, -1, -1, 13, -1 },
                                          { -1, -1, -1, -1, -1, -1 }, { -1, 15, -1, -1, -1, -1 } };
  std::cout << snakesAndLadders(board) << std::endl;
}