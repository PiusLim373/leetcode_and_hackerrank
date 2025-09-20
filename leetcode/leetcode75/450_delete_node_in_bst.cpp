#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <algorithm>
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

void inorder(TreeNode *root, std::vector<int> &data)
{
    if (!root)
        return;
    inorder(root->left, data);
    data.push_back(root->val);
    inorder(root->right, data);
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (!root)
        return root;
    if (key < root->val)
        root->left = deleteNode(root->left, key);
    if (key > root->val)
        root->right = deleteNode(root->right, key);
    if (key == root->val)
    {
        if (!root->left)
            return root->right;
        if (!root->right)
            return root->left;

        TreeNode *curr = root->right;
        while (curr->left)
            curr = curr->left;
        root->val = curr->val;
        root->right = deleteNode(root->right, root->val);
    }
    return root;
}
TreeNode *deleteNodeNotworking(TreeNode *root, int key)
{
    // inorder transfersal
    std::vector<int> data;
    inorder(root, data);

    auto it = std::find(data.begin(), data.end(), key);
    if (it == data.end())
        return root;
    data.erase(it);
    return nullptr;
}

int main()
{
    std::vector<int> r1 = {5, 3, 6, 2, 4, -1, 7};
    int key = 3;

    TreeNode *root1 = buildTree(r1);
    auto res = deleteNode(root1, key);
    return 0;
}