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
Input->     
o  e  o
1->2->6->7->3->4->NULL
h  eh
Output->
1->6->3->2->7->4->NULL
              
*/

Node *oddEven(Node *head)
{
    if(head==NULL || head->next==NULL)return head;

    Node *oddTail=head,*evenHead=head->next,*evenTail=evenHead;

    while(oddTail->next!=NULL && evenTail->next!=NULL)
    {
        oddTail->next=evenTail->next;
        oddTail=oddTail->next;
        evenTail->next=oddTail->next;
        evenTail=evenTail->next;
    }

    if(evenTail!=NULL)
    evenTail->next=NULL;

    oddTail->next=evenHead;
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
    vector<int>arr={1,2,3,5,6,7};
    Node *head=create(arr);

    print(head);
    head=oddEven(head);
    print(head);
 
}