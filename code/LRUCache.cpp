// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// design the class in the most optimal way
struct Node
{
    int key;
    int val;
    Node *prev;
    Node *next;

    Node(int k, int v)
    {
        key = k;
        val = v;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache
{
private:
public:
    static int capacity;
    static Node *head;
    static Node *tail;
    static unordered_map<int, Node *> um;
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        capacity = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    static void insertAt(Node *node)
    {
        node->next = head->next;
        node->prev = head;
        node->next->prev = node;
        head->next = node;
    }

    static void deleteAt(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    //Function to return value corresponding to the key.
    static int get(int key)
    {
        if (um.find(key) == um.end())
            return -1;
        else
        {
           Node *node=um[key];
           int res=node->val;
           um.erase(key);
            deleteAt(node);
            insertAt(node);

            um[key]=node;
            return res;
        }
    }

    //Function for storing key-value pair.
    static void set(int key, int value)
    {
        Node *node = new Node(key, value);
        if (um.find(key) != um.end())
        {
            deleteAt(node);
            insertAt(node);
        }
        else
        {

            int del;
            if (um.size() == capacity)
            {
                del = tail->prev->key;
                tail->prev = tail->prev->prev;
                tail->prev->next = tail;
                um.erase(del);
            }
            insertAt(node);   
        }
        um[key] = node;
    }
};
Node *LRUCache::head;
Node *LRUCache::tail;
unordered_map<int, Node *> LRUCache::um;
int LRUCache ::capacity;

// { Driver Code Starts.

int main()
{
    LRUCache ca(2);
    LRUCache::set(1,2);
    // LRUCache::set(2, 2);
    // LRUCache::set(3, 3);
    cout << LRUCache::get(1);
    // LRUCache::set(4, 4);
    // cout << LRUCache::get(1);

    return 0;
}
// } Driver Code Ends
