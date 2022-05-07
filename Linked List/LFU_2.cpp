#include <bits/stdc++.h>
using namespace std;

class LFUCache
{
private:
    struct Node
    {
        int key, value, frequency;
        Node *next, *prev;
        Node(int k, int v)
        {
            key = k;
            value = v;
            frequency = 1;
            next = prev = NULL;
        }
    };
    int count,cap,minFreq;
    list<Node*>dq;

    unordered_map < int, list<Node*>> frequencyList;
    unordered_map < int, list<Node*>::iterator> mp;

public:
    LFUCache(int capacity)
    {
        count = 0;
        cap = capacity;
        minFreq = 1;
        frequencyList.clear();
        mp.clear();
    }
    void updateFrequencyList(list<Node *>::iterator n)
    {
        Node *node = (*n);

            frequencyList[node->frequency].remove(node);

            if (node->frequency == minFreq && frequencyList[node->frequency].empty())
                minFreq++;

            list<Node*> nextList;
            if (frequencyList.find(node->frequency + 1) != frequencyList.end())
                nextList = frequencyList[node->frequency + 1];

            node->frequency++;
            nextList.push_front(node);
            frequencyList[node->frequency] = nextList;
            mp[node->key] = frequencyList[node->frequency].begin();
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1;

        int val = (*mp[key])->value;
        updateFrequencyList(mp[key]);
        return val;
    }

    void set(int key, int value)
    {
        if (cap == 0)
            return;

        if (mp.find(key) != mp.end())
        {
            (*mp[key])->value = value;
            updateFrequencyList(mp[key]);
            return;
        }
        if (count == cap)
        {
            Node *node = frequencyList[minFreq].back();
            mp.erase(node->key);
            frequencyList[minFreq].remove(node);
            count--;
        }
        minFreq = 1;
        count++;
        list<Node*>newList;
        if (frequencyList.find(minFreq) != frequencyList.end())
            newList = frequencyList[minFreq];

        Node *node = new Node(key, value);
        newList.push_front(node);
        frequencyList[minFreq] = newList;
        mp[key] = frequencyList[minFreq].begin();
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    LFUCache lf(2);

    lf.set(1, 2);
    lf.set(2, 3);
    lf.set(3, 4);
    cout << lf.get(1) << " "; //->-1
    cout << lf.get(3) << " "; //->4   // 2->1   3->2
    lf.set(2, 2);//2->2  3->2
    lf.set(4, 5);//4->1 2->2
    cout << lf.get(2) << " "; //2
    cout << lf.get(3) << " "; //-1
    return 0;
}