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

bool checkLoop(Node *head)
{
    Node *slow=head,*fast=head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast)return true;
    }

    return false;
}

Node *startPoint(Node *head)
{
    Node *slow=head,*fast=head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast)break;
    }

    if(fast==NULL || fast->next==NULL)return NULL;

    slow=head;

    while(slow!=fast)
    {
        slow=slow->next;
        fast=fast->next;
    }

    return slow;

}

void deleteLoop(Node * head)
{
    Node *slow=head,*fast=head;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast)break;
    }

    if(fast==NULL || fast->next==NULL)return;

    slow=head;
    Node *tail=NULL;
    while(slow!=fast)
    {
        slow=slow->next;
        tail=fast;
        fast=fast->next;
    }

    do
    {
       fast=fast->next;
    } while (fast->next!=slow);
    

    // if(tail!=NULL)
    // tail->next=NULL;
    fast->next=NULL;
    
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
    Node *random=head;
    for(int i=0;i<3;i++)
    {
        random=random->next;
    }
    Node *tail=head;
    while(tail->next!=NULL)
    tail=tail->next;

    tail->next=random;

    //cout<<startPoint(head)->data;
    //cout<<((checkLoop(head)==1)?"true":"false");
    deleteLoop(head);
    print(head);
    
}