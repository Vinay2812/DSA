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
void countNodes(Node *root,int &count)
{
    if(root == NULL)
        return;

    count++;
    countNodes(root->left,count);
    countNodes(root->right,count);
}

void setNodes(Node *root,Node *&f,Node *&s,int k,int &count)
{
    if(root == NULL)
        return;
    
    setNodes(root->left,f,s,k,count);
    count++;

    if(count == k)
        f = root;
    else if(count == k+1){
        s = root;
        return;
    }
    
    setNodes(root->right,f,s,k,count);
}

double medianOfBST(Node *root)
{
    if(root == NULL)
        return 0.0;

    int count=0;
    countNodes(root,count);
    bool isEven = (count%2)?0:1;
    int k = count/2;
    count=0;
    Node *f=NULL,*s=NULL;
    setNodes(root,f,s,k,count);

    if(isEven)
        return (f->data + s->data )/2.0;
    else 
        return s->data;

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
    vector<int> arr = {4,5,6,11,12,13};
    Node *root = build(arr,0,arr.size()-1);
    printInorder(root);
    cout << "\nMedian if bst is : "<<medianOfBST(root);
    return 0;
}