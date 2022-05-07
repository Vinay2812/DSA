#include<bits/stdc++.h>
using namespace std;

/*
Given 
capacity 
get(int key)
set(int key,int value)

get(key); ->value
-if not exist return -1;
-if exist *update
	     *return value of key
set(key,value)
		*if key exist ->update then return 
		*if key doesn’t exist  
			-if(capacity full)
				delete least recent used 
 then insert
*/
class LRUCache
{
    private:
    int capacity;
    struct Node
    {
        int key,value;
        Node *next,*prev;
        Node(int k,int v)
        {
            key=k;
            value=v;
            next=prev=NULL;
        }
    };

    struct List{
        int size;
        Node *head,*tail;

        List()
        {
            size=0;
            head=new Node(-1,-1);
            tail=new Node(-1,-1);
            head->next=tail;
            tail->prev=head;
        }

        void add(Node *node)
        {
            node->next=head->next;
            node->prev=head;
            head->next->prev=node;
            head->next=node;
            size++;
        }

        void remove(Node *node)
        {
            node->prev->next=node->next;
            node->next->prev=node->prev;
            size--;
        }
    };
    public :
        List * dq;
        unordered_map<int,Node *>mp;
        LRUCache(int cap)
        {
            capacity = cap;
            dq = new List();
            mp.clear();
        }

    void update(Node *node)
    {
        dq->remove(node);
        dq->add(node);
        mp[node->key]=node;
    }

    int get(int key)
    {
        if(mp.find(key)==mp.end())
            return -1;
        
        Node *node=mp[key];
        update(node);
        return node->value;
    }

    void set(int key,int value)
    {
        if(mp.find(key)!=mp.end())
        {
            Node *node=mp[key];
            node->value=value;
            update(node);
            return;
        }

        Node *node=new Node(key,value);

        if(capacity==dq->size)
        {
            Node *node = dq->tail->prev;
            dq->remove(node);
            mp.erase(node->key);
        }

        dq->add(node);
        mp[key]=node;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    LRUCache lc(3);
    cout<<lc.get(1)<<endl;
    lc.set(1,2);
    lc.set(2,2);
    lc.set(3,3);
    cout << lc.get(1) << endl;
    lc.set(4,4);
    cout << lc.get(2) << endl;
    lc.set(2,4);
    cout << lc.get(3) << endl;
    cout << lc.get(5) << endl;
    lc.set(2,3);
    lc.set(4,5);
    lc.set(5,5);
    cout << lc.get(3) << endl;

    return 0;
}

/*
-1
2 
-1
-1
-1
-1*/