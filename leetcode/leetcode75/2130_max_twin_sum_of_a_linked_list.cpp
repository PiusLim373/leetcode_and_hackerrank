#include <iostream>
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

ListNode *reverseList(ListNode *head)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *next = head->next;
    ListNode *curr = head;

    while (next)
    {
        ListNode *temp = next->next;
        next->next = curr;
        curr = next;
        next = temp;
    }

    dummy->next->next = nullptr;
    return curr;
}

int pairSum(ListNode *head)
{
    // loop through the whole list and find the middle;
    int count = 1;
    ListNode *curr = head;
    while (curr->next)
    {
        count++;
        curr = curr->next;
    }

    // reverse the second last part
    ListNode *second_head = head;
    for (int i = 0; i < count / 2; i++)
    {
        second_head = second_head->next;
    }
    ListNode *second_part_pointer = reverseList(second_head);
    ListNode *first_part_pointer = head;
    int max_sum = -1;

    while (second_part_pointer)
    {
        int temp_sum = first_part_pointer->val + second_part_pointer->val;
        if (temp_sum > max_sum)
            max_sum = temp_sum;
        first_part_pointer = first_part_pointer->next;
        second_part_pointer = second_part_pointer->next;
    }

    return max_sum;
}

int main()
{
    // std::vector<int> data = {5, 4, 2, 1, 100, 12, 20, 30};
    std::vector<int> data = {1, 100000};
    ListNode *head = buildList(data);
    auto res = pairSum(head);
    // auto res = reverseList(head);
    return 0;
}