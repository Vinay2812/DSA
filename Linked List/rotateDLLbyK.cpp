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

Node *rotateDLLByK(Node *head,int k)
{
    if(head==NULL || head->next==NULL || k==0)return head;
    Node *s1=head,*s2=NULL,*t1=NULL,*t2=NULL;
    int count=0;//1 2 3 4 5 6
    for (int i = 1; i < k; i++)
    {
        count++;
        head = head->next;
        if (head == NULL)
            break;
    }
    if (head == NULL)
        return rotateDLLByK(s1, (k % count));

    if (t1 == NULL)
        t1 = head;

    if (s2 == NULL)
        s2 = head->next;

    if(s2==NULL)
        return s1;

    t2=s2;

    while(t2->next!=NULL)t2=t2->next;

   
    t2->next=s1;
    s1->prev=t2;
    t1->next=NULL;
    s2->prev=NULL;

    return s2;    
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
    vector<int> arr{1,2,3,4,5,6};
    auto p = create(arr);

    Node *head = p.first;
    Node *tail = p.second;

    print(head);
    int k=12;
    head=rotateDLLByK(head,k);
    print(head);
    return 0;
}