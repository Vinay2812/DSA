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

int maxSum;
int findSum(Node*root)
{
    if(root==NULL)
        return 0;

    int ls=findSum(root->left);
    int rs=findSum(root->right);

    maxSum = max(maxSum,(ls + rs + root->data));

    return max((max(ls,rs)+root->data),0);
}

int findMaxSum(Node *root)
{
    maxSum=INT_MIN;
    findSum(root);
    return maxSum;

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
    root->left->left = new Node(-4);
    root->left->right = new Node(5);
    root->right->left = new Node(-6);
    root->right->right = new Node(-7);
    //level 3
    root->right->right->left = new Node(-8);
    root->right->left->left=new Node(-9);

    /*
              1
           /    \
          2      3
          /\    /\
       -4  5 -6   -7
              /  /
            -9   -8 
    */

    cout<<findMaxSum(root);
    return 0;
}