#include <queue>
#include <unordered_map>
#include <string>
#include <stack>

class TrieNode
{
public:
    TrieNode(char c) : val(c), is_end(false) {}
    TrieNode() : is_end(false) {}
    char val;
    bool is_end;
    std::unordered_map<char, TrieNode *> children;
};

class WordDictionary
{
public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    void addWord(std::string word)
    {
        TrieNode *curr_root = root;
        for (int i = 0; i < word.size(); i++)
        {
            char w = word[i];
            if (!curr_root->children.count(w))
                curr_root->children[w] = new TrieNode(w);
            curr_root = curr_root->children[w];
            if (i == word.size() - 1)
                curr_root->is_end = true;
        }
    }

    bool dfs(TrieNode *curr_root, int index, std::string word)
    {
        if (index == word.size())
            return curr_root->is_end;
        char c = word[index];
        if (c == '.')
        {
            for (auto x : curr_root->children)
            {
                if (dfs(x.second, index + 1, word))
                    return true;
                // return dfs(x.second, index + 1, word);
            }
        }
        else
        {
            if (!curr_root->children.count(c))
                return false;
            return dfs(curr_root->children[c], index + 1, word);
        }
        return false;
    }

    bool search(std::string word)
    {
        return dfs(root, 0, word);
    }

private:
    TrieNode *root;
};

int main()
{

    WordDictionary *wordDictionary = new WordDictionary();
    wordDictionary->addWord("bad");
    wordDictionary->addWord("dad");
    wordDictionary->addWord("mad");
    bool ans;
    // ans = wordDictionary->search("pad");  // return False
    // ans = wordDictionary->search("bad");  // return True
    ans = wordDictionary->search(".ad");  // return True
    ans = wordDictionary->search("b..."); // return False
    ans = wordDictionary->search("...");  // return False

    // WordDictionary *wordDictionary = new WordDictionary();
    // wordDictionary->addWord("at");
    // wordDictionary->addWord("and");
    // wordDictionary->addWord("an");
    // wordDictionary->addWord("add");
    // bool ans;
    // ans = wordDictionary->search("a"); // return False
    // ans = wordDictionary->search(".at"); // return True
    // wordDictionary->addWord("bat");
    // ans = wordDictionary->search(".at"); // return True
    // ans = wordDictionary->search("an."); // return True
    // ans = wordDictionary->search("a.d."); // return False
    // ans = wordDictionary->search("b."); // return False
    // ans = wordDictionary->search("a.d"); // return False
    // ans = wordDictionary->search("."); // return False
    return 0;
}