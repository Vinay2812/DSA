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
void leftBoundary(Node *root){
    if(root==NULL || (root->left==NULL && root->right==NULL))
        return;
    
    cout<<root->data<<" ";
    if(root->left!=NULL)
    leftBoundary(root->left);
    else
    leftBoundary(root->right);
    
}

void leafNodes(Node *root){
    if(root==NULL)return;

    if(root->left==NULL && root->right==NULL)
        cout<<root->data<<" ";
    leafNodes(root->left);
    leafNodes(root->right);
}

void rightBoundary(Node *root){
    if(root==NULL ||(root->left==NULL && root->right==NULL))
    return;

    if(root->right!=NULL)
        rightBoundary(root->right);
    else    
        rightBoundary(root->left);
    cout<<root->data<<" ";
}

void boundary(Node *root){
    if(root==NULL)return;

    cout<<root->data<<" ";
    if(root->left==NULL && root->right==NULL)return;
    leftBoundary(root->left);
    leafNodes(root);
    rightBoundary(root->right);

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
    //level 3
    root->right->right->left = new Node(8);
    root->right->left->left=new Node(9);

    /*
             1
            /\
           2  3
          /\  /\
        4  5 6   7
            /  /
           9   8 
    */
   cout<<"Boundary of tree is : ";
   boundary(root);

    return 0;
}
