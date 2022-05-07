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

void inorder(Node *root,int k,int &count,int &res)
{
    if(root == NULL)
        return;

    inorder(root->left,k,count,res);

    count++;
    if(count == k){
        res=root->data;
        return;
    }

    inorder(root->right,k,count,res);
    
}

void reverseInorder(Node *root,int k,int &count,int &res)
{
    if(root == NULL)
        return;

    reverseInorder(root->right,k,count,res);

    count++;
    if(count == k)
    {
        res = root->data;
        return;
    }

    reverseInorder(root->left,k,count,res);
}

int kthLargest(Node *root,int k)
{
    int count=0,res=-1;
    reverseInorder(root,k,count,res);
    return res;
}

int kthSmallest(Node *root,int k)
{
    int count=0,res=-1;
    inorder(root,k,count,res);
    return res;
}

Node *build(vector<int>arr,int l,int h)
{
    if(l>h)
     return NULL;
    int mid = l +(h-l)/2;
    Node *root= new Node(arr[mid]);
    root->left = build(arr,l,mid-1);
    root->right = build(arr,mid+1,h);
    return root;
}
void printInorder(Node *root)
{
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> arr = {4,5,6,10,11,12,13};
    Node *root = build(arr,0,arr.size()-1);
    printInorder(root);
    int k=3;
    cout <<"\n"<<k<<"th smallest element is : "
        <<kthSmallest(root,k)<<" "<<k<<"th largest element is : "
        <<kthLargest(root,k);

    return 0;
}