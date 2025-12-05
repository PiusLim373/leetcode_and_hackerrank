#include <vector>
#include <unordered_map>
// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *buildTree(std::vector<std::vector<int>> &nums)
{
    if (!nums.size())
        return nullptr;
    std::unordered_map<int, Node *> address;
    Node *root = new Node(nums[0][0]);
    address[0] = root;
    Node *curr = root;

    for (int i = 1; i < nums.size(); i++)
    {
        curr->next = new Node(nums[i][0]);
        curr = curr->next;
        address[i] = curr;
    }

    curr = root;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i][1] == -1)
        {
        }
        else
            curr->random = address[nums[i][1]];
        curr = curr->next;
    }
    return root;
}

Node *copyRandomList(Node *head)
{
    if (!head)
        return nullptr;
    int index = 1;
    std::unordered_map<Node *, int> index_map;
    std::unordered_map<int, Node *> address_map;
    index_map[head] = 0;
    Node *curr1 = head->next;
    Node *ans = new Node(head->val);
    address_map[0] = ans;
    Node *curr2 = ans;

    while (curr1)
    {
        curr2->next = new Node(curr1->val);
        address_map[index] = curr2->next;
        index_map[curr1] = index;
        curr2 = curr2->next;
        curr1 = curr1->next;
        index++;
    }

    curr1 = head;
    curr2 = ans;

    while (curr1)
    {
        if (!curr1->random)
            curr2->random = nullptr;
        else
        {
            int random_index = index_map[curr1->random];
            curr2->random = address_map[random_index];
        }

        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return ans;
}

int main()
{
    // std::vector<std::vector<int>> nums = {{7, -1}, {13, 0}, {11, 4}, {10, 2}, {1, 0}};
    std::vector<std::vector<int>> nums = {{2, 1}};
    Node *head = buildTree(nums);
    auto ans = copyRandomList(head);
    return 0;
}
