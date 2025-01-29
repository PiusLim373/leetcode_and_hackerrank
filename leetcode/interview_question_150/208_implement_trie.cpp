#include <iostream>
#include <map>
struct TrieNode
{
  std::map<char, TrieNode*> children;
  bool is_end = false;
};

class Trie
{
public:
  TrieNode* root;
  Trie()
  {
    root = new TrieNode;
  }

  void insert(std::string word)
  {
    TrieNode* curr = root;
    for (auto x : word)
    {
      if (!curr->children.count(x))  // cant find
        curr->children[x] = new TrieNode;
      curr = curr->children[x];
    }
    curr->is_end = true;
  }

  bool search(std::string word)
  {
    TrieNode* curr = root;
    for (auto x : word)
    {
      if (curr->children.count(x))
        curr = curr->children[x];
      else
        return false;
    }
    return curr->is_end;
  }

  bool startsWith(std::string prefix)
  {
    TrieNode* curr = root;
    for (auto x : prefix)
    {
      if (curr->children.count(x))
        curr = curr->children[x];
      else
        return false;
    }
    return true;
  }
};

int main()
{
  Trie t;
  t.insert("apple");
  auto a = t.search("apple");
  auto ab = t.search("app");
  auto abc = t.startsWith("app");
  return 0;
}