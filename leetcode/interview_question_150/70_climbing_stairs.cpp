#include <vector>

int climbStairs(int n)
{
  if (n == 1)
    return 1;
  if (n == 2)
    return 2;

  int one = 1;
  int two = 1;
  int sum = 0;
  for (int i = 2; i <= n; i++)
  {
    sum = one + two;
    one = two;
    two = sum;
  }
  return sum;
}

int main()
{
  int n = 3;
  auto ans = climbStairs(n);

  return 0;
}