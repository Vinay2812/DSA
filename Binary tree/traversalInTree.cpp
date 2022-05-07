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

void preorderUsingRecursion(Node *root){
    if(root==NULL)
        return;

    cout<<root->data<<" ";
    preorderUsingRecursion(root->left);
    preorderUsingRecursion(root->right);
}

void preorderWithoutRecursion(Node *root){
    stack<Node *>st;
    while(1)
    {
        while(root!=NULL)
        {
            cout<<root->data<<" ";
            st.push(root);
            root=root->left;
        }
        
        if(st.empty())
            break;

        root=st.top();
        st.pop();
        root=root->right; 
    }
}

void inorderUsingRecursion(Node *root){
    if(root==NULL)
        return;
    inorderUsingRecursion(root->left);
    cout<<root->data<<" ";
    inorderUsingRecursion(root->right);
}

void inorderWithoutRecursion(Node *root)
{
    stack<Node *>st;
    while(1)
    {
        while(root!=NULL)
        {
            st.push(root);
            root=root->left;
        }
        if(st.empty())
            break;

        root=st.top();
        st.pop();
        cout<<root->data<<" ";
        root=root->right;
    }
}

void postorderUsingRecursion(Node *root){
    if(root==NULL)
    return ;
    postorderUsingRecursion(root->left);
    postorderUsingRecursion(root->right);
    cout<<root->data<<" ";
}

void postorderWithoutRecursion(Node *root){
    stack<Node *>st;
    Node *prevNode=NULL;
    while(1)
    {
        while(root!=NULL)
        {
            st.push(root);
            root=root->left;
        }

        while(root==NULL && !st.empty())
        {
            root=st.top();
            if(root->right==NULL || root->right==prevNode)
            {
                st.pop();
                cout<<root->data<<" ";
                prevNode=root;
                root=NULL;
            }
            else
            {
                root=root->right;
            }
            
        }
        if(st.empty())
            break;
    }
    
}

void levelorder(Node *root){
    if(root==NULL)
        return;
    
    queue<Node*>q;
    q.push(root);
    int n;

    while(!q.empty())
    {
        n=q.size();//gives no. of nodes at each level
        for(int i=1;i<=n;i++)
        {
            Node *node=q.front();
            q.pop();

            cout<<node->data<<" ";
            if(node->left!=NULL)
                q.push(node->left);
            if(node->right!=NULL)
                q.push(node->right);
        }

    }
}

void zigzagTraversal(Node *root){
    if(root==NULL)return ;

    stack<int>st;
    queue<Node*>q;
    q.push(root);
    int n,level=0;

    while(!q.empty())
    {
        n=q.size();
        for(int i=1;i<=n;i++)
        {
            Node *node=q.front();
            q.pop();

            if(level%2==1){
                st.push(node->data);
            }
            else{
                cout<<node->data<<" ";
            }
            if(node->left!=NULL)
                q.push(node->left);
            if(node->right!=NULL)
                q.push(node->right);
        }

        level++;
        while(!st.empty())
        {
            cout<<st.top()<<" ";
            st.pop();
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

    cout<<"\nPreOrder Traversal -- "<<endl;
    cout<<"With Recursion : ";
    preorderUsingRecursion(root);
    cout<<"\nwithout recursion : ";
    preorderWithoutRecursion(root);

    cout<<"\n\nInOrder Traversal -- "<<endl;
    cout<<"With Recursion : ";
    inorderUsingRecursion(root);
    cout<<"\nwithout recursion : ";
    inorderWithoutRecursion(root);

    cout<<"\n\npostOrder Traversal -- "<<endl;
    cout<<"With Recursion : ";
    postorderUsingRecursion(root);
    cout<<"\nwithout recursion : ";
    postorderWithoutRecursion(root);

    cout<<"\n\nLevel Order Traversal -- ";
    levelorder(root);

    cout<<"\n\nZigzag Traversal -- ";
    zigzagTraversal(root);
    return 0;
}