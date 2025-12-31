#include <vector>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *buildList(std::vector<int> &nums)
{
    ListNode *dummy = new ListNode(0);
    ListNode *curr = new ListNode(nums[0]);
    dummy->next = curr;

    for (int i = 1; i < nums.size(); i++)
    {
        ListNode *temp = new ListNode(nums[i]);
        curr->next = temp;
        curr = curr->next;
    }
    return dummy->next;
}

ListNode *swapPairs(ListNode *head)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *curr = head, *prev = dummy;

    while (curr && curr->next) // make sure there is a pair to swap
    {
        // curr is the first
        ListNode *next_pair = curr->next->next;
        ListNode *second = curr->next;

        // swap the curent pair
        second->next = curr;
        curr->next = next_pair;
        prev->next = second;

        // clean up
        prev = curr;
        curr = next_pair;
        
    }
    return dummy->next;
}

int main()
{
    std::vector<int> nums = {1, 2, 3, 4, 5};
    ListNode *head = buildList(nums);
    auto ans = swapPairs(head);
    return 0;
}