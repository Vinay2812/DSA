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

//directly find the nodes at distance k of target node
int sum;
void findSum(Node *root,int level,int k)
{
    if(root==NULL)return;

    if(level==k){
        sum+=root->data;
        return;
    }

    findSum(root->left,level+1,k);
    findSum(root->right,level+1,k);
}

int sumAtLevelK(Node*root,int k)
{
    if(root==NULL)return 0;
    sum=0;
    findSum(root,0,k);

    return sum;
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

    cout<<sumAtLevelK(root,2);
    return 0;
}