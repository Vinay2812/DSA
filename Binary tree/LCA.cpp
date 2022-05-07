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


Node * lowestCommonAncestor(Node *root,int n1,int n2)
{
    if(root==NULL)
        return NULL;

    if(root->data==n1 || root->data==n2){
        return root;
    }
    
    Node *leftLCA=lowestCommonAncestor(root->left,n1,n2);
    Node *rightLCA=lowestCommonAncestor(root->right,n1,n2);

    if(leftLCA!=NULL && rightLCA!=NULL)
    {
        return root;
    }
    if(leftLCA==NULL && rightLCA==NULL)
    {  
        return NULL;
    }

    if(leftLCA!=NULL)
    {
        return leftLCA;
    }

    return rightLCA;
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
   Node *ans=lowestCommonAncestor(root,8,4);
   cout<<"LCA : "<<ans->data<<endl;

    return 0;
}