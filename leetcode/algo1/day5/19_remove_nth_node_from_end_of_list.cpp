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
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    // int total_nodes = count_nodes(head);
    // if(total_nodes == 1)head = nullptr;
    // else if(total_nodes == n) head = head->next;
    // else{
    //     remove_node(head, total_nodes, n);
    // }
    // return head;

    // better solution
    ListNode *slow = head;
    ListNode *fast = head;
    for (int i = 0; i < n; i++)
        fast = fast->next;
    if (fast == nullptr)
        return head->next;
    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
}