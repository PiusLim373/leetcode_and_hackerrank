#include <vector>
#include <queue>
#include <stack>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void dfs(TreeNode *root, std::vector<int> &v)
{
    std::stack<TreeNode *> s;
    s.push(root);
    while (!s.empty())
    {
        auto curr = s.top();
        s.pop();
        if (!curr->left && !curr->right)
            v.push_back(curr->val);
        if (curr->left)
            s.push(curr->left);
        if (curr->right)
            s.push(curr->right);
    }
}
bool leafSimilar(TreeNode *root1, TreeNode *root2)
{
    std::vector<int> v1, v2;
    dfs(root1, v1);
    dfs(root2, v2);
    if (v1.size() != v2.size())
        return false;
    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i] != v2[i])
            return false;
    }
    return true;
}

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

int main()
{
    std::vector<int> r1 = {3, 5, 1, 6, 2, 9, 8, -1, -1, 7, 4};
    std::vector<int> r2 = {3, 5, 1, 6, 7, 4, 2, -1, -1, -1, -1, -1, -1, 9, 8};
    TreeNode *root1 = buildTree(r1);
    TreeNode *root2 = buildTree(r2);
    auto res = leafSimilar(root1, root2);
    return 0;
}