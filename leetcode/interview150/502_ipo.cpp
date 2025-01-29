#include <vector>
#include <queue>
int findMaximizedCapital(int k, int w, std::vector<int>& profits, std::vector<int>& capital)
{
  // min queue for cap
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>>
      cap_min_queue;

  std::priority_queue<int> profit_max_queue;
  for (int i = 0; i < capital.size(); i++)
    cap_min_queue.push({ capital[i], profits[i] });

  int curr_cap = w;
  for (int i = 0; i < k; i++)
  {
    while (!cap_min_queue.empty())
    {
      auto [cap, profit] = cap_min_queue.top();
      if (cap <= curr_cap)
      {
        profit_max_queue.push(profit);
        cap_min_queue.pop();
      }
      else
      {
        break;
      }
    }
    if (profit_max_queue.empty())
      break;
    int profit = profit_max_queue.top();
    profit_max_queue.pop();
    curr_cap += profit;
  }
  return curr_cap;
}
int main()
{
  int k = 3;
  int w = 0;
  std::vector<int> profits = {  };
  std::vector<int> capital = {  };
  int ans = findMaximizedCapital(k, w, profits, capital);
  return 0;
}