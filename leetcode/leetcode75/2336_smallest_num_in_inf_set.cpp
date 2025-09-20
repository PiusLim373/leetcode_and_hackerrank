#include <queue>
#include <iostream>
#include <vector>
#include <set>

class SmallestInfiniteSet
{
public:
    std::vector<bool> present;
    SmallestInfiniteSet()
    {
        for (int i = 0; i < 1002; i++)
        {
            present.push_back(true);
        }
    }

    int popSmallest()
    {
        for (int i = 1; i < present.size(); i++)
        {
            if (present[i])
            {
                present[i] = false;
                return i;
            }
        }
        return -1;
    }

    void addBack(int num)
    {
        present[num] = true;
    }
};
class SmallestInfiniteSet2
{
public:
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    std::set<int> s;
    SmallestInfiniteSet2()
    {
        for (int i = 1; i < 1001; i++)
        {
            pq.push(i);
            s.insert(i);
        }
    }

    int popSmallest()
    {
        int top = pq.top();
        pq.pop();
        s.erase(top);
        return top;
    }

    void addBack(int num)
    {
        if (s.find(num) == s.end())
            pq.push(num);
    }
};

int main()
{
    // SmallestInfiniteSet smallestInfiniteSet = SmallestInfiniteSet();
    // smallestInfiniteSet.addBack(2);    // 2 is already in the set, so no change is made.
    // std::cout << smallestInfiniteSet.popSmallest() << "\n"; // return 1, since 1 is the smallest number, and remove it from the set.
    // std::cout << smallestInfiniteSet.popSmallest() << "\n"; // return 2, and remove it from the set.
    // std::cout << smallestInfiniteSet.popSmallest() << "\n"; // return 3, and remove it from the set.
    // smallestInfiniteSet.addBack(1);    // 1 is added back to the set.
    // std::cout << smallestInfiniteSet.popSmallest() << "\n"; // return 1, since 1 was added back to the set and
    //                                    // is the smallest number, and remove it from the set.
    // std::cout << smallestInfiniteSet.popSmallest() << "\n"; // return 4, and remove it from the set.
    // std::cout << smallestInfiniteSet.popSmallest() << "\n"; // return 5, and remove it from the set.

    SmallestInfiniteSet smallestInfiniteSet = SmallestInfiniteSet();
    std::cout << smallestInfiniteSet.popSmallest() << "\n";
    smallestInfiniteSet.addBack(1);
    std::cout << smallestInfiniteSet.popSmallest() << "\n";
    std::cout << smallestInfiniteSet.popSmallest() << "\n";
    std::cout << smallestInfiniteSet.popSmallest() << "\n";
    smallestInfiniteSet.addBack(2);
    smallestInfiniteSet.addBack(3);
    std::cout << smallestInfiniteSet.popSmallest() << "\n";
    std::cout << smallestInfiniteSet.popSmallest() << "\n";
}