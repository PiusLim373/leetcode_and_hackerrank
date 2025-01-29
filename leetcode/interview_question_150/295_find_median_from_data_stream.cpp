#include <iostream>
#include <queue>

class MedianFinder
{
private:
  std::priority_queue<int, std::vector<int>, std::greater<>> max_pq;  // top() return smallest
  std::priority_queue<int, std::vector<int>, std::less<>> min_pq;     // top() return greatest

public:
  MedianFinder()
  {
  }

  void addNum(int num)
  {
    min_pq.push(num);

    max_pq.push(min_pq.top());
    min_pq.pop();

    if (max_pq.size() > min_pq.size())
    {
      min_pq.push(max_pq.top());
      max_pq.pop();
    }
  }

  double findMedian()
  {
    if (min_pq.size() == max_pq.size())
      return (min_pq.top() + max_pq.top()) / 2.0;
    else if (min_pq.size() > max_pq.size())
      return min_pq.top();
    return max_pq.top();
  }
};

class MedianFinderNotWorking2
{
private:
  std::priority_queue<int, std::vector<int>, std::greater<>> max_pq;  // top() return smallest
  std::priority_queue<int, std::vector<int>, std::less<>> min_pq;     // top() return greatest

public:
  MedianFinderNotWorking2()
  {
  }

  void addNum(int num)
  {
    min_pq.push(num);
    if (min_pq.size() && max_pq.size() && min_pq.top() > max_pq.size())
    {
      int temp = min_pq.top();
      min_pq.pop();
      max_pq.push(temp);
    }

    // fix uneven
    if (min_pq.size() > max_pq.size() + 1)
    {
      int temp = min_pq.top();
      min_pq.pop();
      max_pq.push(temp);
    }

    if (max_pq.size() > min_pq.size() + 1)
    {
      int temp = max_pq.top();
      max_pq.pop();
      min_pq.push(temp);
    }
  }

  double findMedian()
  {
    if (min_pq.size() == max_pq.size())
      return (min_pq.top() + max_pq.top()) / 2.0;
    else if (min_pq.size() > max_pq.size())
      return min_pq.top();
    return max_pq.top();
  }
};

class MedianFinderNotWorking
{
private:
  std::priority_queue<int, std::vector<int>, std::greater<>> max_pq;  // top() return smallest
  std::priority_queue<int, std::vector<int>, std::less<>> min_pq;     // top() return greatest

public:
  MedianFinderNotWorking()
  {
  }

  void addNum(int num)
  {
    min_pq.push(num);

    if (abs(min_pq.size() - max_pq.size()) > 1)
    {
      // rebalancing
      int temp = min_pq.top();
      min_pq.pop();
      max_pq.push(temp);
    }
    if (max_pq.size() && (min_pq.top() > max_pq.top()))
    {
      int temp = min_pq.top();
      min_pq.pop();
      max_pq.push(temp);
    }
    if (max_pq.size() && (abs(min_pq.size() - max_pq.size()) > 1) && (min_pq.top() < max_pq.top()))
    {
      // transfer back
      int temp = max_pq.top();
      max_pq.pop();
      min_pq.push(temp);
    }
  }

  double findMedian()
  {
    if (min_pq.size() == max_pq.size())
      return (min_pq.top() + max_pq.top()) / 2.0;
    else if (min_pq.size() > max_pq.size())
      return min_pq.top();
    return max_pq.top();
  }
};

int main()
{
  MedianFinder* obj = new MedianFinder();
  obj->addNum(3);
  obj->addNum(2);
  std::cout << obj->findMedian() << std::endl;
  obj->addNum(7);
  obj->addNum(4);
  std::cout << obj->findMedian() << std::endl;
  return 0;
}