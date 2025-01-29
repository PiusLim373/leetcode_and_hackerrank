#include <vector>
#include <queue>
#include <map>
class Node
{
public:
  int val;
  std::vector<Node*> neighbors;
  Node()
  {
    val = 0;
    neighbors = std::vector<Node*>();
  }
  Node(int _val)
  {
    val = _val;
    neighbors = std::vector<Node*>();
  }
  Node(int _val, std::vector<Node*> _neighbors)
  {
    val = _val;
    neighbors = _neighbors;
  }
};

Node* createGraph(std::vector<std::vector<int>> adjList)
{
  std::map<int, Node*> node_recorder;
  for (int i = 1; i < adjList.size() + 1; i++)
  {
    Node* temp = new Node(i);
    node_recorder[i] = temp;
  }
  for (int i = 0; i < adjList.size(); i++)
  {
    for (auto x : adjList[i])
    {
      node_recorder[i + 1]->neighbors.push_back(node_recorder[x]);
    }
  }
  return node_recorder[1];
}

Node* cloneGraph(Node* node)
{
  if (!node)
    return nullptr;
  Node* new_graph = new Node(node->val);
  std::queue<std::pair<Node*, Node*>> queue;
  queue.push({ node, new_graph });

  std::map<int, Node*> node_recorder;
  node_recorder[node->val] = new_graph;

  while (!queue.empty())
  {
    auto [curr, new_curr] = queue.front();
    queue.pop();

    for (auto neigh : curr->neighbors)
    {
      if (node_recorder[neigh->val] == nullptr)
      {
        Node* temp = new Node(neigh->val);
        new_curr->neighbors.push_back(temp);
        queue.push({ neigh, temp });
        node_recorder[neigh->val] = temp;
      }
      else
      {
        new_curr->neighbors.push_back(node_recorder[neigh->val]);
      }
    }
  }
  return new_graph;
}

int main()
{
  std::vector<std::vector<int>> adjList = { { 2, 4 }, { 1, 3 }, { 2, 4 }, { 1, 3 } };

  Node* graph = createGraph(adjList);
  Node* cloned = cloneGraph(graph);
  return 0;
}