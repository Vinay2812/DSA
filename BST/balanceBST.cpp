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
void inorder(Node *root,vector<int> &arr)
{
    if(root == NULL)
        return;
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

Node *buildTree(vector<int>arr ,int l,int h)
{
    if(l>h)
        return NULL;

    int mid = l +(h-l)/2;
    Node *root =new Node(arr[mid]);
    root->left = buildTree(arr,l,mid-1);
    root->right = buildTree(arr,mid+1,h);

    return root;
}
Node *balanceBST(Node *root)
{
    vector<int>arr;
    inorder(root,arr);

    return buildTree(arr,0,arr.size()-1);
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
    vector<int> arr = {4,5,6,10,11,12,13};
    Node *root = build(arr,0,arr.size()-1);
    printInorder(root);
    cout <<"\n";
    printInorder(balanceBST(root));
    return 0;
}