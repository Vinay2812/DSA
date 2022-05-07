#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *prev,*next;

    Node(int val)
    {
        data=val;
        prev=NULL;
        next=NULL;
    }
};
// NULL 1  2 3 4  NULL
//   p  c  n
//NULL  4  3  2  1  NULL

Node *reverseDLLrecurr(Node *head)
{
    if(head==NULL || head->next==NULL)return head;

    Node *newHead=reverseDLLrecurr(head->next);

    head->next->next=head;
    head->prev=head->next;
    head->next=NULL;

    return newHead;

}
Node *reverseDLL(Node *head)
{
   Node *p=NULL,*n=NULL;

   while(head!=NULL)
   {
       n=head->next;
       head->prev=n;
       head->next=p;
       p=head;
       head=n;
   }

   return p;
}

Node *insertAtTail(Node *tail,int val)
{
    if(tail==NULL)
    return new Node(val);

    Node *node=new Node(val);
    node->prev=tail;
    tail->next=node;

    return node;
}
pair<Node *,Node*> create(vector<int>arr)
{
    Node *head=NULL;
    Node *tail=NULL;
    for(auto x : arr){
        tail=insertAtTail(tail,x);
        if(head==NULL)
        head=tail;
    }

    return {head,tail};
}
void print(Node *head)
{
    Node *temp=head;

    if(head->next!=NULL){
    while(temp!=NULL)
    {
        cout<<temp->data<<"<=>";
        temp=temp->next;
    }
    cout<<"NULL\n";
    }
else{
    while(temp!=NULL)
    {
        cout<<temp->data<<"<=>";
        temp=temp->prev;
    }
    cout<<"NULL\n";
    }
}

int main()
{
    vector<int>arr{1,2,3,4,5,6};
    auto p=create(arr);

    Node *head=p.first;
    Node *tail=p.second;

    print(head);
    // head=reverseDLL(head);
    head = reverseDLLrecurr(head);
    print(head);
    //print(tail);
    return 0;
}