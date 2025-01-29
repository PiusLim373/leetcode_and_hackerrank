#include <vector>

struct ListNode
{
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL)
  {
  }
};

bool hasCycle(ListNode* head)
{
  ListNode* fast = head;
  ListNode* slow = head;

  while (fast)
  {
    slow = slow->next;
    if (fast->next && fast->next->next)
      fast = fast->next->next;
    else
      return false;
    if (slow == fast)
      return true;
  }
  return false;
}

ListNode* buildList(std::vector<int>& data, int pos, int& index, ListNode* loop)
{
  ListNode* head = new ListNode(data[index]);
  if (index == pos)
    loop = head;
  index++;
  if (index > data.size())
  {
    head->next = loop;
  }
  else
  {
    head->next = buildList(data, pos, index, loop);
  }
  return head;
}

int main()
{
  std::vector<int> head = { 3, 2, 0, -4 };
  int pos = 1;

  int index = 0;
  ListNode* h = buildList(head, pos, index, nullptr);
  bool has_cycle = hasCycle(h);
  return 0;
}