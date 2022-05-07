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

Node *insertAtBegin(Node *head,int val)
{
    if(head==NULL)
        return new Node(val);

    Node *node=new Node(val);

    node->next=head;
    head->prev=node;
    
    return node;
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

// 1 2 3   5 6 7
//       4
Node *insertAtPos(Node *head,int pos,int val)
{
    if(head==NULL)return new Node(val);

    if(pos==0)
        return insertAtBegin(head,val);
    Node *temp=head;

    for(int i=0;i<pos-1;i++)
    {
        if(temp->next!=NULL)
        temp=temp->next;
        else
        break;
    }

    if(temp->next==NULL)
        insertAtTail(temp,val);

    Node *node=new Node(val);

    node->next=temp->next;
    node->prev=temp;
    temp->next=node;
    node->next->prev=node;

    return head;

}
pair<Node *,Node*> create(vector<int>arr)
{
    Node *head=NULL;
    Node *tail=NULL;
    for(auto x : arr){
        // head=insertAtBegin(head,x);
        // if(tail==NULL)
        // tail=head;

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
    vector<int>arr{1,2,3,5,6};
    auto p=create(arr);

    Node *head=p.first;
    Node *tail=p.second;

    print(head);
    head=insertAtPos(head,3,4);
    print(head);
    //print(tail);
    return 0;
}