#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
int height_it(Node *node)
{
    int height = 0;
    queue<Node *> q;
    q.push(node);
    while (!q.empty())
    {
        height++;
        int ct = q.size();
        while(ct--)
        {
            Node*temp = q.front();
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return height;
}
int height_rec(Node *node)
{
    int left = 0;
    int right = 0;
    if (node->left)
        left = height_rec(node->left);
    if (node->right)
        right = height_rec(node->right);
    return max(left, right) + 1;
}
Node *insert(Node *node, int key)
{
    if (node == NULL)
    {
        node = new Node(key);
    }
    else if (key < node->data)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->data)
    {
        node->right = insert(node->right, key);
    }
    return node;
}
void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
void postorder(Node *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}
void preorder(Node *root)
{
    if (root)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    Node *tree = NULL;
    int arr[] = {10, 15, 13, 17, 4, 7, 19, 1, 6};
    for (int i = 0; i < sizeof(arr) / 4; i++)
    {
        tree = insert(tree, arr[i]);
    }
    postorder(tree);
}
