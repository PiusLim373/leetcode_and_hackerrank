#include <vector>

class ListNode
{
public:
  int val;
  ListNode* next;
  ListNode(int val) : val(val), next(nullptr) {};
};

ListNode* buildListNode(std::vector<int> nums)
{
  ListNode* dummy = new ListNode(0);
  ListNode* curr = dummy;
  for (auto x : nums)
  {
    ListNode* temp = new ListNode(x);
    curr->next = temp;
    curr = curr->next;
  }
  return dummy->next;
}


ListNode* reverseList(ListNode* head)
{
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* curr = head;
    while (curr)
    {
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    dummy->next->next = nullptr;
    return prev; 
}

int main()
{
  std::vector<int> nums = { 1, 2, 3, 4, 5 };
  ListNode* head = buildListNode(nums);
  ListNode* ans = reverseList(head);
  return 0;
}