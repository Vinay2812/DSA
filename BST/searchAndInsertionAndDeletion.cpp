#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left,*right;
    Node(int val)
    {
        data=val;
        left=NULL;right=NULL;
    }
};
Node * findMax(Node *root)
{
    while(root!=NULL && root->right!=NULL)
        root=root->right;

    return root;
}
Node *deletion(Node *root,int val)
{
    if(root==NULL)
        return NULL;

    if(root->data == val)
    {
        //case 1: No children
        if(root->left == NULL && root->right == NULL){
            delete(root);
            return NULL;
        }
        //case 2 : 1 children

        if(root->left==NULL)
        {
           return root->right;
        }
        else if(root->right==NULL)
        {
            return root->left;
        }
        else
        {
            //case 3:2 children
            Node *node = findMax(root->left);
            swap(root->data , node->data);
            root->left=deletion(root->left,val);
        }
    }
    if(val < root->data )
        root->left=deletion(root->left,val);
    else
        root->right=deletion(root->right,val);

    return root;
}

bool search(Node *root,int val)
{
    if(root==NULL)
        return false;
    
    if(root->data == val)
        return true;

    if(val < root->data)
        return search(root->left,val);

    return search(root->right,val);
}

Node *insertion(Node *root,int val)
{
    if(root==NULL)
        return new Node(val);

    if(val < root->data)
        root->left=insertion(root->left,val);
    else
        root->right=insertion(root->right,val);

    return root;
}

Node *buildBST(vector<int>arr)
{
    Node *root=NULL;
    for(int x : arr)
    {
        root=insertion(root,x);
    }

    return root;
}

void printInorder(Node *root)
{
    if(root==NULL)
        return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int>arr={10,4,6,12,5,13,11};
    Node *root=buildBST(arr);
    printInorder(root);
    cout<<"\n";
    //cout<<search(root,21);
    deletion(root,10);
    printInorder(root);
    cout << "\n";
    return 0;
}