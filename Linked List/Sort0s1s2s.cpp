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

//Dutch National Flag sort algo (DNF algorithm)

Node *sort0s1s2s(Node *head)
{
    Node *zero=new Node(-1);
    Node *z=zero;

    Node *one=new Node(-1);
    Node *o=one;

    Node *prev=NULL,*curr=head,*temp;
    head=NULL;

    while(curr!=NULL)
    {
        temp = curr->next;
        if(curr->data==2)
        {
            if(head==NULL)head=curr;
            prev=curr;
        }
        else
        {
            
            if(prev!=NULL)prev->next=temp;
            curr->next=NULL;

            if(curr->data==0)
            {
                z->next=curr;
                z=curr;
            }
            else
            {
                o->next=curr;
                o=curr;
            }
        }
        curr=temp;
    }

    //if(prev!=NULL)prev->next=NULL;

    o->next=head;
    z->next=one->next;

    return zero->next;
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
    vector<int> arr = {2,1,1,0,2,2,1,0,1};
    Node *head = create(arr);
    print(head);
    head = sort0s1s2s(head);
    print(head);
}