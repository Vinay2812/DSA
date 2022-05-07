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
int idx;

Node *build(int preorder[],int min,int max,int n)
{
    if(idx >= n)
        return NULL;

    int val=preorder[idx];
    Node *root=NULL;

    if(val > min && val < max)
    {
        root=new Node(val);
        idx++;

        if(idx < n)
            root->left=build(preorder,min,val,n);

        if(idx < n)
            root->right=build(preorder,val,max,n);
    }

    return root;
}

Node *buildBST(int preorder[], int n)
{
    idx=0;
    Node *root=build(preorder,INT_MIN,INT_MAX,n);
    return root;
}

void printInorder(Node *root)
{
    if (root == NULL)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int preorder[]={10,5,4,7,6,9,12,13};
    Node *root=buildBST(preorder,8);

    printInorder(root);
    return 0;
}