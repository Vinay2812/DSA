#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
int calculateSum(Node *root)
{
    if(root==NULL)return 0;

    int ls=calculateSum(root->left);
    int rs=calculateSum(root->right);

    int val=root->data+ls+rs;
    root->data=ls+rs;

    return val;
}
void sumReplacement(Node *root)
{
    calculateSum(root);
}

void inOrder(Node *root)
{
    if(root==NULL)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main()
{
    struct Node *root;
    //level 0
    root = new Node(1);
    //level 1
    root->left = new Node(2);
    root->right = new Node(3);
    //level 2
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    inOrder(root);
    cout<<"\nAfter sum Replacement"<<endl;
    sumReplacement(root);
    inOrder(root);

    return 0;
}