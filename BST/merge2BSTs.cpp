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



vector<int> merge2BSTs(Node *root1, Node *root2)
{
    vector<int> ans;
    stack<Node *> st1, st2;

    while (1)
    {
        while (root1 != NULL)
        {
            st1.push(root1);
            root1 = root1->left;
        }

        while (root2 != NULL)
        {
            st2.push(root2);
            root2 = root2->left;
        }

        /*
        while(root1!=NULL || root2!=NULL)
        {
            if(root1){
                st1.push(root1);
                root1 = root1->left;
            }

            if(root2){
                st2.push(root2);
                root2 = root2->left;
            }
        }
        */

        if (st1.empty() && st2.empty())
            break;

        int x = (st1.empty())?INT_MAX:st1.top()->data;
        int y = (st2.empty())?INT_MAX:st2.top()->data;

        if(x < y){
            root1 = st1.top();
            st1.pop();
            ans.push_back(root1->data);
            root1 = root1->right;
        }
        else{
            root2 = st2.top();
            st2.pop();
            ans.push_back(root2->data);
            root2 = root2->right;
        }
/*
        if (!st1.empty() && !st2.empty())
        {
            if (st1.top()->data < st2.top()->data)
            {
                root1 = st1.top();
                st1.pop();
                ans.push_back(root1->data);
                root1 = root1->right;
            }
            else
            {
                root2 = st2.top();
                st2.pop();
                ans.push_back(root2->data);
                root2 = root2->right;
            }
        }
        else if (!st1.empty())
        {
            root1 = st1.top();
            st1.pop();
            ans.push_back(root1->data);
            root1 = root1->right;
        }
        else
        {
            root2 = st2.top();
            st2.pop();
            ans.push_back(root2->data);
            root2 = root2->right;
        }
*/
    }
    return ans;
}

Node *insertion(Node *root, int val)
{
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insertion(root->left, val);
    else
        root->right = insertion(root->right, val);

    return root;
}

Node *buildBST(vector<int> arr)
{
    Node *root = NULL;
    for (int x : arr)
    {
        root = insertion(root, x);
    }

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

    vector<int> arr1 = {10, 4, 6, 12, 5, 13, 11};
    vector<int> arr2 = {12, 2, 4, 7 ,10, 9};
    Node *root1 = buildBST(arr1);
    Node *root2 = buildBST(arr2);
    //root->right->data=5;
    printInorder(root1);
    cout << "\n";
    printInorder(root2);
    cout << "\n\nAfter merging 2 BST's :\n";

    vector<int> res = merge2BSTs(root1, root2);
    for (int x : res)
        cout << x << " ";

    return 0;
}