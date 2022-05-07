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

Node *LCA(Node *root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }

    if(root->data==n1 || root->data==n2){
        return root;
    }

    Node *LeftLCA=LCA(root->left,n1,n2);
    Node *rightLCA=LCA(root->right,n1,n2);

    if(LeftLCA!=NULL && rightLCA!=NULL){
        return root;
    }

    if(LeftLCA!=NULL){
        return LeftLCA;
    }

    return rightLCA;
}

int distance(Node *root,int num,int level){
    if(root==NULL){
        return -1;
    }

    if(root->data==num){
        return level;
    }

    int left=distance(root->left,num,level+1);
    if(left!=-1){
        return left;
    }
    int right=distance(root->right,num,level+1);

    return right;
}

int distanceBetweenTwoNodes(Node *root,int n1,int n2){
    Node *rootLCA=LCA(root,n1,n2);
    int left=distance(rootLCA,n1,0);
    int right=distance(rootLCA,n2,0);

    return left+right;
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
    root->left->right->left = new Node(8);
    //level 4
    root->left->right->left->right = new Node(9);

    cout<<"Distance between two nodes is "<<distanceBetweenTwoNodes(root,3,9);
    return 0;
}