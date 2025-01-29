#include <vector>
#include <queue>
#include <map>
#include <iostream>

class Graph
{
private:
  std::vector<std::vector<int>> grid_map;

public:
  Graph(std::vector<std::vector<int>> grid_map) : grid_map(grid_map) {};
  void find_path(std::pair<int, int> start, std::pair<int, int> dest)
  {
    int max_row = grid_map.size();
    int max_col = grid_map[0].size();
    int dist_to_target = 0;
    std::vector<std::pair<int, int>> dirs = { { -1, 0 },  { 1, 0 },  { 0, 1 },  { 0, -1 },
                                              { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } };
    std::map<std::pair<int, int>, bool> visited;
    std::map<std::pair<int, int>, std::pair<int, int>> comes_from;
    std::queue<std::tuple<int, int, int>> queue;  // x,y,dist

    comes_from[start] = { -1, -1 };
    queue.push({ start.first, start.second, 0 });
    visited[start] = true;
    bool found = false;
    while (!found && !queue.empty())
    {
      auto [curr_row, curr_col, dist] = queue.front();
      queue.pop();

      for (auto dir : dirs)
      {
        int check_row = curr_row + dir.first;
        int check_col = curr_col + dir.second;

        if (check_row == dest.first && check_col == dest.second)
        {
          dist_to_target = dist + 1;
          comes_from[{ check_row, check_col }] = { curr_row, curr_col };
          found = true;
          break;
        }

        if (check_row >= 0 && check_row < max_row && check_col >= 0 && check_col < max_col &&
            !visited[{ check_row, check_col }] && grid_map[check_row][check_col] != 0)
        {
          visited[{ check_row, check_col }] = true;
          queue.push({ check_row, check_col, dist + 1 });
          comes_from[{ check_row, check_col }] = { curr_row, curr_col };
        }
      }
    }

    std::cout << "found target in " << dist_to_target << "steps" << std::endl;
    std::pair<int, int> backtrack = dest;

    while (backtrack.first != -1)
    {
      std::cout << "( " << backtrack.first << ", " << backtrack.second << " ) <-";
      backtrack = comes_from[backtrack];
    }
  }

  // Manhattan Distance Heuristic
  int manhattan_distance(std::pair<int, int> start, std::pair<int, int> goal)
  {
    return std::abs(start.first - goal.first) + std::abs(start.second - goal.second);
  }

  // A* Pathfinding Algorithm
  void find_path_a_star(std::pair<int, int> start, std::pair<int, int> dest)
  {
    int max_row = grid_map.size();
    int max_col = grid_map[0].size();

    // Edge case: Check if start or destination are blocked or out of bounds
    if (start.first < 0 || start.first >= max_row || start.second < 0 || start.second >= max_col ||
        grid_map[start.first][start.second] == 0 || dest.first < 0 || dest.first >= max_row || dest.second < 0 ||
        dest.second >= max_col || grid_map[dest.first][dest.second] == 0)
    {
      std::cout << "Invalid start or destination!" << std::endl;
      return;
    }

    // A* specific structures
    std::map<std::pair<int, int>, std::pair<int, int>> came_from;  // To reconstruct the path
    std::map<std::pair<int, int>, int> g_score;                    // g(n) - cost to reach a node
    std::map<std::pair<int, int>, int> f_score;                    // f(n) = g(n) + h(n) - total estimated cost

    for (int i = 0; i < max_row; ++i)
    {
      for (int j = 0; j < max_col; ++j)
      {
        g_score[{ i, j }] = INT16_MAX;  // Initialize all scores to infinity
        f_score[{ i, j }] = INT16_MAX;
      }
    }

    // Starting point
    g_score[start] = 0;
    f_score[start] = manhattan_distance(start, dest);

    // Priority queue to explore nodes based on f_score (min-heap)
    auto cmp = [&f_score](std::pair<int, int> left, std::pair<int, int> right) {
      return f_score[left] > f_score[right];  // Min-heap: prioritize nodes with lower f_score
    };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> open_set(cmp);
    open_set.push(start);

    std::vector<std::pair<int, int>> dirs = { { -1, 0 },  { 1, 0 },  { 0, 1 },  { 0, -1 },
                                              { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } };  // Directions: 8 neighbors

    bool found = false;
    while (!open_set.empty())
    {
      // Get the node with the lowest f_score
      auto current = open_set.top();
      open_set.pop();

      if (current == dest)
      {
        found = true;
        break;
      }

      // Explore neighbors
      for (auto dir : dirs)
      {
        int check_row = current.first + dir.first;
        int check_col = current.second + dir.second;

        if (check_row >= 0 && check_row < max_row && check_col >= 0 && check_col < max_col &&
            grid_map[check_row][check_col] != 0)  // Valid cell and not blocked
        {
          int tentative_g_score = g_score[current] + 1;  // Assuming each move has cost 1

          if (tentative_g_score < g_score[{ check_row, check_col }])
          {
            came_from[{ check_row, check_col }] = current;
            g_score[{ check_row, check_col }] = tentative_g_score;
            f_score[{ check_row, check_col }] =
                g_score[{ check_row, check_col }] + manhattan_distance({ check_row, check_col }, dest);
            open_set.push({ check_row, check_col });
          }
        }
      }
    }

    // Path reconstruction if the destination is found
    if (found)
    {
      std::cout << "Found target!" << std::endl;
      std::pair<int, int> backtrack = dest;
      std::vector<std::pair<int, int>> path;

      // Backtrack to reconstruct the path
      while (backtrack != start)
      {
        path.push_back(backtrack);
        backtrack = came_from[backtrack];
      }
      path.push_back(start);

      // Output the path from start to destination
      std::cout << "Path: ";
      for (auto it = path.rbegin(); it != path.rend(); ++it)
      {
        std::cout << "(" << it->first << ", " << it->second << ") ";
      }
      std::cout << std::endl;
    }
    else
    {
      std::cout << "No path found!" << std::endl;
    }
  }
};

int main()
{
  std::vector<std::vector<int>> grid_map{
    { 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 0, 0, 1, 1 }, { 1, 1, 1, 0, 0, 1, 1 }, { 1, 1, 1, 0, 0, 1, 1 },
    { 1, 1, 1, 0, 0, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1, 1, 1 },
  };

  std::pair<int, int> start = { 3, 1 };
  std::pair<int, int> dest = { 4, 5 };

  Graph g(grid_map);
  g.find_path(start, dest);
  return 0;
}

/*

{1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 0, 0, 1, 1},
{1, 1, 1, 0, 0, 1, 1},
{1, A, 1, 0, 0, 1, 1},
{1, 1, 1, 0, 0, B, 1},
{1, 1, 1, 1, 1, 1, 1},
{1, 1, 1, 1, 1, 1, 1},

*/