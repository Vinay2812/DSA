#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

struct mycmp{
    int operator()(Node *&a,Node *&b){
        return a->data > b->data;
    }
};

Node *mergeKSortedList(Node *head[] ,int k)
{
    priority_queue<Node *,vector<Node*>,mycmp>pq;

    for(int i=0;i<k;i++)
    {
        pq.push(head[i]);
    }
    Node *s=new Node(-1);
    Node *t=s;
    while(!pq.empty())
    {
        t->next=pq.top();
        t=t->next;
        pq.pop();

        if(t->next!=NULL)
            pq.push(t->next);
    }

    t->next=NULL;
    return s->next;
}

Node *insertAtTail(Node *head, int d)
{
    if (head == NULL)
    {
        return new Node(d);
    }

    Node *tail = head;

    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->next = new Node(d);

    return head;
}

Node *create(vector<int> &arr)
{
    Node *head = NULL;

    for (int i = 0; i < arr.size(); i++)
    {
        head = insertAtTail(head, arr[i]);
    }

    return head;
}

void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main()
{
    int k;
    cin>>k;

    Node *head[k];
    vector<int>arr;
    
    for(int i=0;i<k;i++){
        int n;
        cin>>n;
        for(int j=0;j<n;j++){
            int data;
            cin>>data;
            arr.push_back(data);
        }
        head[i]=create(arr);
        arr.clear();
    }
    cout<<endl;
    for(int i=0;i<k;i++){
        print(head[i]);
    }
    cout<<"\nAfter Merging K list :\n\n";
   Node *head1=mergeKSortedList(head ,k);

    print(head1);
}