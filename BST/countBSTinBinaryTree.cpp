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

struct Info{
    int min;
    int max;
    bool isBst;
    int size;
    int ans;
};


Info getAns(Node *root)
{
    if(root==NULL)
        return {INT_MAX,INT_MIN,true,0,0};
    
    if(root->left == NULL && root->right == NULL)
        return {root->data,root->data ,true,1,1};

    Info l=getAns(root->left);
    Info r=getAns(root->right);

    Info curr={-1,-1,false,-1,max(l.ans,r.ans)};

    if(l.isBst && r.isBst && root->data > l.max && root->data < r.min)
    {
        curr.isBst=true;
        curr.min=min(root->data,l.min);
        curr.max=max(root->data,r.max);
        curr.size=l.size + r.size + 1;
        curr.ans=curr.size;
    }

    return curr;
}
int sizeOfBst(Node *root)
{
    return getAns(root).ans;
}

int main()
{
    struct Node *root;
    //level 0
    root = new Node(1);
    //level 1
    root->left = new Node(4);
    root->right = new Node(9);
    //level 2
    root->left->left = new Node(2);
    root->left->right = new Node(5);
    root->right->left = new Node(3);
    root->right->right = new Node(11);
    //level 3
    root->right->right->left = new Node(10);
    root->right->left->right = new Node(6);

    /*
            1
           /\
          4  9
          /\  /\
        2  5 3   11
             \  /
             6  10 
    */
    
    cout<<"Largest BST:"<<sizeOfBst(root);
    return 0;
}