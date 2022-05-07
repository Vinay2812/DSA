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
Node * segregate(Node *head)
{
    Node *even=new Node(-1);
    Node *t2=even;

    Node *prev=NULL,*curr=head;
    head = NULL;

    while(curr!=NULL)
    {
        if((curr->data )%2==0)
        {
            Node *nxt=curr->next;
            if(prev!=NULL)prev->next=nxt;

            curr->next=NULL;
            t2->next=curr;
            t2=curr;
            curr=nxt;
        }
        else
        {
            if(head==NULL)head=curr;
            prev=curr;
            curr=curr->next;
        }
        
    }
    t2->next=head;
    return even->next;
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
    cout << "NULL";
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node *head = create(arr);
    print(head);
    cout << endl;
    head=segregate(head);
    print(head);
}