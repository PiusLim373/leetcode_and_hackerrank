#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
int count_node(ListNode *head)
{
    static int counter = 1;
    if (head->next == nullptr)
        return counter;
    else
    {
        counter++;
        return count_node(head->next);
    }
}

ListNode *transverse_node(ListNode *head, int step)
{
    if (step)
        return transverse_node(head->next, step - 1);
    else
        return head;
}

ListNode *middleNode(ListNode *head)
{
    // 1st pass, find total node
    int number_of_nodes = count_node(head);

    // 2nd pass, find middle node
    int step = 0;
    if (number_of_nodes % 2)
        step = (number_of_nodes + 1) / 2;
    else
        step = number_of_nodes / 2 + 1;
    return transverse_node(head, step - 1);

    // better solution
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}