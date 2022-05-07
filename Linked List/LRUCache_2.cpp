#include <bits/stdc++.h>
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
    struct Node{
        int key,val;
        Node(int k,int v)
        {
            key =k;
            val=v;
        }
    };
private:
    list<pair<int, int>> dq;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    int capacity;
public:
    
    LRUCache(int cap)
    {
        capacity = cap;
        dq.clear();
        mp.clear();
    }

    void update(list<pair<int, int>>::iterator it)
    {
        dq.erase(it);
        dq.push_front({it->first,(*it).second});
        mp[(*it).first] = dq.begin();
    }

    int get(int key)
    {
        if(mp.find(key)==mp.end())
            return -1;
        
        auto it=mp[key];
        update(it);
        return it->second;
    }

    void set(int key, int value)
    {
        if(mp.find(key)!=mp.end())
        {
            auto it=mp[key];
            it->second=value;
            update(it);
            return;
        }

        if(capacity==dq.size())
        {
            int key=dq.back().first;
            dq.pop_back();
            mp.erase(key);
        }

        dq.push_front({key,value});
        mp[key]=dq.begin();
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    LRUCache lc(3);
    cout << lc.get(1) << endl;
    lc.set(1, 2);
    lc.set(2, 2);
    lc.set(3, 3);
    cout << lc.get(1) << endl;
    lc.set(4, 4);
    cout << lc.get(2) << endl;
    lc.set(2, 4);
    cout << lc.get(3) << endl;
    cout << lc.get(5) << endl;
    lc.set(2, 3);
    lc.set(4, 5);
    lc.set(5, 5);
    cout << lc.get(3) << endl;

    return 0;
}