#include <iostream>
#include <vector>
#include <algorithm>
struct ListNode
{
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr)
  {
  }
  ListNode(int x) : val(x), next(nullptr)
  {
  }
  ListNode(int x, ListNode* next) : val(x), next(next)
  {
  }
};

ListNode* buildList(std::vector<int> num, int index)
{
  if (index > num.size() - 1)
    return nullptr;
  ListNode* head = new ListNode(num[index]);
  head->next = buildList(num, index + 1);
  return head;
}

ListNode* getMid(ListNode* head)
{
  ListNode* slow = head;
  ListNode* fast = head->next;

  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

ListNode* mergeList(ListNode* list1, ListNode* list2)
{
  ListNode dummy(0);
  ListNode* tail = &dummy;
//   ListNode* tail = new ListNode();
  while (list1 && list2)
  {
    if (list1->val < list2->val)
    {
      tail->next = list1;
      list1 = list1->next;
    }
    else
    {
      tail->next = list2;
      list2 = list2->next;
    }
    tail = tail->next;
  }
  if (list1)
    tail->next = list1;
  if (list2)
    tail->next = list2;

  return dummy.next;
}

ListNode* sortList(ListNode* head)
{
  if (!head || !head->next)
    return head;
  ListNode* left = head;
  ListNode* mid = getMid(head);
  ListNode* right = mid->next;
  mid->next = nullptr;

  left = sortList(left);
  right = sortList(right);
  return mergeList(left, right);
}

ListNode* sortList_memory_out(ListNode* head)
{
  std::vector<int> list;
  while (head != nullptr)
  {
    list.push_back(head->val);
    head = head->next;
  }
  std::sort(list.begin(), list.end());
  if (!list.size())
    return nullptr;
  ListNode* ans = buildList(list, 0);
  return ans;
}
int main()
{
  std::vector<int> nums = { -1, 5, 3, 4, 0 };
  ListNode* head = buildList(nums, 0);
  ListNode* ans = sortList(head);
  return 0;
}