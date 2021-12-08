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
        while (ct--)
        {
            Node *temp = q.front();
            q.pop();
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
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
Node *getMinimumKey(Node *curr)
{
    while (curr->left != nullptr)
    {
        curr = curr->left;
    }
    return curr;
}
void searchKey(Node *&curr, int key, Node *&parent)
{
    while (curr != nullptr && curr->data != key)
    {
        parent = curr;
        if (key < curr->data)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
}
void deleteNode(Node *&root, int key)
{
    Node *parent = nullptr;
    Node *curr = root;
    searchKey(curr, key, parent);
    if (curr == nullptr)
    {
        return;
    }
    if (curr->left == nullptr && curr->right == nullptr)
    {
        if (curr != root)
        {
            if (parent->left == curr)
            {
                parent->left = nullptr;
            }
            else
            {
                parent->right = nullptr;
            }
        }
        else
        {
            root = nullptr;
        }
        free(curr);
    }
    else if (curr->left && curr->right)
    {
        Node *successor = getMinimumKey(curr->right);
        int val = successor->data;
        deleteNode(root, successor->data);
        curr->data = val;
    }
    else
    {
        Node *child = (curr->left) ? curr->left : curr->right;
        if (curr != root)
        {
            if (curr == parent->left)
            {
                parent->left = child;
            }
            else
            {
                parent->right = child;
            }
        }
        else
        {
            root = child;
        }
        free(curr);
    }
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
void deleteleaf(Node*tree){
    queue<Node*>q;
    q.push(tree);
    while(!q.empty())
    {
        Node*temp = q.front();
        q.pop();
        if(!temp->left->left)
        {
            temp->left = NULL;
        }
        if(!temp->right->left)
        {
            temp->right = NULL;
        }
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
    }
}
void MorrisTraversal(struct Node* root)
{
    struct Node *current, *pre;
  
    if (root == NULL)
        return;
  
    current = root;
    while (current != NULL) {
  
        if (current->left == NULL) {
            printf("%d ", current->data);
            current = current->right;
        }
        else {
            pre = current->left;
            while (pre->right != NULL
                   && pre->right != current)
                pre = pre->right;

            if (pre->right == NULL) {
                pre->right = current;
                current = current->left;
            }
  
            else {
                pre->right = NULL;
                printf("%d ", current->data);
                current = current->right;
            } 
        } 
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
    deleteleaf(tree);
    cout<<endl;
    postorder(tree);
}
