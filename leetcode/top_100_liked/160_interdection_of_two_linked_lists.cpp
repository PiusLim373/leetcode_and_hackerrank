#include <vector>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct BuildResult
{
    BuildResult(ListNode *data1, ListNode *data2) : a(data1), b(data2) {};
    ListNode *a;
    ListNode *b;
};
BuildResult buildData(std::vector<int> &a, std::vector<int> &b, int skip_a, int skip_b, int intersect_val)
{
    ListNode *root_a = new ListNode(a[0]);
    ListNode *curr_a = root_a;
    for (int i = 1; i < a.size(); i++)
    {
        curr_a->next = new ListNode(a[i]);
        curr_a = curr_a->next;
    }

    ListNode *root_b = new ListNode(b[0]);
    ListNode *curr_b = root_b;
    for (int i = 1; i < b.size(); i++)
    {
        curr_b->next = new ListNode(b[i]);
        curr_b = curr_b->next;
    }

    if (intersect_val != 0)
    {
        curr_a = root_a;
        while (skip_a != 0)
        {
            curr_a = curr_a->next;
            skip_a--;
        }

        if (skip_b == 0)
        {
            root_b = curr_a;
        }
        else
        {
            curr_b = root_b;
            skip_b -= 1;
            while (skip_b != 0)
            {
                curr_b = curr_b->next;
                skip_b--;
            }
            curr_b->next = curr_a;
        }
    }
    return BuildResult(root_a, root_b);
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *a_ptr = headA;
    ListNode *b_ptr = headB;
    bool a_ptr_at_a = true;
    bool b_ptr_at_b = true;

    while (a_ptr != b_ptr)
    {
        a_ptr = (!a_ptr) ? headB : a_ptr->next;
        b_ptr = (!b_ptr) ? headA : b_ptr->next;
    }
    return a_ptr;
}

int main()
{
    std::vector<int> nums_a = {4, 1, 8, 4, 5};
    std::vector<int> nums_b = {5, 6, 1, 8, 4, 5};
    int skip_a = 2;
    int skip_b = 3;

    // std::vector<int> nums_a = {1, 9, 1, 2, 4};
    // std::vector<int> nums_b = {2, 4};
    // int skip_a = 3;
    // int skip_b = 0;
    
    int intersec_val = 8;
    auto [list_a, list_b] = buildData(nums_a, nums_b, skip_a, skip_b, intersec_val);
    auto ans = getIntersectionNode(list_a, list_b);
    return 0;
}