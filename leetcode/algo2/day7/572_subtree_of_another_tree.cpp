#include <queue>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool compare_trees(TreeNode *ori, TreeNode *compare)
{

    std::queue<TreeNode *> q1;
    std::queue<TreeNode *> q2;
    q1.push(ori);
    q2.push(compare);
    while (!q1.empty() && !q2.empty())
    {
        int c1 = q1.size();
        int c2 = q2.size();
        if (c1 != c2)
            return false;
        TreeNode *curr1 = q1.front();
        TreeNode *curr2 = q2.front();
        q1.pop();
        q2.pop();
        if (curr1->val != curr2->val)
            return false;
        if (curr1->left && curr2->left)
        {
            q1.push(curr1->left);
            q2.push(curr2->left);
        }
        else if (!curr1->left && !curr2->left)
            ;
        else
            return false;
        if (curr1->right && curr2->right)
        {
            q1.push(curr1->right);
            q2.push(curr2->right);
        }
        else if (!curr1->right && !curr2->right)
            ;
        else
            return false;
    }

    return (q1.size() == q2.size());
}
bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    std::queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();
        if (curr->val == subRoot->val)
        {
            if (compare_trees(curr, subRoot))
                return true;
        }
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
    return false;
}

// better solution
bool helper(TreeNode *root1, TreeNode *root2)
{
    if (!root1 && !root2)
        return true;

    if (!root1 || !root2)
        return false;

    return root1->val == root2->val &&
           helper(root1->left, root2->left) &&
           helper(root1->right, root2->right);
}
bool isSubtree(TreeNode *root1, TreeNode *root2)
{

    if (!root1)
        return false;

    if (!root2)
        return true;

    return helper(root1, root2) || isSubtree(root1->left, root2) || isSubtree(root1->right, root2);
}