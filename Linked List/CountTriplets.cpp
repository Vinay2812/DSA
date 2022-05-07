#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *prev, *next;

    Node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

vector<vector<int>> countTriplets(Node *head, int x)
{
    vector<vector<int>>ans; 
    
    if (head == NULL || head->next == NULL)
        return ans;


    Node *i = head, *j = head->next, *k, *tail = head;

    while (tail->next != NULL)
        tail = tail->next;

    k = tail;
    while (i!=NULL)
    {
        j = i->next;
        k = tail;
        while (j!=NULL && k!=NULL && j != k  && k->next != j)
        {
            int sum = i->data + j->data + k->data;

            if (sum == x)
            {
                ans.push_back({i->data, j->data, k->data});
                j = j->next;
                k = k->prev;
            }
            else if (sum < x)
                j = j->next;
            else
                k = k->prev;
        }
        i = i->next;
    }

    return ans;
}
Node *insertAtTail(Node *tail, int val)
{
    if (tail == NULL)
        return new Node(val);

    Node *node = new Node(val);
    node->prev = tail;
    tail->next = node;

    return node;
}
pair<Node *, Node *> create(vector<int> arr)
{
    Node *head = NULL;
    Node *tail = NULL;
    for (auto x : arr)
    {
        tail = insertAtTail(tail, x);
        if (head == NULL)
            head = tail;
    }

    return {head, tail};
}
void print(Node *head)
{
    Node *temp = head;

    if (head->next != NULL)
    {
        while (temp != NULL)
        {
            cout << temp->data << "<=>";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    else
    {
        while (temp != NULL)
        {
            cout << temp->data << "<=>";
            temp = temp->prev;
        }
        cout << "NULL\n";
    }
}

int main()
{
    vector<int> arr{1, 2,3};
    auto p = create(arr);

    Node *head = p.first;
    Node *tail = p.second;

    print(head);
    auto v= countTriplets(head, 6);

    cout<<v.size()<<endl;
    for(auto x : v)
    {
        for(auto y : x)
            cout<<y<<" ";

        cout<<endl;
    }
    return 0;
}