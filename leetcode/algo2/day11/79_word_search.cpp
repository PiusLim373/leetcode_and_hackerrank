#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#include <map>
#include <algorithm>

std::vector<std::pair<int, int>> curr;
std::vector<int> dir_x = {-1, 0, 1, 0};
std::vector<int> dir_y = {0, 1, 0, -1};

bool search(std::vector<std::vector<char>> board, std::string word, int m, int n, std::pair<int, int> coor, int pointer)
{
    if (pointer == word.size())
        return true;
    if (coor.first < 0 || coor.second < 0 || coor.first > m - 1 || coor.second > n - 1 || std::find(curr.begin(), curr.end(), coor) != curr.end() || board[coor.first][coor.second] != word[pointer])
        return false;
    curr.push_back({coor.first, coor.second});
    for (int i = 0; i < dir_x.size(); i++)
    {
        int search_x = coor.first + dir_x[i];
        int search_y = coor.second + dir_y[i];
        search(board, word, m, n, {search_x, search_y}, pointer + 1);
    }
    curr.pop_back();
    return false;
}

bool exist(std::vector<std::vector<char>> &board, std::string word)
{

    int m = board.size();
    int n = board[0].size();

    int pointer = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (search(board, word, m, n, {i, j}, pointer))
                return true;
        }
    }
    return false;
}

// something wrong about pointer movement, either should increase during queue popping or during inside visit_x and visit_y searching
bool exist_bugged(std::vector<std::vector<char>> &board, std::string word)
{
    int m = board.size();
    int n = board[0].size();

    std::vector<std::pair<int, int>> search_coor;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == word[0])
                search_coor.push_back({i, j});
        }
    }
    if (!search_coor.size())
        return false;

    std::vector<int> dir_x = {-1, 0, 1, 0};
    std::vector<int> dir_y = {0, 1, 0, -1};

    for (auto x : search_coor)
    {
        std::string debug_str = "";
        std::queue<std::pair<int, int>> q;
        std::map<std::pair<int, int>, bool> v;
        int word_pointer = 1;
        q.push(x);
        v[x] = true;
        debug_str.push_back(board[x.first][x.second]);
        while (!q.empty())
        {
            std::pair<int, int> curr = q.front();
            int curr_pointer = word_pointer;
            q.pop();
            for (int i = 0; i < dir_x.size(); i++)
            {
                int visit_x = curr.first + dir_x[i];
                int visit_y = curr.second + dir_y[i];
                if (visit_x >= 0 && visit_y >= 0 && visit_x <= m - 1 && visit_y <= n - 1 && v[{visit_x, visit_y}] != true)
                {
                    q.push({visit_x, visit_y});
                    word_pointer++;
                    v[{visit_x, visit_y}] = true;
                    debug_str.push_back(board[visit_x][visit_y]);
                    std::cout << debug_str << std::endl;
                }
            }
        }
        if (word_pointer == word.size())
            return true;
    }
    return false;
}
int main()
{
    std::vector<std::vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    // std::vector<std::vector<char>> board = {{'a', 'b'}, {'d', 'c'}};
    // std::vector<std::vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'E', 'S'}, {'A', 'D', 'E', 'E'}};
    std::string word = "ABCCED";
    std::cout << exist(board, word) << std::endl;

    // std::vector<std::pair<int, int>> v;
    // v.push_back({1, 2});
    // v.push_back({2, 3});
    // v.push_back({3, 4});
    // std::pair<int, int> search = std::make_pair(3, 4);
    // if (std::find(v.begin(), v.end(), search) != v.end())
    //     std::cout << "can find";
}