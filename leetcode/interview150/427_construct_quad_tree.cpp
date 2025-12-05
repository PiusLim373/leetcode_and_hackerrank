#include <vector>

// Definition for a QuadTree node.
class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

Node *construct(std::vector<std::vector<int>> &grid)
{
    int size = grid.size();
    if (size == 0)
        return nullptr;
    if (size == 1)
        return new Node(grid[0][0], true);
    // convert the grid to nodes*
    std::vector<std::vector<Node *>> prev_grid_nodes, new_grid_nodes;
    prev_grid_nodes.resize(size);
    for (int row = 0; row < size; row++)
    {
        prev_grid_nodes[row].resize(size);
        for (int col = 0; col < size; col++)
        {
            prev_grid_nodes[row][col] = new Node(grid[row][col], true);
        }
    }

    int prev_grid_nodes_size = prev_grid_nodes.size();  // 8
    int new_grid_nodes_size = prev_grid_nodes_size / 2; // 4
    while (new_grid_nodes_size > 1)
    {
        new_grid_nodes.clear();
        new_grid_nodes.resize(new_grid_nodes_size);
        for (int row = 0; row < prev_grid_nodes_size; row += 2)
        {
            new_grid_nodes[row / 2].resize(prev_grid_nodes_size / 2);
            for (int col = 0; col < prev_grid_nodes_size; col += 2)
            {
                Node *temp = new Node();
                temp->topLeft = prev_grid_nodes[row][col];
                temp->topRight = prev_grid_nodes[row][col + 1];
                temp->bottomLeft = prev_grid_nodes[row + 1][col];
                temp->bottomRight = prev_grid_nodes[row + 1][col + 1];

                bool top_left_val = temp->topLeft->val;
                bool top_right_val = temp->topRight->val;
                bool bottom_left_val = temp->bottomLeft->val;
                bool bottom_right_val = temp->bottomRight->val;

                bool top_left_leaf = temp->topLeft->isLeaf;
                bool top_right_leaf = temp->topRight->isLeaf;
                bool bottom_left_leaf = temp->bottomLeft->isLeaf;
                bool bottom_right_leaf = temp->bottomRight->isLeaf;

                bool all_same = (top_left_val == top_right_val) && (top_right_val == bottom_left_val) && (bottom_left_val == bottom_right_val);
                bool all_leaf_true = (top_left_leaf == top_right_leaf) && (top_right_leaf == bottom_left_leaf) && (bottom_left_leaf == bottom_right_leaf) && (top_left_leaf);
                if (all_same && all_leaf_true)
                    temp = new Node(top_left_val, true);
                new_grid_nodes[row / 2][col / 2] = temp;
            }
        }
        prev_grid_nodes.clear();
        prev_grid_nodes = new_grid_nodes;
        prev_grid_nodes_size = prev_grid_nodes.size();
        new_grid_nodes_size = prev_grid_nodes_size / 2;
    }

    Node *root = new Node();
    root->topLeft = prev_grid_nodes[0][0];
    root->topRight = prev_grid_nodes[0][1];
    root->bottomLeft = prev_grid_nodes[1][0];
    root->bottomRight = prev_grid_nodes[1][1];

    bool top_left_val = root->topLeft->val;
    bool top_right_val = root->topRight->val;
    bool bottom_left_val = root->bottomLeft->val;
    bool bottom_right_val = root->bottomRight->val;

    bool top_left_leaf = root->topLeft->isLeaf;
    bool top_right_leaf = root->topRight->isLeaf;
    bool bottom_left_leaf = root->bottomLeft->isLeaf;
    bool bottom_right_leaf = root->bottomRight->isLeaf;


    bool all_same = (top_left_val == top_right_val) && (top_right_val == bottom_left_val) && (bottom_left_val == bottom_right_val);
    bool all_leaf = (top_left_leaf == top_right_leaf) && (top_right_leaf == bottom_left_leaf) && (bottom_left_leaf == bottom_right_leaf) && (top_left_leaf);
    if (all_same && all_leaf)
        root = new Node(top_left_val, true);
    return root;
}

int main()
{
    std::vector<std::vector<int>> grid = {
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 0},
    };

    // std::vector<std::vector<int>> grid = {{1, 1, 0, 0},
    //                                       {0, 0, 1, 1},
    //                                       {1, 1, 0, 0},
    //                                       {0, 0, 1, 1}};

    auto ans = construct(grid);
    return 0;
}