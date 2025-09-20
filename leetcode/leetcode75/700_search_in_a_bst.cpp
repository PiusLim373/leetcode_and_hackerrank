#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *buildTree(std::vector<int> data)
{
    TreeNode *head = new TreeNode(data[0]);
    std::queue<TreeNode *> q;
    q.push(head);
    int i = 1;
    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();
        if (i < data.size() && data[i] != -1)
        {
            curr->left = new TreeNode(data[i]);
            q.push(curr->left);
        }
        i++;
        if (i < data.size() && data[i] != -1)
        {
            curr->right = new TreeNode(data[i]);
            q.push(curr->right);
        }
        i++;
    }
    return head;
}

TreeNode *searchBST(TreeNode *root, int val)
{
    if (!root)
        return nullptr;

    if (val == root->val)
        return root;
    TreeNode* left_res = nullptr;
    if (root->left)
        left_res = searchBST(root->left, val);
    if (left_res)
        return left_res;
    if (root->right)
        return searchBST(root->right, val);
    return nullptr;
}

int main()
{
    // std::vector<int> r1 = {4, 2, 7, 1, 3};
    std::vector<int> r1 = { 18,2,22,-1,-1,-1,63,-1,84,-1,-1};
   
    int val = 63;

    TreeNode *root1 = buildTree(r1);
    auto res = searchBST(root1, val);
    return 0;
}