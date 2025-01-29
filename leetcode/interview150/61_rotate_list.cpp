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

ListNode* rotateRight(ListNode* head, int k)
{
  if (!head)
    return nullptr;
  if (!head->next)
    return head;

  // count how many rotation needed
  int count = 0;
  ListNode* counter = head;
  while (counter)
  {
    counter = counter->next;
    count++;
  }
  int rotation = k % count;

  ListNode* right;
  ListNode* left;
  ListNode* dummy = new ListNode(0);

  for (int i = 0; i < rotation; i++)
  {
    left = head;
    right = head->next;
    dummy->next = head;

    while (right->next)
    {
      right = right->next;
      left = left->next;
    }
    left->next = nullptr;
    right->next = dummy->next;

    head = right;
  }
  return head;
}
ListNode* rotateRightNotFullRotation(ListNode* head, int k)
{
  ListNode* dummy = new ListNode(0);
  dummy->next = head;

  ListNode* left = head;
  ListNode* right = head;

  for (int i = 0; i < k; i++)
  {
    right = right->next;
  }

  while (right->next)
  {
    right = right->next;
    left = left->next;
  }
  ListNode* ans = left->next;
  left->next = nullptr;
  right->next = dummy->next;
  return ans;
}
int main()
{
  std::vector<int> list1 = { 1, 2, 3 };
  int k = 2000000000;

  ListNode* h1 = buildList(list1);
  ListNode* ans = rotateRight(h1, k);

  return 0;
}