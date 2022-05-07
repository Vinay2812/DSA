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

void LeftView(Node *root)
{
    if(root==NULL)
        return;
    queue<Node*>q;
    q.push(root);
    int nodes_at_each_level;

    while(!q.empty())
    {
        nodes_at_each_level=q.size();
        for(int i=1;i<=nodes_at_each_level;i++)
        {
            Node *node=q.front();
            q.pop();

            if(i==1){
                cout<<node->data<<" ";
            }

            if(node->left!=NULL)
                q.push(node->left);
            if(node->right!=NULL)
                q.push(node->right);        
        }
    }
}

void rightView(Node *root)
{
    if(root==NULL)
        return;
    queue<Node *>q;
    q.push(root);
    int nodes_at_each_level;

    while(!q.empty())
    {
        nodes_at_each_level=q.size();
        for(int i=1;i<=nodes_at_each_level;i++)
        {
            Node *node=q.front();
            q.pop();

            if(i==nodes_at_each_level){
                cout<<node->data<<" ";
            }

            if(node->left!=NULL)
                q.push(node->left);
            if(node->right!=NULL)
                q.push(node->right);
        }
    }
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

   cout<<"Left View of Binary tree is : ";
   LeftView(root);
   cout<<"\nRight View of Binary tree is : ";
   rightView(root);

    return 0;
}