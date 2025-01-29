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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
  ListNode dummy(0);
  ListNode* current = &dummy;
  while (list1 && list2)
  {
    if (list1->val <= list2->val)
    {
      current->next = list1;
      list1 = list1->next;
    }
    else
    {
      current->next = list2;
      list2 = list2->next;
    }
    current = current->next;
  }
  if (list1)
    current->next = list1;
  if (list2)
    current->next = list2;
  return dummy.next;
}

int main()
{
  std::vector<int> list1 = { 1, 2, 4 };
  std::vector<int> list2 = { 1, 3, 4 };

  ListNode* h1 = buildList(list1);
  ListNode* h2 = buildList(list2);
  ListNode* merged = mergeTwoLists(h1, h2);

  return 0;
}