#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left,*right,*next;
    Node(int val)
    {
        data=val;
        next=NULL;left=NULL;right=NULL;
    }
};
void populate(Node *root,Node *&prev)
{
    if(root == NULL)
        return;

    populate(root->left , prev);

    if(prev)
        prev->next = root;
    
    prev = root;

    populate(root->right,prev);
}
Node *inorderSuccesor(Node *root)
{
    Node *prev = NULL;
    populate(root,prev);
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

void printNext(Node *root)
{
    if(root == NULL)
        return;

    printNext(root->left);
    int x = (root->next)?root->next->data:-1;
    cout<<root->data<<"->"<<x<<" ";
    printNext(root->right);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> arr = {4,5,6,10,11,12,13};
    Node *root = build(arr,0,arr.size()-1);
    printInorder(root);
    cout <<"\n";
    root = inorderSuccesor(root);
    printNext(root);
    return 0;
}