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

pair<int,int> diameterOfBinaryTree(Node* root)
{
    //in left of pair we will store height of each node
    //in right of pair we will store diameter of each node

    if(root==NULL)
        return {0,0};

    pair<int,int>left=diameterOfBinaryTree(root->left);
    pair<int,int>right=diameterOfBinaryTree(root->right);

    //height of tree at each node 
    //        = max(left sub tree of root"s height ,right sub tree of root's heght)+1 i.e
    int height=max(left.first,right.first)+1;

    //diameter at each node = 
    //        = max((leftheight + rightHeight +1),max(left diameter,right diameter))
    int diameter=max((left.first + right.first +1),max(left.second,right.second));
    return {height,diameter};
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

   cout<<"diameter of binary tree is : "<<diameterOfBinaryTree(root).second-1;

    return 0;
}