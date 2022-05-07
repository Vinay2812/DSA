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

int checkCL(Node *head)
{
    Node *tail=head->next;

    while(tail!=NULL)
    {
        if(head==tail)return 1;

        tail=tail->next;
    }

    return 0;
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

    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
    //cout<< "NULL\n";
}

int main()
{
    vector<int> arr = {2, 5, 3, 2, 1, 1, 3, 4};
    Node *head = create(arr);
    Node *tail = head;
    while (tail->next != NULL)
        tail = tail->next;

    tail->next = head;
    print(head);
    cout<<"\n"<<checkCL(head);
}