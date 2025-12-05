#include <vector>
#include <stack>
#include <string>

class TrieNode
{
public:
    TrieNode(char v) : val(v) {}
    TrieNode() {};
    char val{};
    bool is_end = false;
    // initialize children to size 26 (filled with nullptr) as an in-class initializer
    std::vector<TrieNode *> children = std::vector<TrieNode *>(26, nullptr);
};

void dfs(std::vector<std::vector<char>> &board, int curr_row, int curr_col, TrieNode *curr_node, std::string curr_str, std::vector<std::string> &ans, int max_row, int max_col, int words_size)
{
    if (ans.size() >= words_size)
        return;
    char ch = board[curr_row][curr_col];
    curr_str += ch;
    board[curr_row][curr_col] = '#';
    if (curr_node->is_end)
    {
        ans.push_back(curr_str);
        curr_node->is_end = false;
    }

    std::vector<std::pair<int, int>> valid_neigh;
    if (curr_col - 1 >= 0 && board[curr_row][curr_col - 1] != '#' && curr_node->children[board[curr_row][curr_col - 1] - 'a'])
        valid_neigh.push_back({curr_row, curr_col - 1});
    if (curr_col + 1 < max_col && board[curr_row][curr_col + 1] != '#' && curr_node->children[board[curr_row][curr_col + 1] - 'a'])
        valid_neigh.push_back({curr_row, curr_col + 1});
    if (curr_row - 1 >= 0 && board[curr_row - 1][curr_col] != '#' && curr_node->children[board[curr_row - 1][curr_col] - 'a'])
        valid_neigh.push_back({curr_row - 1, curr_col});
    if (curr_row + 1 < max_row && board[curr_row + 1][curr_col] != '#' && curr_node->children[board[curr_row + 1][curr_col] - 'a'])
        valid_neigh.push_back({curr_row + 1, curr_col});

    for (auto x : valid_neigh)
        dfs(board, x.first, x.second, curr_node->children[board[x.first][x.second] - 'a'], curr_str, ans, max_row, max_col, words_size);
    
    board[curr_row][curr_col] = ch;
}

std::vector<std::string>
findWords(std::vector<std::vector<char>> &board, std::vector<std::string> &words)
{
    TrieNode *root = new TrieNode();
    for (auto w : words)
    {
        TrieNode *curr = root;
        for (int i = 0; i < w.size(); i++)
        {
            char ch = w[i];
            if (!curr->children[ch - 'a'])
                curr->children[ch - 'a'] = new TrieNode(ch);
            curr = curr->children[ch - 'a'];

            if (i == w.size() - 1)
                curr->is_end = true;
        }
    }

    int max_row = board.size();
    int max_col = board[0].size();
    std::vector<std::string> ans;
    for (int row = 0; row < max_row; row++)
    {
        for (int col = 0; col < max_col; col++)
        {
            char curr = board[row][col];
            if (root->children[curr - 'a'])
            {
                dfs(board, row, col, root->children[curr - 'a'], "", ans, max_row, max_col, words.size());
            }
        }
    }
    return ans;
}

int main()
{
    std::vector<std::vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'},
    };
    std::vector<std::string> words = {"oath", "pea", "eat", "rain", "oathkrvlfiie"};

    // std::vector<std::vector<char>> board = {
    //     {'a'},
    // };
    // std::vector<std::string> words = {"a"};
    /*
    std::vector<std::vector<char>> board = {
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
    };
    std::vector<std::string> words = {
        "lllllll",
        "fffffff",
        "ssss",
        "s",
        "rr",
        "xxxx",
        "ttt",
        "eee",
        "ppppppp",
        "iiiiiiiii",
        "xxxxxxxxxx",
        "pppppp",
        "xxxxxx",
        "yy",
        "jj",
        "ccc",
        "zzz",
        "ffffffff",
        "r",
        "mmmmmmmmm",
        "tttttttt",
        "mm",
        "ttttt",
        "qqqqqqqqqq",
        "z",
        "aaaaaaaa",
        "nnnnnnnnn",
        "v",
        "g",
        "ddddddd",
        "eeeeeeeee",
        "aaaaaaa",
        "ee",
        "n",
        "kkkkkkkkk",
        "ff",
        "qq",
        "vvvvv",
        "kkkk",
        "e",
        "nnn",
        "ooo",
        "kkkkk",
        "o",
        "ooooooo",
        "jjj",
        "lll",
        "ssssssss",
        "mmmm",
        "qqqqq",
        "gggggg",
        "rrrrrrrrrr",
        "iiii",
        "bbbbbbbbb",
        "aaaaaa",
        "hhhh",
        "qqq",
        "zzzzzzzzz",
        "xxxxxxxxx",
        "ww",
        "iiiiiii",
        "pp",
        "vvvvvvvvvv",
        "eeeee",
        "nnnnnnn",
        "nnnnnn",
        "nn",
        "nnnnnnnn",
        "wwwwwwww",
        "vvvvvvvv",
        "fffffffff",
        "aaa",
        "p",
        "ddd",
        "ppppppppp",
        "fffff",
        "aaaaaaaaa",
        "oooooooo",
        "jjjj",
        "xxx",
        "zz",
        "hhhhh",
        "uuuuu",
        "f",
        "ddddddddd",
        "zzzzzz",
        "cccccc",
        "kkkkkk",
        "bbbbbbbb",
        "hhhhhhhhhh",
        "uuuuuuu",
        "cccccccccc",
        "jjjjj",
        "gg",
        "ppp",
        "ccccccccc",
        "rrrrrr",
        "c",
        "cccccccc",
        "yyyyy",
        "uuuu",
        "jjjjjjjj",
        "bb",
        "hhh",
        "l",
        "u",
        "yyyyyy",
        "vvv",
        "mmm",
        "ffffff",
        "eeeeeee",
        "qqqqqqq",
        "zzzzzzzzzz",
        "ggg",
        "zzzzzzz",
        "dddddddddd",
        "jjjjjjj",
        "bbbbb",
        "ttttttt",
        "dddddddd",
        "wwwwwww",
        "vvvvvv",
        "iii",
        "ttttttttt",
        "ggggggg",
        "xx",
        "oooooo",
        "cc",
        "rrrr",
        "qqqq",
        "sssssss",
        "oooo",
        "lllllllll",
        "ii",
        "tttttttttt",
        "uuuuuu",
        "kkkkkkkk",
        "wwwwwwwwww",
        "pppppppppp",
        "uuuuuuuu",
        "yyyyyyy",
        "cccc",
        "ggggg",
        "ddddd",
        "llllllllll",
        "tttt",
        "pppppppp",
        "rrrrrrr",
        "nnnn",
        "x",
        "yyy",
        "iiiiiiiiii",
        "iiiiii",
        "llll",
        "nnnnnnnnnn",
        "aaaaaaaaaa",
        "eeeeeeeeee",
        "m",
        "uuu",
        "rrrrrrrr",
        "h",
        "b",
        "vvvvvvv",
        "ll",
        "vv",
        "mmmmmmm",
        "zzzzz",
        "uu",
        "ccccccc",
        "xxxxxxx",
        "ss",
        "eeeeeeee",
        "llllllll",
        "eeee",
        "y",
        "ppppp",
        "qqqqqq",
        "mmmmmm",
        "gggg",
        "yyyyyyyyy",
        "jjjjjj",
        "rrrrr",
        "a",
        "bbbb",
        "ssssss",
        "sss",
        "ooooo",
        "ffffffffff",
        "kkk",
        "xxxxxxxx",
        "wwwwwwwww",
        "w",
        "iiiiiiii",
        "ffff",
        "dddddd",
        "bbbbbb",
        "uuuuuuuuu",
        "kkkkkkk",
        "gggggggggg",
        "qqqqqqqq",
        "vvvvvvvvv",
        "bbbbbbbbbb",
        "nnnnn",
        "tt",
        "wwww",
        "iiiii",
        "hhhhhhh",
        "zzzzzzzz",
        "ssssssssss",
        "j",
        "fff",
        "bbbbbbb",
        "aaaa",
        "mmmmmmmmmm",
        "jjjjjjjjjj",
        "sssss",
        "yyyyyyyy",
        "hh",
        "q",
        "rrrrrrrrr",
        "mmmmmmmm",
        "wwwww",
        "www",
        "rrr",
        "lllll",
        "uuuuuuuuuu",
        "oo",
        "jjjjjjjjj",
        "dddd",
        "pppp",
        "hhhhhhhhh",
        "kk",
        "gggggggg",
        "xxxxx",
        "vvvv",
        "d",
        "qqqqqqqqq",
        "dd",
        "ggggggggg",
        "t",
        "yyyy",
        "bbb",
        "yyyyyyyyyy",
        "tttttt",
        "ccccc",
        "aa",
        "eeeeee",
        "llllll",
        "kkkkkkkkkk",
        "sssssssss",
        "i",
        "hhhhhh",
        "oooooooooo",
        "wwwwww",
        "ooooooooo",
        "zzzz",
        "k",
        "hhhhhhhh",
        "aaaaa",
        "mmmmm",
    };

    */
    auto ans = findWords(board, words);
    return 0;
}