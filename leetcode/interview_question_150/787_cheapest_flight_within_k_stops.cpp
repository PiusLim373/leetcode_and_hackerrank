#include <queue>
#include <vector>
#include <map>
#include <iostream>

int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int k)
{
  std::map<int, std::vector<std::pair<int, int>>> skyscanner;
  for (auto x : flights)
  {
    skyscanner[x[0]].push_back({ x[1], x[2] });
  }

  std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>,
                      std::greater<std::tuple<int, int, int>>>
      queue;  // cost, curr
  std::vector<std::vector<int>> cost_from_src(n, std::vector<int>(k + 2, INT16_MAX));
  cost_from_src[src][0] = 0;
  queue.push({ 0, src, 0 });

  while (!queue.empty())
  {
    auto [curr_cost, curr_city, curr_stops] = queue.top();
    queue.pop();

    if (curr_city == dst)
    {
      for (auto x: cost_from_src)
      {
        for(auto y: x)
            std::cout <<y <<" ";
        std::cout << std::endl;
      }
      return curr_cost;
    }

    if (curr_stops > k)
      continue;

    // if (cost > cost_from_src[])
    for (auto neigh : skyscanner[curr_city])
    {
      int new_cost = curr_cost + neigh.second;
      if (new_cost < cost_from_src[neigh.first][curr_stops + 1])
      {
        cost_from_src[neigh.first][curr_stops + 1] = new_cost;
        queue.push({ new_cost, neigh.first, curr_stops + 1 });
      }
    }
  }

  return -1;
}

int findCheapestPriceNoStops(int n, std::vector<std::vector<int>>& flights, int src, int dst, int k)
{
  std::map<int, std::vector<std::pair<int, int>>> skyscanner;
  for (auto x : flights)
  {
    skyscanner[x[0]].push_back({ x[1], x[2] });
  }

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>>
      queue;  // cost, curr
  std::vector<int> cost_from_src(n, INT16_MAX);
  cost_from_src[src] = 0;
  queue.push({ 0, src });

  while (!queue.empty())
  {
    auto [curr_cost, curr_city] = queue.top();
    queue.pop();

    if (curr_city == dst)
      break;

    if (curr_cost > cost_from_src[curr_city])
      continue;

    // if (cost > cost_from_src[])
    for (auto neigh : skyscanner[curr_city])
    {
      int new_cost = curr_cost + neigh.second;
      if (new_cost < cost_from_src[neigh.first])
      {
        cost_from_src[neigh.first] = new_cost;
        queue.push({ new_cost, neigh.first });
      }
    }
  }

  return 0;
}

int main()
{
  int n = 4;
  std::vector<std::vector<int>> flights = { { 0, 1, 100 }, { 1, 2, 100 }, { 2, 0, 100 }, { 1, 3, 600 }, { 2, 3, 200 } };
  int src = 0;
  int dst = 3;
  int k = 1;
  auto ans = findCheapestPrice(n, flights, src, dst, k);
  return 0;
}