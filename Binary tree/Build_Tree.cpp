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
int search(int inorder[],int start,int curr,int end)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==curr)
            return i;
    }
    return -1;
}
Node * build_tree_using_inorderAndpreorder(int preorder[],int inorder[],int start,int end)
{
    if(start>end)
        return NULL;

    static int idx_preorder=0;

    int curr=preorder[idx_preorder];
    idx_preorder++;

    Node *root=new Node(curr);
    if(start==end)
        return root;

    int pos=search(inorder,start,curr,end);
    root->left=build_tree_using_inorderAndpreorder(preorder,inorder,start,pos-1);
    root->right=build_tree_using_inorderAndpreorder(preorder,inorder,pos+1,end);

    return root;
}

Node * build_tree_using_inorder_and_postorder(int *postorder ,int *inorder,int start,int end)
{
    if(start>end)
        return NULL;

    static int idx_postorder=end;

    int curr = postorder[idx_postorder];
    idx_postorder--;

    Node *root=new Node(curr);
    if(start==end)
        return root;
    
    int pos=search(inorder,start,curr,end);

    root->right=build_tree_using_inorder_and_postorder(postorder,inorder,pos+1,end);
    root->left=build_tree_using_inorder_and_postorder(postorder,inorder,start,pos-1);

    return root;
}

void inOrderPrint(Node* root)
{
    if(root==NULL)
        return;
    
    inOrderPrint(root->left);
    cout<<root->data<<" ";
    inOrderPrint(root->right);
}

int main()
{
    int preorder[]={1,2,4,3,5}; // R l r

    int postorder[]={4,2,5,3,1};//l r R   idx=n-1; 
    int inorder[]={4,2,1,5,3};//   l R r
   /*
           1
      2      3
    4      5
   */




    cout<<"Using inorder and preorder : ";
    Node * root=build_tree_using_inorderAndpreorder(preorder,inorder,0,4);
    inOrderPrint(root);

    cout<<"\n\nUsing inorder and postorder : ";
    root=build_tree_using_inorder_and_postorder(postorder,inorder,0,4);
    inOrderPrint(root);

    return 0;
}