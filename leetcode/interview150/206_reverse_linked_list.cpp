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

ListNode* reverseList(ListNode* head)
{
  bool start = true;
  ListNode* next;
  ListNode* prev;
  while (head)
  {
    if (!head->next)
    {
      if (start)
        return head;
      // end of list;
      head->next = prev;
      return head;
    }
    next = head->next;
    if (start)
    {
      head->next = nullptr;
      start = false;
    }
    else
    {
      head->next = prev;
    }
    prev = head;
    head = next;
  }

  return nullptr;
}
int main()
{
  // std::vector<int> list1 = { 1, 2, 3, 4, 5 };
  std::vector<int> list1 = { 1 };

  ListNode* h1 = buildList(list1);
  ListNode* ans = reverseList(h1);

  return 0;
}