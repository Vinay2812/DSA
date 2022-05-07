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

void fillSet(Node *root,unordered_set<int>&s)
{
    if(root == NULL)
        return;

    fillSet(root->left,s);
    s.insert(root->data);
    fillSet(root->right,s);
}

void getCount(Node *root,unordered_set<int>&s,int x,int &count)
{
    if(root == NULL)
        return;

    if(s.find(x-root->data)!=s.end())
        count++;

    getCount(root->left,s,x,count);
    getCount(root->right,s,x,count);
}

int countPairs(Node *r1,Node *r2,int x)
{
    if(r1==NULL || r2==NULL)
        return 0;

    int count=0;

    unordered_set<int>s;
    fillSet(r1,s);
    getCount(r2,s,x,count);
    
    return count;
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
    vector<int> arr1 = {2,3,4,5,6,7,8};
    vector<int> arr2 = {3,6,8,10,11,15,18};
    int x = 16; // 3
    Node *root1 = build(arr1,0,arr1.size()-1);
    Node *root2 = build(arr2, 0, arr2.size() - 1);
    printInorder(root1);
    cout <<"\n";
    printInorder(root2);

    cout<<"\nThe count of pairs with sum "
            <<x<<" is "<<countPairs(root1,root2,x);
    return 0;
}