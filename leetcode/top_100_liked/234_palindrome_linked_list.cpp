#include <vector>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *buildTree(std::vector<int> &nums)
{
    ListNode *dummy = new ListNode();
    ListNode *curr = new ListNode(nums[0]);
    dummy->next = curr;
    for (int i = 1; i < nums.size(); i++)
    {
        auto temp = new ListNode(nums[i]);
        curr->next = temp;
        curr = curr->next;
    }
    return dummy->next;
}
ListNode *reverseTree(ListNode *head)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *curr = head;
    ListNode *prev = nullptr;
    while (curr)
    {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
bool isPalindrome(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;

    while (slow->next && fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    bool is_odd = true;
    if (fast->next)
    {
        // even sized, shift show by 1, odd size no need shift
        is_odd = false;
        ListNode* temp = slow;
        slow = slow->next;
        temp->next = nullptr;
    }
    
    // reverse the remaining linked list
    ListNode* prev = nullptr;
    while (slow)
    {
        ListNode *temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }
    ListNode* head2 = prev;

    // compare vals
    while(head && head2)
    {
        if (head->val != head2->val)
            return false;
        head = head->next;
        head2 = head2->next;
    }
    
    if (head == nullptr && head2 == nullptr)
        return true;

    return false;
}

int main()
{
    // std::vector<int> nums = {1, 2, 4, 5, 5, 4, 2, 1};
    std::vector<int> nums = {1};
    ListNode *root = buildTree(nums);
    // auto ans = reverseTree(root);
    auto ans = isPalindrome(root);
    return 0;
}