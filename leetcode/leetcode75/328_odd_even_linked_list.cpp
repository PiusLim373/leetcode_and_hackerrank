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

ListNode *oddEvenList(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    bool is_odd = true;
    ListNode *last_odd = new ListNode(0);
    ListNode *first_even = nullptr;
    ListNode *last_even = nullptr;
    ListNode *curr = head;
    while (curr)
    {
        if (is_odd)
        {
            last_odd->next = curr;
            last_odd = curr;
            is_odd = false;
        }
        else
        {
            if (!first_even)
            {
                first_even = curr;
            }
            else
            {
                last_even->next = curr;
            }
            last_even = curr;
            is_odd = true;
        }
        curr = curr->next;
    }
    last_odd->next = first_even;
    last_even -> next = nullptr;
    return dummy->next;
}
int main()
{
    // std::vector<int> data = {1, 2, 3, 4, 5};
    std::vector<int> data = {1};

    ListNode *head = buildList(data);
    ListNode *ans = oddEvenList(head);
    return 0;
}