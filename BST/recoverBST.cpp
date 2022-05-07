#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left,*right;
    Node(int val)
    {
        data=val;
        left=NULL;right=NULL;
    }
};
void update(Node *curr, Node *&prev, Node *&l, Node *&h)
{
    if (curr == NULL)
        return;
    update(curr->left, prev, l, h);

    if (prev && prev->data > curr->data)
    {
        if (l == NULL)
        {
            l = prev;
            h = curr;
        }
        else
            h = curr;
    }
    prev = curr;
    update(curr->right, prev, l, h);
}

void update(Node *curr,Node *&prev,Node *&l,Node *&m,Node *&h)
{
    if(curr == NULL)
        return;
    update(curr->left, prev, l, m, h);

    if(prev && prev->data > curr->data)
    {
        if(l == NULL)
        {
            l=prev;
            m=curr;
        }
        else
            h=curr;
    }
    prev=curr;
    update(curr->right,prev, l, m, h);
}

Node *recoverBST(Node *root)
{
    Node *prev=NULL,*l=NULL,*m=NULL,*h=NULL;
    // update(root,prev,l,m,h);
    // /*
    // if(h!=NULL)
    //     swap(l,h);
    // else
    //     swap(l,m);
    // */
    // if(h!=NULL)
    //     m=h;

    // swap(l->data,m->data);
    update(root,prev,l,h);
    swap(l->data,h->data);

    return root;
}

Node *build(vector<int>arr,int l,int h)
{
    if(l>h)
     return NULL;
    int mid = l +(h-l)/2;
    Node *root= new Node(arr[mid]);
    root->left = build(arr,l,mid-1);
    root->right = build(arr,mid+1,h);
    return root;
}
void printInorder(Node *root)
{
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> arr = {4,5,6,10,11,12,13};
    Node *root = build(arr,0,arr.size()-1);
    // swap(root->left->right->data ,root->right->data);// nodes are not adjacent
    swap(root->data , root->left->right->data);
    printInorder(root);
    cout <<"\n";
    printInorder(recoverBST(root));
    return 0;
}