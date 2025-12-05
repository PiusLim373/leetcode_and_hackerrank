#include <vector>
#include <map>
#include <string>
#include <memory>
#include <stack>
#include <iostream>
#include <algorithm>

class TrieNode
{
public:
    TrieNode()
    {
        children.resize(26, nullptr);
    }
    std::vector<std::string> suggestions;
    std::vector<TrieNode *> children;
};

class Trie
{
public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(std::string product)
    {
        TrieNode *curr = root;
        for (auto c : product)
        {
            int index = c - 'a';
            if (!curr->children[index])
                curr->children[index] = new TrieNode();
            curr = curr->children[index];
            curr->suggestions.push_back(product);

            std::sort(curr->suggestions.begin(), curr->suggestions.end());
            if (curr->suggestions.size() > 3)
                curr->suggestions.pop_back();
        }
    }

    std::vector<std::vector<std::string>> getSuggestions(std::string searchWord)
    {
        TrieNode *curr = root;
        std::vector<std::vector<std::string>> ans;
        for (auto c : searchWord)
        {
            int index = c - 'a';
            if (curr && curr->children[index])
                curr = curr->children[index];
            else
                curr = nullptr;
            if(curr)
                ans.push_back(curr->suggestions);
            else
                ans.push_back({});
        }
        return ans;
    }

    TrieNode *root;
};

/*
class TrieNodeNotWorking
{
public:
    TrieNode() {}
    TrieNode(char character) : character(character) {}

    std::map<char, TrieNode *> children;
    bool is_end;
    char character;
};

class TrieNorworking
{
public:
    TrieNorworking()
    {
        root = new TrieNode();
    }
    std::vector<std::vector<std::string>> search(std::string search_word)
    {
        std::vector<std::vector<std::string>> ans;
        for (int i = 0; i < search_word.size(); i++)
        {
            int j = i;
            TrieNode *starting_root = root;
            while (j != 0)
            {
                starting_root = root->children[search_word[i]]
            }
            ans.push_back(searchChar(search_word[i], starting_root));
        }
        return ans;
    }

    std::vector<std::string> searchChar(char c, TrieNode *starting_root)
    {
        std::vector<std::string> ans;
        std::stack<std::pair<TrieNode *, std::string>> st;
        if (starting_root->children.count(c) == 0)
            return {};
        st.push({starting_root->children[c], std::string(1, c)});
        int count = 0;
        while (!st.empty() && count < 3)
        {
            auto [curr_node, curr_str] = st.top();
            st.pop();

            if (curr_node->is_end)
            {
                count++;
                ans.push_back(curr_str);
            }
            for (auto it = curr_node->children.rbegin(); it != curr_node->children.rend(); it++)
            {
                st.push({it->second, curr_str + it->first});
            }
        }
        return ans;
    }

    void insert(std::string product)
    {
        TrieNode *curr = root;
        for (auto c : product)
        {
            if (curr->children.count(c) == 0)
                curr->children[c] = new TrieNode(c);
            curr = curr->children[c];
        }
        curr->is_end = true;
    }

private:
    TrieNode *root;
};
*/
std::vector<std::vector<std::string>>
suggestedProducts(std::vector<std::string> &products, std::string searchWord)
{
    auto dictionary = std::make_shared<Trie>();
    for (auto x : products)
        dictionary->insert(x);
    return dictionary->getSuggestions(searchWord);
}

int main()
{
    // std::vector<std::string> products = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    std::vector<std::string> products = {"havana"};
    std::string search_word = "havana";

    auto ans = suggestedProducts(products, search_word);
    return 0;
}
