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
//tc-> o(n + n +n)->O(3n)
//sc->O(n+n)->O(2n)
  3->2->1->4->5->6->7->NULL   k=3       3 2 1 6 5 4 7 
  p     h  c   
  3->2->1->6->5->4->7->NULL
*/

Node *reverseKNodes(Node *head,int k)
{
    if(head==NULL || head->next==NULL)return head;

    Node *prev=NULL,*curr=head,*next=NULL;

    for(int i=0;i<k;i++)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;

        if(curr==NULL)
        break;
    }

    if(head!=NULL)
    head->next=reverseKNodes(curr,k);

    return prev;
    
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
    vector<int>arr={1,2,3,4,5,6,7,8};
    Node *head=create(arr);
    print(head);
    head=reverseKNodes(head,3);
    print(head);
    
}