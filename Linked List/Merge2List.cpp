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

/*
s(-1)->1->2->3->4->5->6->7->8->9->NULL

               h1
           7->NULL
           

             h2
             
          
*/

Node *merge(Node *h1,Node *h2)
{
    if(h1==NULL)
    return h2;

    if(h2==NULL)
    return h1;

    Node *start=new Node(-1);
    Node *tail=start;

    while(h1!=NULL && h2!=NULL)
    {
        if(h1->data < h2->data)
        {
            tail->next=h1;
            h1=h1->next;    
        }
        else
        {
            tail->next=h2;
            h2=h2->next;
        }
         tail=tail->next;
    }

    tail->next=NULL;

    if(h1!=NULL)
    {
        tail->next=h1;
    }

    if(h2!=NULL)
    {
        tail->next=h2;
    }

    return start->next;
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
    vector<int>arr1={1,4,7,9};
    vector<int>arr2={2,3,5,6,8,9,10};

    Node *head1=create(arr1);
    Node *head2=create(arr2);

    print(head1);
    print(head2);
    Node *head=merge(head1,head2);

    print(head);
    
    
    
}