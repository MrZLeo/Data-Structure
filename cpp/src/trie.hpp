#ifndef __TRIE_HPP__
#define __TRIE_HPP__

#include <string>
#include <unordered_map>

class Trie {
private:
    struct Node {
        bool end;
        std::unordered_map<char, Node *> next;
        Node()
            : end(false)
        {
        }
    };

    Node *root;

public:
    Trie()
        : root(new Node())
    {
    }

    void insert(std::string word)
    {
        Node *cur = root;
        for (char ch : word) {
            // don't have node -> char
            if (cur->next.find(ch) == cur->next.end()) {
                cur->next[ch] = new Node();
            }
            cur = cur->next[ch];
        }
        cur->end = true;
    }

    bool search(std::string word)
    {
        Node *cur = root;
        for (char ch : word) {
            if (cur->next.find(ch) == cur->next.end())
                return false;
            cur = cur->next[ch];
        }
        return cur->end;
    }

    bool startsWith(std::string prefix)
    {
        Node *cur = root;
        for (char ch : prefix) {
            if (cur->next.find(ch) == cur->next.end())
                return false;
            cur = cur->next[ch];
        }
        return true;
    }
};

#endif // __TRIE_HPP__
