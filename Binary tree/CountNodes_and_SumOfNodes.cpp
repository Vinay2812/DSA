#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node * left;
    struct Node * right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

int countNodes(Node *root)
{
    if(root==NULL)
        return 0;
    
    return (countNodes(root->left) + countNodes(root->right)+1);
}

int sumOfNodes(Node *root)
{
    if(root==NULL)
        return 0;

    int lsum=sumOfNodes(root->left);
    int rsum=sumOfNodes(root->right);
    
    return (lsum+rsum+root->data);
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

   cout<<"Count of nodes in binary tree is : "<<countNodes(root)<<endl;
   cout<<"Sum of nodes in binary tree is : "<<sumOfNodes(root)<<endl;

    return 0;
}