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

int dfs(TreeNode *root, long long curr_sum, int target_sum, std::map<long long, int> &m)
{
    if (!root)
        return 0;

    curr_sum += root->val;

    int path = m[curr_sum - target_sum];
    m[curr_sum]++;

    path += dfs(root->left, curr_sum, target_sum, m);
    path += dfs(root->right, curr_sum, target_sum, m);

    m[curr_sum]--;
    return path;
}

int pathSum(TreeNode *root, int targetSum)
{
    std::map<long long, int> m;
    m[0]++;
    return dfs(root, 0, targetSum, m);
}

void dfs(TreeNode *root, std::deque<int> &v, int target, int &counter)
{
    if (root->val < target)
    {
        target -= root->val;
        v.push_back(root->val);
    }
    else if (root->val == target)
    {
        counter++;
        target -= root->val;
        v.push_back(root->val);
    }
    else
    {
        target += v.front();
        v.pop_front();
    }

    if (root->left)
        dfs(root->left, v, target, counter);
    if (root->right)
        dfs(root->right, v, target, counter);
}
int pathSumNotworking(TreeNode *root, int targetSum)
{
    int counter = 0;
    std::deque<int> v;
    int remainder = targetSum;
    if (root->val < targetSum)
    {
        v.push_back(root->val);
        remainder = targetSum - root->val;
    }
    if (root->left)
        dfs(root->left, v, remainder, counter);
    if (root->right)
        dfs(root->right, v, remainder, counter);

    return counter;
}

int main()
{
    std::vector<int> r1 = {10, 5, -3, 3, 2, -1, 11, 3, -2, -1, 1};
    int target = 8;

    TreeNode *root1 = buildTree(r1);
    auto res = pathSum(root1, target);
    return 0;
}