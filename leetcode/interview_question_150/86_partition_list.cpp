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

ListNode* partition(ListNode* head, int x)
{
  ListNode* left = new ListNode(0);
  ListNode* right = new ListNode(0);
  ListNode* left_tail = left;
  ListNode* right_tail = right;

  while (head)
  {
    if (head->val < x)
    {
      left_tail->next = head;
      left_tail = left_tail->next;
    }
    else
    {
      right_tail->next = head;
      right_tail = right_tail->next;
    }
    head = head->next;
  }
  right_tail->next = nullptr;
  left_tail->next = right->next;
  return left->next;
}
ListNode* partitionNotOptimzed(ListNode* head, int x)
{
  if (!head)
    return nullptr;
  ListNode* dummy = new ListNode(0);
  dummy->next = head;

  ListNode* curr = head;
  ListNode* last_valid = dummy;
  ListNode* invalid_start = nullptr;
  ListNode* invalid_end = nullptr;

  bool is_valid = true;
  while (curr)
  {
    if (curr->val < x)
    {
      if (!is_valid)
      {
        // recovered from invalid node, need to join the last valid to curr node
        last_valid->next = curr;
        is_valid = true;
      }
      last_valid = curr;
    }

    else
    {
      if (is_valid)
      {
        if (invalid_end != nullptr)
        {
          // encountered invalud node once again, joining curr node to the last invalid
          invalid_end->next = curr;
          invalid_end = curr;
        }
        else
        {
          // first encounter invalid node
          invalid_start = curr;
          invalid_end = curr;
        }
        is_valid = false;
      }
      else
      {
        // has encountered invalud node before, update ending invalid
        invalid_end = curr;
      }
    }
    if (!curr->next)
      break;
    curr = curr->next;
  }

  // ending
  // after ended, join the curr-> with invalid start if last node is valid
  last_valid->next = invalid_start;
  if (invalid_end)
    invalid_end->next = nullptr;
  return dummy->next;
}
int main()
{
  std::vector<int> list1 = { 1, 4, 3, 0, 5, 2 };
  int x = 2;

  ListNode* h1 = buildList(list1);
  ListNode* ans = partition(h1, x);

  return 0;
}