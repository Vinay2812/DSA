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
                h1
    1->2->3->4->NULL  
    
    1->2->3->4->NULL          s(-1)->3->4
    
          h2
    3->4->5->1->NULL
    
            t
    5 3 2 6 1
                    
    6 1 7 8 9

*/


Node *unsortedUnion(Node *h1,Node *h2)
{
    if(h1==NULL)
    return h2;

    if(h2==NULL)
    return h1;

    Node *head=h1;
    unordered_map<int,int>um;

    while(h1->next!=NULL)
    {
        um[h1->data]++;
        h1=h1->next;
    }
    um[h1->data]++;

    Node *t=h1;

    while(h2!=NULL)
    {
        if(um[h2->data]==0)
        {
            t->next=h2;
            t=t->next;
        }
        h2=h2->next;
  
    }
    t->next=NULL;

    return head;

}

Node *Intersection(Node *h1,Node *h2)
{
    // if(h1==NULL || h2==NULL)return NULL;
        

    // Node *s=new Node(-1);
    // Node *t=s;

    // while(h1!=NULL && h2!=NULL)
    // {
    //     if(h1->data==h2->data)
    //     {
    //         t->next=h1;
    //         t=t->next;

    //         h1=h1->next;
    //         h2=h2->next;
    //     }
    //     else if(h1->data<h2->data)
    //     {
    //         h1=h1->next;
    //     }
    //     else
    //     {
    //         h2=h2->next;   
    //     }
        
    // }
    
    // t->next=NULL;

    // return s->next;

    // O(n + m)
    // O(min(n,m)) ->O(1)
    

    Node *s=new Node(-1);
    Node *t=s;

    while(h1!=NULL && h2!=NULL)
    {
        // while(h1->next!=NULL && h1->data ==h1->next->data)
        // h1=h1->next;

        // while (h2->next != NULL && h2->data == h2->next->data)
        // h2 = h2->next;

        if(h1->data == h2->data)
        {
            t->next=h1;
            t=t->next;
            h1=h1->next;
            h2=h2->next;
        }
        else if(h1->data<h2->data)
        {
            h1=h1->next;
        }
        else
        {
           //h2->data<h1->data
           h2=h2->next;
        }
     
    }
    t->next = NULL;

    return s->next;
    
}
Node *Union(Node *h1,Node *h2)
{
    if(h1==NULL)
        return h2;
    
    if(h2==NULL)
        return h1;

    Node *s=new Node(-1);
    Node *t=s;

    while(h1!=NULL && h2!=NULL)
    {
        if(h1->data == h2->data)
        {
            t->next=h1;
            h1=h1->next;
            h2=h2->next;
        }
        else if(h1->data<h2->data)
        {
            t->next=h1;
            h1=h1->next;
        }
        else
        {
            t->next=h2;
            h2=h2->next;
        }
        t=t->next;
    }

    if(h1!=NULL)
        t->next=h1;
    else
        t->next=h2;

    return s->next;
    
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
    vector<int>arr1={1,1,2,2,2,3,3};
    vector<int>arr2={2,2,3,3,3};

    Node *head1=create(arr1);
    Node *head2=create(arr2);

    print(head1);
    print(head2);
    Node *head;
    //head=Union(head1,head2);
    head=Intersection(head1,head2);
    //head=unsortedUnion(head1,head2);

    print(head);
    
    
    
}