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
Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *newHead = reverse(head->next);

    head->next->next = head;
    head->next = NULL;

    return newHead;
}

bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
        return true;

    stack<int> st;

    Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        st.push(slow->data);
        slow = slow->next;

        fast = fast->next->next;
    } 
    
    if(fast!=NULL)
    slow=slow->next;

    while (slow != NULL)
    {
        if (slow->data != st.top())
            return false;

        st.pop();
        slow = slow->next;
    }

    return true;

    /*if(head==NULL || head->next==NULL)return true;

    Node *slow=head,*fast=head->next;

    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    fast=reverse(slow->next);
    slow->next=NULL;

    Node *t1=head,*t2=fast;

    while(t1!=NULL && t2!=NULL)
    {
        if(t1->data!=t2->data)
        {
            slow->next = reverse(fast);
            return false;
        }
        t1=t1->next;
        t2=t2->next;
    }

    slow->next=reverse(fast);

    return true;
    */
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
    vector<int> arr = {1, 2, 3, 3,2, 2, 1};
    Node *head = create(arr);

    print(head);
    cout << isPalindrome(head) << endl;
    print(head);
}