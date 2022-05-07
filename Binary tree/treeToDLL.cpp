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
Node *head=NULL,*tail=NULL;

void convertToDLL(Node *root){
    if(root==NULL)return;
    
    convertToDLL(root->left);
    if(head==NULL){
        head=root;
    }
    else{
        tail->right=root;
        root->left=tail;
    }
    tail=root;
    convertToDLL(root->right);
}

void printPreorder(Node *root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printList(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->right;
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

   head=NULL,tail=NULL;
    cout<<"Preorder of Tree : ";
    printPreorder(root);
    
    convertToDLL(root);
    cout<<"\nAfter converting to DLL in inorder sequence: "<<endl;
    printList(head);

    return 0;
}