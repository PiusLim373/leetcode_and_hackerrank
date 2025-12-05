#include <vector>
#include <queue>
#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *buildList(std::vector<int> nums)
{
    if(!nums.size())
        return nullptr;
    ListNode *root = new ListNode(nums[0]);
    ListNode *curr = root;
    for (int i = 1; i < nums.size(); i++)
    {
        ListNode *temp = new ListNode(nums[i]);
        curr->next = temp;
        curr = curr->next;
    }
    return root;
}

struct Compare
{
    bool operator()(ListNode *lhs, ListNode *rhs)
    {
        return (lhs->val > rhs->val);
    }
};

ListNode *mergeKLists(std::vector<ListNode *> &lists)
{
    std::priority_queue<ListNode *, std::vector<ListNode *>, Compare> pq;
    for (auto x : lists)
    {
        if(x)
            pq.push(x);
    }

    ListNode* dummy = new ListNode(-1);
    ListNode* curr = dummy;
    while (!pq.empty())
    {
        auto top = pq.top();
        curr->next = top;
        curr = curr->next;
        pq.pop();
        if (top && top->next)
        {
            ListNode *temp = top->next;
            pq.push(temp);
        }
    }
    if (curr)
        curr->next = nullptr;
    return dummy->next;
}
int main()
{
    // std::vector<std::vector<int>> nums = {{10, 12}, {15, 20}, {1, 4, 5}, {1, 3, 4}, {2, 6}};

    std::vector<std::vector<int>> nums = {{}, {}, {}};
    std::vector<ListNode *> lists;
    for (auto x : nums)
    {
        lists.push_back(buildList(x));
    }
    auto ans = mergeKLists(lists);
    return 0;
}