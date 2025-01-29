#include <vector>
#include <iostream>
#include <map>
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
ListNode* deleteDuplicates(ListNode* head)
{
  ListNode dummy(0);
  dummy.next = head;
  ListNode* prev_valid = &dummy;
  int value = 100;
  ListNode* curr = head;
  while (curr && curr->next)
  {
    if (curr->val != curr->next->val)
    {
      prev_valid = curr;
      curr = curr->next;
    }
    else
    {
      value = curr->val;
      while (curr && curr->val == value)
      {
        curr = curr->next;
      }
      prev_valid->next = curr;
    }
  }
  return dummy.next;
}
int main()
{
  std::vector<int> list1 = { };

  ListNode* h1 = buildList(list1);
  ListNode* ans = deleteDuplicates(h1);

  return 0;
}