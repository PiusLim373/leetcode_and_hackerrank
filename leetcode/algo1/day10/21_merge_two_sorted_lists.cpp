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

void recursion()
{
    static ListNode *merge_list = new ListNode();
    static int i = 0;
    i++;
    if (i == 10)
    {
        cout << "finished" << endl;
        return;
    }
    else
        return recursion();
}
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *temp = new ListNode();
    if (list1 == nullptr)
        return list2;
    if (list2 == nullptr)
        return list1;

    if (list1->val >= list2->val)
    {
        temp = list2;
        temp->next = mergeTwoLists(temp->next, list1);
    }
    else
    {
        temp = list1;
        temp->next = mergeTwoLists(temp->next, list2);
    }
    return temp;

    // better solution to not use recursion and have a pointer always pointing to tail for updating
}
int main()
{
    string s1 = "ab";
    string s2 = "eidbaooo";
    recursion();
}