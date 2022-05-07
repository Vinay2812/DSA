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
                            1->1->2->2->3   3->4->5->NULL
     s=2                                                     f=1
     2->2->3->5->NULL                                     1->1->3->4->NULL;
   
    s ->h=2              f =2
    2->5->NULL          2->3->NULL

    s       f           s         f
    2->NULL 5->NULL     3->NULL  2->NULL

        h               h
        2->5->NULL      2->3->NULL
   
*/
Node *merge(Node *h1,Node *h2)
{
    if(h1==NULL)return h2;
    if(h2==NULL)return h1;

    Node *s=new Node(-1);
    Node *t=s;

    while(h1!=NULL && h2!=NULL)
    {
        if(h1->data<h2->data)
        {
            t->next=h1;
            h1=h1->next;
        }
        else
        {
            //h2->data < h1->data
            t->next=h2;
            h2=h2->next;
        }

        t=t->next;
        
    }
    //t->next=NULL;
    if(h1!=NULL)t->next=h1;
    else t->next=h2;

    return s->next;
}

Node * mergeSort(Node *head)
{
    if(head==NULL || head->next==NULL)return head;

    Node *slow=head,*fast=head->next;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    fast=slow->next;
    slow->next=NULL;
    slow=head;

    slow=mergeSort(slow);
    fast=mergeSort(fast);
    head=merge(slow,fast);

    return head;
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
    vector<int>arr={2,5,3,2,1,1,3,4};
    Node *head=create(arr);
    print(head);
    head=mergeSort(head);
    print(head);
   
    
}