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

ListNode* removeNthFromEnd(ListNode* head, int n)
{
  ListNode dummy(0);
  dummy.next = head;

  ListNode* left = &dummy;
  ListNode* right = head;

  while (n > 0 && right)
  {
    right = right->next;
    n--;
  }

  while (right)
  {
    left = left->next;
    right = right->next;
  }

  left->next = left->next->next;

  return dummy.next;
}
ListNode* removeNthFromEndNotOptimized(ListNode* head, int n)
{
  int index = 0;
  ListNode* curr = head;
  ListNode* jumper = head;
  bool jump = true;
  while (jump)
  {
    for (int i = 0; i < n; i++)
    {
      std::cout << jumper->val << std::endl;
      jumper = jumper->next;
    }
    if (!jumper)
      return head->next;
    if (!jumper->next)
    {
      jump = false;
    }
    else
    {
      curr = curr->next;
      jumper = curr;
    }
  }

  ListNode* next = curr->next->next;
  curr->next = next;

  return head;
}
int main()
{
  // std::vector<int> list1 = { 1, 2, 3, 4, 5, 6, 7, 8 };
  std::vector<int> list1 = { 1, 2 };
  int n = 2;

  ListNode* h1 = buildList(list1);
  ListNode* ans = removeNthFromEnd(h1, n);

  return 0;
}