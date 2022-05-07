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

int countPairs(Node *head,int k)
{
    if(head==NULL)return -1;
    int count=0;

    Node *tail=head;
    while (tail->next != NULL )
    {
        tail = tail->next;
    }

    while(head!=tail and tail->next!=head)
    {
        int sum = head->data +tail->data;
        if (sum==k)
        {
            count++;
            while(head->next!=tail && head->data==head->next->data)
            head=head->next;
            while (tail->prev!=head && tail->data==tail->prev->data)
            tail = tail->prev;
            head=head->next;
            tail=tail->prev;
           
        }
        if(sum>k)
        {
            tail=tail->prev;
        }
        else
        {
            head=head->next;
        }
        
    }

    return count;
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
    vector<int>arr{1,1,2,2,3,3};
    auto p=create(arr);

    Node *head=p.first;
    Node *tail=p.second;

    print(head);
    cout<<countPairs(head,4);
    return 0;
}
