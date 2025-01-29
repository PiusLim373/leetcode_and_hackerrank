#include <vector>
#include <iostream>
class ListNode
{
public:
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {};
  ListNode(int num, ListNode* next) : val(num), next(next) {};
  ListNode(int num)
  {
    this->val = num;
    this->next = nullptr;
  }
};

ListNode* buildList(std::vector<int> nums)
{
  ListNode* dummy = new ListNode(0);
  ListNode* current = dummy;

  for (auto x : nums)
  {
    ListNode* temp = new ListNode(x);
    current->next = temp;
    current = temp;
  }
  return dummy->next;
}

ListNode* reverseBetween(ListNode* head, int left, int right)
{
  ListNode dummy(0);
  dummy.next = head;

  ListNode* curr = head;
  ListNode* next;
  ListNode* left_prev = &dummy;
  int index = 1;
  // loop until left index
  while (index < left)
  {
    left_prev = curr;
    curr = curr->next;
    index++;
  }

  // loop for the swap
  ListNode* prev = nullptr;
  while (index <= right)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    index++;
  }

  // fill back pointers
  left_prev->next->next = curr;
  left_prev->next = prev;

  return dummy.next;
}

ListNode* reverseBetween_not_optimized(ListNode* head, int left, int right)
{
  if (left == right)
    return head;
  ListNode* begin = head;
  ListNode* next;
  ListNode* prev = nullptr;
  ListNode* start;
  ListNode* left_edge;
  bool right_index_end = false;
  int index = 1;

  while (index < left)
  {
    prev = head;
    head = head->next;
    if (!head->next)
    {
      // not yet reach left list ended
      return begin;
    }
    index++;
  }

  next = head->next;
  bool beginning = true;
  left_edge = prev;  // number1
  start = head;      // number2

  while (index <= right)
  {
    next = head->next;
    if (beginning && (right - left) > 1)
    {
      beginning = false;
    }
    else
    {
      head->next = prev;
    }
    prev = head;
    if (!next)
    {
      // last element
      right_index_end = true;
      break;
    }
    else
      head = next;
    index++;
  }
  start->next = nullptr;
  if (left_edge == nullptr)
  {
    // left index = start
    left_edge = prev;
    begin = left_edge;
  }
  else
  {
    left_edge->next = prev;  // 1 point to 4
  }
  if (!right_index_end)
    start->next = head;  // 2 point to 5
  head = next;

  while (head)
  {
    head = head->next;
  }

  return begin;
}
int main()
{
  // std::vector<int> list1 = { 1, 2, 3, 4, 5 };
  std::vector<int> list1 = { 3, 5 };
  int left = 1;
  int right = 2;

  ListNode* h1 = buildList(list1);
  ListNode* ans = reverseBetween(h1, left, right);

  return 0;
}