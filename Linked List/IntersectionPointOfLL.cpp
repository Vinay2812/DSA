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
/*

*/

Node *intersectPoint(Node *h1,Node *h2)
{
    // int n1=0,n2=0;
    // Node *temp1=h1;
    // Node *temp2=h2;

    // while(temp1!=NULL && ++n1)temp1=temp1->next;
    // while(temp2!=NULL && ++n2)temp2=temp2->next;

    // int diff=abs(n1-n2);

    // if(n1<n2)
    // swap(h1,h2);

    // for(int i=0;i<diff;i++)
    // h1=h1->next;

    // while(h1!=NULL && h2!=NULL)
    // {
    //     if(h1==h2)return h1;

    //     h1=h1->next;
    //     h2=h2->next;
    // }

    // return NULL;
    Node *t1=h1,*t2=h2;

    while(t1!=t2)
    {
        t1=t1->next;
        t2=t2->next;

        if(t1==t2)return t1;
        if(t1==NULL)t1=h2;
        if(t2==NULL)t2=h1;
    }

    return t1;

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
    vector<int> arr2 = {1,2,3,4,5,-1,7,8,9};
    vector<int> arr1 = {6,7,10};

    Node *head1 = create(arr1);
    Node *head2 = create(arr2);
    Node *temp=head2;
    Node *tail2=head1;

    for(int i=0;i<5;i++)
    temp=temp->next;

    while(tail2->next!=NULL)
    {
        tail2=tail2->next;
    }
    tail2->next=temp;

    print(head1);
    print(head2);

   Node *node=intersectPoint(head1,head2);

   cout<<((node==NULL)?NULL:node->data);
    
    
}