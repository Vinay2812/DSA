#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

struct Info{
    int min;
    int max;
    bool isBst;
};

Info checkBst(Node *root)
{
    if(root==NULL)
        return {INT_MAX,INT_MIN,true};

    if(root->left == NULL && root->right==NULL)
        return {root->data,root->data,true};

    Info l=checkBst(root->left);
    Info r=checkBst(root->right);

    Info curr={-1,-1,false};

    if(l.isBst && r.isBst && root->data > l.max && root->data < r.min)
    {
        curr.isBst=true;
        curr.min= min(root->data,l.min);
        curr.max=max(root->data,r.max);
    }

    return curr;
}
bool checkBst(Node *root,int min ,int max)
{
    if(root==NULL || (root->left==NULL && root->right==NULL))
        return true;
    int val=root->data;

    if(val > min && val < max)
    {
        return checkBst(root->left,min,val) && checkBst(root->right,val,max);
    }

    return false;
}
bool isBST(Node *root)
{
    return checkBst(root).isBst;
}
Node *insertion(Node *root, int val)
{
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insertion(root->left, val);
    else
        root->right = insertion(root->right, val);

    return root;
}

Node *buildBST(vector<int> arr)
{
    Node *root = NULL;
    for (int x : arr)
    {
        root = insertion(root, x);
    }

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

    vector<int> arr = {10, 4, 6, 12, 5, 13, 11};
    Node *root = buildBST(arr);
    //root->right->data=5;
    printInorder(root);
    cout<<"\n"<<isBST(root);
    return 0;
}