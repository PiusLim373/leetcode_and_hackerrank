#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *buildTree(std::vector<int> &nums, int pos)
{
    ListNode *dummy = new ListNode();
    ListNode *curr = new ListNode(nums[0]);
    ListNode *cycle = nullptr;
    dummy->next = curr;
    if (pos == 0)
        cycle = dummy->next;
    for (int i = 1; i < nums.size(); i++)
    {
        auto temp = new ListNode(nums[i]);
        curr->next = temp;
        curr = curr->next;
        if (i == pos)
            cycle = curr;
    }
    curr->next = cycle;
    return dummy->next;
}

ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    bool found = false;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            found = true;
            break;
        }
    }
    if (!found)
        return nullptr;
    slow = head;
    while (true)
    {
        if (slow == fast)
            return slow;
        slow = slow->next;
        fast = fast->next;
    }
    return nullptr;
}

int main()
{
    std::vector<int> nums = {12};
    int pos = -1;

    auto head = buildTree(nums, pos);
    auto ans = detectCycle(head);
    return 0;
}