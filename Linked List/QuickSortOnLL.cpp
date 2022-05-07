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
Approach is -> 

in Partition function ->
consider last element as pivot 
add all the greater elements after pivot and update tail

After getting the partition Node->
Apply quicksort on left of pivot and right of pivot
since its singly list...we have to traverse from head to pivot to get tail for left part

after quick sort on left part connect left part with pivot and apply quick sort on right of pivot

return head
*/
Node *getTail(Node *head)
{
    while(head->next!=NULL)head=head->next;
    return head;
}

/*Node *partition(Node *&head,Node *&tail)//since we are modifying the original head n tail
{
    if(head==NULL || head==tail)return head;

    Node *pivot=tail,*curr=head,*prev=NULL,*newHead=NULL;

    while(curr!=pivot)
    {
        if(curr->data < pivot->data)//all elements less than pivot will be before pivot
        {
            if(newHead==NULL)newHead=curr;//first element i.e less than pivot becomes new head

            //maintain prev so than while putting node ahead we can make connection 
            //of prev node and next node
            prev=curr;
            curr=curr->next;
        }
        else
        {
            //greater elements should be put after pivot

            Node *temp=curr->next; //to handle condition if prev is NULL

            if(prev!=NULL)prev->next=temp; //removing curr

            tail->next = curr;
            curr->next=NULL;
            tail=curr;//updating curr;
            curr=temp;//bring curr back (after previous)
        }
        
    }
    if(newHead==NULL)newHead=pivot;//if all nodes on left of pivot are greater,
                                    //then newHead never gets updated

    head=newHead;//updating head to new head..and tail is already updated

    return pivot;
}

Node * quickSort(Node *head,Node *tail)
{
    if(head==NULL || head==tail)return head;

    Node *pivot=partition(head,tail); //here head n tail get updated

    if(head!=pivot)
    {
        Node *temp=head;
        while(temp->next!=pivot)temp=temp->next;

        temp->next=NULL;

        head=quickSort(head,temp);

        temp=getTail(head);

        temp->next=pivot;
    }

    pivot->next=quickSort(pivot->next,tail);

    return head;
}
*/

Node *partition(Node *&head,Node *&tail)
{
    if(head==NULL || head==tail)return head;

    Node *pivot=tail,*newHead=NULL,*curr=head,*prev=NULL;

    while(curr!=pivot)
    {
        if(curr->data<=pivot->data)
        {
            if(newHead==NULL)newHead=curr;
            prev=curr;
            curr=curr->next;
        }
        else
        {
            Node *temp = curr->next;
            tail->next=curr;
            curr->next=NULL;
            tail=curr;
            if(prev!=NULL)prev->next=temp;
            curr=temp;
        }
        
    }
    head=(newHead==NULL)?pivot:newHead;

    return pivot;
}

Node *quickSort(Node *head,Node *tail)//its is a helper quicksort function since i need to qs from head to tail
{
    if(head==NULL || head==tail)return head;

    Node *pivot=partition(head,tail);

    if(head!=pivot)
    {
        Node *temp=head;

        while(temp->next!=pivot)temp=temp->next;

        temp->next=NULL;
        head=quickSort(head,temp);
        
        temp=getTail(head);
        temp->next=pivot;
    } 

    pivot->next=quickSort(pivot->next,tail);

    return head;   
}

Node *QuickSort(Node *head) // void QuickSort(Node **head_ref)
{
    if(head==NULL && head->next==NULL)return head; // *head_ref =*head_ref
    head=quickSort(head,getTail(head));           //*head_ref = quickSort(*head_ref ,getTail(*head_ref))
    return head;
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
    vector<int> arr = {2, 1, 3, 1, 2, 4, 5, 5};
    Node *head = create(arr);
    print(head);
    head=QuickSort(head);
    print(head);
}