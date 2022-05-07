// { Driver Code Starts
#include <bits/stdc++.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node *merge(Node *h1, Node *h2)
{
    if (h1 == NULL)
        return h2;

    if (h2 == NULL)
        return h1;

    Node *s = new Node(-1);
    Node *t = s;

    while (h1 != NULL && h2 != NULL)
    {
        if (h1->data < h2->data)
        {
            t->bottom = h1;
            h1 = h1->bottom;
        }
        else
        {
            t->bottom = h2;
            h2 = h2->bottom;
        }
        t = t->bottom;
    }

    if (h1 != NULL)
    {
        t->bottom = h1;
    }
    else
    {
        t->bottom = h2;
    }
    s->bottom->next = NULL;
    return s->bottom;
}

Node *flatten(Node *head)
{
    // if(head==NULL || head->next==NULL)
    //     return head;

    // head->next=flatten(head->next);
    // head=merge(head,head->next);
    // return head;

    if (head == NULL || head->next == NULL)
        return head;

    Node *prev = head, *next;
    head = head->next;

    while (head != NULL)
    {
        next=head->next;
        prev=merge(prev,head);
        head=next;
        prev->next=head;
    }

    return prev;
}

int main(void)
{

    int n, m, flag = 1, flag1 = 1;
    struct Node *temp = NULL;
    struct Node *head = NULL;
    struct Node *pre = NULL;
    struct Node *tempB = NULL;
    struct Node *preB = NULL;
    cin >> n;
    int work[n];
    for (int i = 0; i < n; i++)
        cin >> work[i];
    for (int i = 0; i < n; i++)
    {
        m = work[i];
        --m;
        int data;
        scanf("%d", &data);
        temp = new Node(data);
        temp->next = NULL;
        temp->bottom = NULL;

        if (flag)
        {
            head = temp;
            pre = temp;
            flag = 0;
            flag1 = 1;
        }
        else
        {
            pre->next = temp;
            pre = temp;
            flag1 = 1;
        }
        for (int j = 0; j < m; j++)
        {

            int temp_data;
            scanf("%d", &temp_data);
            tempB = new Node(temp_data);

            if (flag1)
            {
                temp->bottom = tempB;
                preB = tempB;
                flag1 = 0;
            }
            else
            {
                preB->bottom = tempB;
                preB = tempB;
            }
        }
    }
    Node *fun = head;
    Node *fun2 = head;

    Node *root = flatten(head);
    printList(root);
    cout << endl;

    return 0;
}
