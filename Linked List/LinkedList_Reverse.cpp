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

// NULL<-1<-2<-3<-4     //nh=4
//       h               
Node *reverseRecursion(Node *head)
{
    if(head==NULL || head->next==NULL)
    return head;

    Node *newHead=reverseRecursion(head->next);
    head->next->next=head;
    head->next=NULL;

    return newHead;
}
Node *reverse(Node *head)
{
    Node *p=NULL,*c=head,*n;

    while(c!=NULL)
    {
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }

    return p;
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
    cout<<"NULL";
}

int main()
{
    vector<int>arr={1,2,3,4,5,6};
    Node *head=create(arr);
    print(head);
    cout<<endl;
    //head=reverse(head);
    head=reverseRecursion(head);
    print(head);
    
}