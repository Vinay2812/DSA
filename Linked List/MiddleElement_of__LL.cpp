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
     
1->2->3->4->5->NULL
s          
1->2->6->7->3->4->NULL
   f               
*/

int findMiddle(Node *head)
{
    if(head==NULL) return -1;
    if(head->next==NULL)return head->data;

    Node *slow=head,*fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow->data;
    
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
    vector<int>arr={1,2,3,5,6};
    Node *head=create(arr);
    print(head);
    cout<<findMiddle(head);
    
    
}