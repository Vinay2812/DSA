#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node * reverse(Node *head)
{
    Node *prev=NULL,*next;

    while(head!=NULL)
    {
        next=head->next;
        head->next=prev;
        prev=head;
        head=next;
    }

    return prev;
}


Node * reverseRecurr(Node * head)
{
    if(head==NULL || head->next==NULL)return head;

    Node * newHead=reverseRecurr(head->next);

    head->next->next=head;
    head->next=NULL;

    return newHead;
}

Node * insertAtTail(Node *head,int d)
{
    if(head==NULL)
    {
            return new Node(d);
    }
    
    Node *tail=head;

    while(tail->next!=NULL)
    {
        tail=tail->next;
    }

    tail->next=new Node(d);

    return head;
}




Node * create(vector<int>&arr)
{
    Node *head=NULL;

    for(int i=0;i<arr.size();i++)
    {
        head=insertAtTail(head,arr[i]);
    }

    return head;
}

void print(Node *head)
{
    Node *temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}

int main()
{
    vector<int>arr={1,2,3,5,6,7};
    Node *head=create(arr);

    print(head);
    //head=reverse(head);
    head=reverseRecurr(head);
    print(head);
 
}