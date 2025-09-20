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

void dfs(TreeNode *root, int max_val, int &ans)
{
    if (root->val >= max_val)
    {
        ans++;
        max_val = root->val;
    }
    if(root->left)
        dfs(root->left, max_val, ans);
    if(root->right)
        dfs(root->right, max_val, ans);
}

int goodNodes(TreeNode *root)
{
    int count = 1;
    int left = 0;
    int right = 0;
    if (root->left)
        dfs(root->left, root->val, left);
    if (root->right)
        dfs(root->right, root->val, right);
    return 1 + left + right;
}

int goodNodesNotWorking(TreeNode *root)
{
    int count = 1;
    std::vector<int> v;
    std::stack<TreeNode *> s;
    s.push(root);
    while (!s.empty())
    {
        auto curr = s.top();
        s.pop();
        v.push_back(curr->val);
        if (v.size() != 1 && v[v.size() - 1] >= v[v.size() - 2] && v[v.size() - 1] >= v[0])
            count++;
        if (!curr->left && !curr->right)
            v.pop_back();
        if (curr->left)
            s.push(curr->left);
        if (curr->right)
            s.push(curr->right);
    }
    return count;
}

int main()
{
    std::vector<int> r1 = {3, 1, 4, 3, -1, 1, 5};
    // std::vector<int> r1 = {9, -1, 3, 6};
    // std::vector<int> r1 = {2, 4, 4, 4, -1, 1, 3, -1, -1, 5, -1, -1, -1, -1, 5, 4, 4};

    TreeNode *root1 = buildTree(r1);
    auto res = goodNodes(root1);
    return 0;
}