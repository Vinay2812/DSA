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

int check(Node *root){
    if(root==NULL){
        return 0;
    }

    int lh=check(root->left);
    int rh=check(root->right);

    if(lh==-1 || rh==-1)
        return -1;

    if(abs(lh-rh)>1)
        return -1;
    
    return max(lh,rh)+1;
}
bool isBalanced(Node * root){
    if(root==NULL)return true;

    int ans=check(root);

    return (ans==-1)?false:true;
}

int main()
{
    struct Node *root,*target;
    //level 0
    root = new Node(1);
    //level 1
    root->left = new Node(2);
    target=root->right = new Node(3);
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

    cout<<isBalanced(root);
    return 0;
}