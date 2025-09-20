#include <vector>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *buildList(std::vector<int> data)
{
    ListNode *head = new ListNode(data[0]);
    ListNode *prev = head;
    for (int i = 1; i < data.size(); i++)
    {
        ListNode *curr = new ListNode(data[i]);
        prev->next = curr;
        prev = curr;
    }
    return head;
}

ListNode *deleteMiddle(ListNode *head)
{
    if (!head->next)
        return nullptr;

    ListNode *prev = head;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next && fast->next->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast->next)
    {
        // even num case
        slow->next = slow->next->next;
    }
    else
    {
        // off number case, slow stop exactly at middle
        prev->next = slow->next;
    }
    return head;
}

int main()
{
    // std::vector<int> data = {1, 3, 4, 7, 1, 2, 6};
    // std::vector<int> data = {1, 2, 3, 4};
    std::vector<int> data = {2, 1};

    ListNode *head = buildList(data);
    ListNode *deleted = deleteMiddle(head);
    return 0;
}