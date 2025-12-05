#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
    dummy, groupprev, groupnext, kth, curr, temp, prev


*/
ListNode *buildTree(std::vector<int> &nums)
{
    if (!nums.size())
        return nullptr;
    ListNode *root = new ListNode(nums[0]);
    ListNode *curr = root;

    for (int i = 1; i < nums.size(); i++)
    {
        curr->next = new ListNode(nums[i]);
        curr = curr->next;
    }
    return root;
}

ListNode *getKthNode(ListNode *curr, int k)
{
    while (k-- && curr)
        curr = curr->next;
    return curr;
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    if (k == 1)
        return head;
    ListNode *dummy = new ListNode(0, head);
    ListNode *group_prev = dummy;

    while (true)
    {
        ListNode *kth = getKthNode(group_prev, k); // 2
        if (!kth)
            break;
        ListNode *group_next = kth->next;

        ListNode *prev = group_next;
        ListNode *curr = group_prev->next;
        while (curr != group_next)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        ListNode *temp = group_prev->next; // 1
        group_prev->next = kth;            // 2
        group_prev = temp;                 // 1
    }
    return dummy->next;
}
ListNode *reverseKGroupBuged(ListNode *head, int k)
{
    if (k == 1)
        return head;
    ListNode *dummy = new ListNode();
    dummy->next = head;
    ListNode *ori = dummy;

    ListNode *prev = head;
    ListNode *start = head;
    ListNode *curr = head->next;
    int count = 2;
    while (curr)
    {
        while (count <= k)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            count++;
        }
        start->next = curr;
        start = curr;
        curr = curr->next;
        prev = start;
        count = 2;
        ori->next = start;
    }

    return dummy->next;
}
int main()
{
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int k = 2;
    auto head = buildTree(nums);
    auto ans = reverseKGroup(head, k);
    return 0;
}
