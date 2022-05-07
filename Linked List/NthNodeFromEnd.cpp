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



int nthNode(Node *head,int k)
{
    if (head == NULL)
        return -1;

    Node *t1 = head, *t2 = head;
    for (int i = 0; i < k; i++)
    {
        if (t1 != NULL)
        {
            t1 = t1->next;
        }
        else
        {
            return -1;
        }
    }
    while (t1 != NULL)
    {
        t2 = t2->next;
        t1 = t1->next;
    }

    return t2->data;
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
    vector<int> arr1 = {1,2,3,4,5,6,7,8,9,10};
   
    Node *head1 = create(arr1);
    print(head1);

   cout<<(nthNode(head1,10));
}
