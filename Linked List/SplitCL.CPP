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

pair<Node*,Node*> splitCL(Node *head) //(Node *head,Node **head1,Node **head2)
{
    if(head==NULL)return {NULL,NULL};//*head1=NULL,*head2=NULL
    if(head->next==head) return {head,NULL};//*head1=.....

    Node *slow=head,*fast=head->next,*tail=NULL;

    while(fast!=head && fast->next!=head)
    {
        slow=slow->next;

        if(fast->next->next==head)
        tail=fast->next;

        fast=fast->next->next;
    }
    if(tail==NULL)
    tail=fast;

    fast=slow->next;

    slow->next=head;
    tail->next=fast;

    return {head,fast};//*head1=head,*head2=fast
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

    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
    //cout<< "NULL\n";
}

int main()
{
    vector<int> arr = {2, 5, 3, 2, 1, 1, 3, 4};
    Node *head = create(arr);
    Node *tail = head;
    while (tail->next != NULL)
        tail = tail->next;

    tail->next = head;
    Node **head1,**head2;
    print(head);

    pair<Node *, Node *> p = splitCL(head /*,*head1,*head2*/);
    cout<<"\n";
    print(p.first);
    cout << "\n";
    print(p.second);
}