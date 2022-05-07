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
  1->9->9       0->0->0 
                      h      var=1  c=1;   
            //  0->0->0->1
  c=1;

  if(carry==1)tail->next=new Node(carry);

  var=(head->data+c)/10;
  head->data=(head->data+c)%10
  c=var;
  
*/

Node *reverse(Node *head)
{
    Node *p = NULL, *n = NULL;

    while (head != NULL)
    {
        n = head->next;
        head->next = p;
        p = head;
        head = n;
    }
    return p;
}

Node *addNum(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    head1 = reverse(head1);
    head2 = reverse(head2);

    Node *tail1 = head1, *tail2 = head2;
    int carr = 0, var;

    while (tail1 != NULL && tail2 != NULL)
    {
        var = (tail1->data + tail2->data + carr) / 10;
        tail1->data = (tail1->data + tail2->data + carr) % 10;
        carr = var;

        if (tail1->next == NULL && tail2->next != NULL)
        {
            tail1->next = tail2->next;
            tail2->next = NULL;
        }

        tail1 = tail1->next;
        tail2 = tail2->next;
    }

    while (tail1 != NULL && carr == 1)
    {
        var = (tail1->data + carr) / 10;
        tail1->data = (tail1->data + carr) % 10;
        carr = var;
        tail1 = tail1->next;
    }

    if (tail1 == NULL && carr == 1)
    {
        Node *node = new Node(1);
        node->next = reverse(head1);
        return node;
    }

    return reverse(head1);
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
    vector<int> arr1 = {9, 9, 9};
    vector<int> arr2 = {9, 9, 9};
    Node *head1 = create(arr1);
    Node *head2 = create(arr2);
    print(head1);
    print(head2);
    print(addNum(head1, head2));
}
