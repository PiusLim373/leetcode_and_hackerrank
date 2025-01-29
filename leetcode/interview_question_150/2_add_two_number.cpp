#include <vector>
#include <math.h>
#include <string>
#include <iostream>
#include <algorithm>
struct ListNode
{
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL)
  {
  }
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
  ListNode* head = new ListNode(0);
  ListNode* current = head;

  int round = 0;
  while (l1 || l2 || round)
  {
    int sum = round;
    if (l1)
    {
      sum += l1->val;
      l1 = l1->next;
    }
    if (l2)
    {
      sum += l2->val;
      l2 = l2->next;
    }
    round = 0;

    ListNode* temp = new ListNode(sum % 10);
    if (sum >= 10)
      round = 1;

    current->next = temp;
    current = temp;
  }

  return head->next;
}
ListNode* addTwoNumbers_too_small(ListNode* l1, ListNode* l2)
{
  int sum = 0;
  int multiplier = 0;
  ListNode* pointer = l1;
  while (pointer)
  {
    sum += pointer->val * pow(10, multiplier);
    pointer = pointer->next;
    multiplier++;
  }
  multiplier = 0;
  pointer = l2;
  while (pointer)
  {
    sum += pointer->val * pow(10, multiplier);
    pointer = pointer->next;
    multiplier++;
  }

  std::string ans_str = std::to_string(sum);
  std::reverse(ans_str.begin(), ans_str.end());
  ListNode* head = new ListNode(ans_str[0] - '0');
  ListNode* current = head;
  for (int i = 1; i < ans_str.size(); i++)
  {
    ListNode* temp = new ListNode(ans_str[i] - '0');
    current->next = temp;
    current = temp;
  }
  return head;
}

ListNode* buildList(std::vector<int>& nums)
{
  ListNode* head = new ListNode(nums[0]);
  ListNode* current = head;
  for (int i = 1; i < nums.size(); i++)
  {
    ListNode* temp = new ListNode(nums[i]);
    current->next = temp;
    current = temp;
  }

  return head;
}

int main()
{
    std::vector<int> l1 = { 9, 9, 9, 9, 9, 9 };
    std::vector<int> l2 = { 9, 9, 9, 9 };
//   std::vector<int> l1 = { 2, 4, 5 };
//   std::vector<int> l2 = { 5, 6, 4 };
  ListNode* h1 = buildList(l1);
  ListNode* h2 = buildList(l2);

  ListNode* ans = addTwoNumbers(h1, h2);
  return 0;
}