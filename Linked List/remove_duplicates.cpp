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

*/

Node *removeDuplicatesUnsorted(Node *head)
{
    if(head==NULL || head->next==NULL)return head;

    unordered_map<int,int>um;
    //            head data,count

    Node *s=new Node(-1);
    Node *t=s;

    // Node *s=head;
    // Node *t=s;

    // um[head->data]++;
    // head=head->next;

    while(head!=NULL)
    {
        if(um[head->data]==0)
        {
            t->next=head;
            t=t->next;
        }

        um[head->data]++;
        head=head->next;
    }
    t->next=NULL;

    //return s;
    return s->next;
}

Node *removeDuplicates(Node *head)
{

    if(head==NULL || head->next==NULL)return head;

    // Node *s=head;
    // Node *t=s;

    // while(head->next!=NULL)
    // {
    //     if(t->data!=head->next->data)
    //     {
    //         t->next=head->next;
    //         t=t->next;
    //     }

    //     head=head->next;
    // }

    // t->next=NULL;
    // return s;

    Node *s=new Node(-1);
    Node *t=s;

    while(head->next!=NULL)
    {
        if(head->data !=head->next->data)
        {
            t->next=head;
            t=t->next;
        }

        head=head->next;
    }
    t->next=head;
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
    vector<int>arr={2,1,3,1,2,4,5,5};
    Node *head=create(arr);
    print(head);
   // head=removeDuplicates(head);
    head=removeDuplicatesUnsorted(head);
    print(head);
   
    
}