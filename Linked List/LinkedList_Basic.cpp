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


Node * insertAtBegin(Node *head,int d)
{
    if(head==NULL)
    {
        return new Node(d);
    }
    
        Node *node=new Node(d);
        node->next=head;
    
    return node;
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

//6->5->3->2->1->NULL;
Node *insertAtPos(Node *head,int pos,int d)
{
    if(pos==0)
    {
        head=insertAtBegin(head,d);
    }

    Node *temp=head;
    
    for(int i=0;i<pos-1;i++)
    {
        if(temp->next!=NULL)
        temp=temp->next;
        else
        break;
    }

    Node *node=new Node(4);
    node->next=temp->next;
    temp->next=node;

    return head;
}


Node * create(vector<int>&arr)
{
    Node *head=NULL;

    for(int i=0;i<arr.size();i++)
    {
        //head=insertAtBegin(head,arr[i]);
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
    //create new node
    //Node *head=new Node(1);

    //delete node
    //delete head;

    vector<int>arr={6,5,3,2,1};
    Node *head=create(arr);

    print(head);

    head=insertAtPos(head,2,4);
    cout<<endl;
    print(head);
    

}