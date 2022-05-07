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
map<int,int>sum;
map<int, vector<int>> mp;
void diagonal(Node *root, int slopeLevel)
{
    if (root == NULL)
        return;
    sum[slopeLevel]+=root->data;
    mp[slopeLevel].push_back(root->data);
    diagonal(root->left, slopeLevel + 1);
    diagonal(root->right, slopeLevel);
}
void diagonalTraversal(Node *root)
{
    //recursive using maps->

    cout << "Using maps (Recursion) -> ";
    mp.clear();
    sum.clear();
    if (root == NULL) return;
    diagonal(root, 0);
    for (auto p : mp)
    {
        for (int x : p.second)
        {
            cout << x << " ";
        }
    }
    
    cout<<"Sum of each diagonal is :"<<endl;
    for(pair<int,int>p : sum){
        cout<<"\n\nSlope Level "<<p.first<<" and its sum is :"<<p.second<<endl;
    }
    cout << "\n\nUsing queue (iterative) -> ";

    queue<Node *> q;
    if (root == NULL)
        return;

    q.push(root);
    while (!q.empty())
    {
        root = q.front();
        q.pop();

        while (root != NULL)
        {
            if (root->left != NULL)
                q.push(root->left);

            cout << root->data << " ";
            root = root->right;
        }
    }
}
int main()
{
    struct Node *root, *target;
    //level 0
    root = new Node(1);
    //level 1
    root->left = new Node(2);
    target = root->right = new Node(3);
    //level 2
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    //level 3
    root->right->right->left = new Node(8);
    root->right->left->left = new Node(9);

    /*
            1
           / \
          2   3
         /\   / \
        4  5 6   7
            /  /
           9   8 
    */
    diagonalTraversal(root);
    return 0;
}