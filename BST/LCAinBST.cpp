#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};


Node *LCA(Node *root,int n1,int n2)
{
    if(root == NULL)
        return NULL;

    if(root->data > n1 && root->data > n2)
        return LCA(root->left,n1,n2);

    if(root->data < n1 && root->data < n2)
        return LCA(root->right,n1,n2);

    return root;
}



// Node *insertion(Node *root, int val)
// {
//     if (root == NULL)
//         return new Node(val);

//     if (val < root->data)
//         root->left = insertion(root->left, val);
//     else
//         root->right = insertion(root->right, val);

//     return root;
// }

// Node *buildBST(vector<int> arr)
// {
//     Node *root = NULL;
//     for (int x : arr)
//     {
//         root = insertion(root, x);
//     }

//     return root;
// }

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
    if (root == NULL)
        return;

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
    //root->right->data=5;
    printInorder(root);
    Node *lca = LCA(root,6,4);
     cout << "\n"<<((lca!=NULL)?lca->data:-1);
    return 0;
}
