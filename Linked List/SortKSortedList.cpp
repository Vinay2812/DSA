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

struct cmp{
    int operator()(Node * &a,Node *&b)
    {
        return a->data>b->data;
    }
};

Node *sortKSortedList(Node *head, int k)
{
   
   /* Node *kthNode = head;
    Node *i = head, *j;
    for (int i = 0; i < k+1; i++)
    {
        kthNode = kthNode->next;
    }
    
    while (kthNode != NULL)
    {
        j = kthNode;
        while (j != i && j->data < j->prev->data)
        {
            swap(j->data, j->prev->data);
            j=j->prev;
        }
        kthNode=kthNode->next;
        i=i->next;
    }

    return head;*/
    
    priority_queue<Node *,vector<Node*>,cmp>pq;

    for(int i=0;i<k;i++){
        pq.push(head);
        head=head->next;

        if(head == NULL)
            break;
    }

    Node *s=new Node(-1);
    Node *t=s;

    while(!pq.empty())
    {
        t->next=pq.top();
        t->next->prev=t;
        pq.pop();
        t=t->next;

        if(head!=NULL){
            pq.push(head);
            head=head->next;
        }
    }
    t->next = NULL;
    s->next->prev=NULL;
    return s->next;
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
    vector<int> arr{3,6,2,12,56,8};
    auto p = create(arr);

    Node *head = p.first;
    Node *tail = p.second;

    print(head);
    // head=reverseDLL(head);

    cout<<"After Sorting :"<<endl;
    head = sortKSortedList(head,3);
    print(head);
    tail=head;
    while(tail->next!=NULL)tail=tail->next;

    print(tail);
    return 0;
}