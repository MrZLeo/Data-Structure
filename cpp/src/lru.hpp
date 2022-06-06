#ifndef __LRU_HPP__
#define __LRU_HPP__

#include <unordered_map>

class LRUCache {
private:
    struct Node {
        int key;
        int val;
        Node *prev;
        Node *next;
        Node(int key, int val, Node *prev, Node *next)
            : key(key)
            , val(val)
            , prev(prev)
            , next(next)
        {
        }
    };
    Node *first;
    Node *last;
    int size;
    int capacity;
    std::unordered_map<int, Node *> map;

public:
    LRUCache(int capacity)
        : first(nullptr)
        , last(nullptr)
        , size(0)
        , capacity(capacity)
    {
    }

    int get(int key)
    {
        // can not find
        if (map.find(key) == map.end())
            return -1;

        Node *node = map[key];
        // move node to front
        if (node != first) {
            if (node == last) {
                last = node->prev;
            } else {
                node->next->prev = node->prev;
            }
            node->prev->next = node->next;
            node->next = first;
            node->prev = nullptr;
            first->prev = node;
            first = node;
        }
        return node->val;
    }

    void put(int key, int val)
    {
        // exists
        if (map.find(key) != map.end()) {
            map[key]->val = val;
            Node *node = map[key];
            // move node to front
            if (node != first) {
                if (node == last) {
                    last = node->prev;
                } else {
                    node->next->prev = node->prev;
                }
                node->prev->next = node->next;
                node->next = first;
                node->prev = nullptr;
                first->prev = node;
                first = node;
            }
            return;
        }

        Node *node = new Node(key, val, nullptr, first);
        if (first != nullptr)
            first->prev = node;
        if (last == nullptr)
            last = node;
        first = node;
        size++;
        map[key] = node;

        if (size > capacity) {
            Node *out = last;
            last = last->prev;
            out->prev->next = nullptr;
            map.erase(out->key);
            delete out;
            size--;
        }
    }
};
#endif // __LRU_HPP__
