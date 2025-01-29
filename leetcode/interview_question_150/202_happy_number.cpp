#include <map>
#include <string>
#include <math.h>
bool isHappy(int n)
{
  std::map<int, bool> visited;
  int check = n;
  bool found = false;
  while (true)
  {
    std::string num_str = std::to_string(check);
    int sum = 0;
    for (auto x : num_str)
    {
      sum += pow(x - '0', 2);
    }
    if (sum == 1)
      return true;
    else if (!visited.count(sum))
    {
      visited[sum] = true;
      check = sum;
    }
    else if (sum != 1)
      return false;
    else
      return true;
  }
}
int main()
{
  int n = 40;
  bool ans = isHappy(n);
  return 0;
}