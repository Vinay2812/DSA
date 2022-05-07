#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *deleteNodesrecurr(Node *head)
{
    if(head==NULL || head->next==NULL)
        return head;

    Node *nxt=deleteNodesrecurr(head->next);

    if(head->data >= nxt->data)
    {
        head->next=nxt;
        return head;
    }
    else
    {
        return nxt;
    }
    
}

Node *reverse(Node *head)
{
    Node *prev=NULL,*next=NULL;

    while(head!=NULL)
    {
        next=head->next;
        head->next=prev;
        prev=head;
        head=next;
    }

    return prev;
}

Node *deleteNode(Node *head)
{
    if(head==NULL || head->next==NULL)
        return head;

    Node *s=new Node(-1);
    Node *t=s;

    int max=INT_MIN;
    Node *prev=NULL;

    head=reverse(head);

    while(head!=NULL)
    {
        if(head->data >= max)
        {
            max=head->data;
            t->next=head;
            t=t->next;
            prev=head;
        }
        else
        {
            prev->next=head->next;
        }
        head=head->next;
    }

    return reverse(s->next);
}

Node *insertAtTail(Node *head, int d)
{
    if (head == NULL)
    {
        return new Node(d);
    }

    Node *tail = head;

    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->next = new Node(d);

    return head;
}

Node *create(vector<int> &arr)
{
    Node *head = NULL;

    for (int i = 0; i < arr.size(); i++)
    {
        head = insertAtTail(head, arr[i]);
    }

    return head;
}

void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main()
{
    vector<int> arr1 = {5,2 ,7 ,3 ,1};

    Node *head1 = create(arr1);
    print(head1);
    //print(deleteNodesrecurr(head1));
    print(deleteNode(head1));
    
}
