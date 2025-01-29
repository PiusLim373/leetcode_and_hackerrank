#include <vector>
#include <unordered_map>
#include <iostream>
class DoublyListNode
{
public:
  int key;
  int val;
  DoublyListNode* next;
  DoublyListNode* prev;
  DoublyListNode() : key(0), val(0), next(nullptr), prev(nullptr) {};
  DoublyListNode(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {};
};
class LRUCache
{
private:
  std::unordered_map<int, DoublyListNode*> cache;
  int max_capacity;

  DoublyListNode* most_recent = new DoublyListNode(0, 0);
  DoublyListNode* least_recent = new DoublyListNode(0, 0);

public:
  LRUCache(int capacity)
  {
    max_capacity = capacity;
    most_recent->prev = least_recent;
    least_recent->next = most_recent;
  }

  int get(int key)
  {
    DoublyListNode* target = nullptr;
    if (cache.count(key))
        target = cache[key];
    if (target == nullptr)
      return -1;
    else
    {
      _remove_from_list(target);
      _insert_at_right(target);
      return target->val;
    }
  }

  void put(int key, int value)
  {
    DoublyListNode* target = nullptr;
    if (cache.count(key))
        target = cache[key];
    if (target == nullptr)
    {
      DoublyListNode* temp = new DoublyListNode(key, value);
      cache[key] = temp;
      _insert_at_right(temp);
    }
    else
    {
      target->val = value;
      _remove_from_list(target);
      _insert_at_right(target);
    }

    if (cache.size() > max_capacity)
    {
      cache.erase(least_recent->next->key);
      _remove_from_list(least_recent->next);
    }
  }

  void _remove_from_list(DoublyListNode* target)
  {
    target->prev->next = target->next;
    target->next->prev = target->prev;
  }

  void _insert_at_right(DoublyListNode* target)
  {
    most_recent->prev->next = target;
    target->prev = most_recent->prev;
    target->next = most_recent;
    most_recent->prev = target;
  }
};

int main()
{
//   LRUCache lRUCache(2);
//   lRUCache.put(1, 1);                         // cache is {1=1}
//   lRUCache.put(2, 2);                         // cache is {1=1, 2=2}
//   std::cout << lRUCache.get(1) << std::endl;  // return 1
//   lRUCache.put(2, 3);                         // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
//   std::cout << lRUCache.get(2) << std::endl;  // returns -1 (not found)
//   lRUCache.put(4, 4);                         // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
//   std::cout << lRUCache.get(1) << std::endl;  // return -1 (not found)
//   std::cout << lRUCache.get(3) << std::endl;  // return 3
//   std::cout << lRUCache.get(4) << std::endl;  // return 4



  LRUCache lRUCache(1);
  std::cout << lRUCache.get(6) << std::endl; 
  std::cout << lRUCache.get(8) << std::endl; 
  lRUCache.put(12, 1);                         // cache is {1=1}
  std::cout << lRUCache.get(2) << std::endl; 
  lRUCache.put(15, 11);                         // cache is {1=1}
  lRUCache.put(5, 2);                         // cache is {1=1}
  lRUCache.put(1, 15);                         // cache is {1=1}
  lRUCache.put(4, 2);                         // cache is {1=1}
  std::cout << lRUCache.get(4) << std::endl;  // return 1
  lRUCache.put(15, 15);                         // cache is {1=1}

  return 0;
}