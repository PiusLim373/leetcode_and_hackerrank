#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
struct Node
{
  int val;
  Node* left;
  Node* right;
  Node* next;
  Node() : val(0), left(nullptr), right(nullptr), next(nullptr)
  {
  }
  Node(int x) : val(x), left(nullptr), right(nullptr), next(nullptr)
  {
  }
  Node(int x, Node* left, Node* right, Node* next) : val(x), left(left), right(right), next(next)
  {
  }
};

Node* buildTree(std::vector<int> nums)
{
  Node* root = new Node(nums[0]);
  std::queue<Node*> q;
  q.push(root);
  int i = 1;
  while (i < nums.size())
  {
    Node* curr = q.front();
    q.pop();
    if (i < nums.size() && nums[i] != -1)
    {
      curr->left = new Node(nums[i]);
      q.push(curr->left);
    }
    i++;

    if (i < nums.size() && nums[i] != -1)
    {
      curr->right = new Node(nums[i]);
      q.push(curr->right);
    }
    i++;
  }
  return root;
}

Node* connect(Node* root)
{
  if (!root)
    return nullptr;
  std::map<Node*, int> level_map;
  std::map<int, Node*> node_map;
  std::queue<Node*> queue;
  queue.push(root);
  level_map[root] = 1;

  while (!queue.empty())
  {
    Node* curr = queue.front();
    queue.pop();

    if (curr->right)
    {
      queue.push(curr->right);
      level_map[curr->right] = level_map[curr] + 1;
      curr->right->next = node_map[level_map[curr->right]];
      node_map[level_map[curr->right]] = curr->right;
    }

    if (curr->left)
    {
      queue.push(curr->left);
      level_map[curr->left] = level_map[curr] + 1;
      curr->left->next = node_map[level_map[curr->left]];
      node_map[level_map[curr->left]] = curr->left;
    }
  }

  return root;
}

int main()
{
  std::vector<int> tree = { 1, 2, 3, 4, 5, -1, 7 };

  Node* root = buildTree(tree);
  Node* ans = connect(root);
  return 0;
}