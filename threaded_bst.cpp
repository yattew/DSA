#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    Node *left;
    Node *right;
    bool l_thread;
    bool r_thread;
    Node(int d)
    {
        key = d;
        left = NULL;
        right = NULL;
        l_thread = false;
        r_thread = false;
    }
};
struct TBST
{
    Node *root;
    TBST() { root = NULL; }
    void insert(int key)
    {
        if (root == NULL)
        {
            root = new Node(key);
            return;
        }
        Node *parent = NULL;
        Node *curr = root;
        while (curr != NULL)
        {
            parent = curr;
            if (key < curr->key)
            {
                if (!(curr->l_thread))
                    curr = curr->left;
                else
                    break;
            }
            else
            {
                if (!(curr->r_thread))
                    curr = curr->right;
                else
                    break;
            }
        }
        Node *n = new Node(key);
        n->l_thread = true;
        n->r_thread = true;
        if (key < parent->key)
        {
            n->left = parent->left;
            n->right = parent;
            parent->left = n;
            parent->l_thread = false;
            if (n->left)
                n->l_thread = true;
            if (n->right)
                n->r_thread = true;
        }
        else
        {
            n->right = parent->right;
            n->left = parent;
            parent->right = n;
            parent->r_thread = false;
            if (n->left)
                n->l_thread = true;
            if (n->right)
                n->r_thread = true;
        }
        return;
    }
    void remove(int key)
    {
        root = remove(root, key);
    }
    Node *remove(Node *root, int key)
    {
        Node *parent = NULL;
        Node *curr = root;
        bool found = false;
        while (curr != NULL)
        {
            if (key == curr->key)
            {
                found = true;
                break;
            }
            parent = curr;
            if (key < curr->key)
            {
                if (!curr->l_thread)
                    curr = curr->left;
                else
                {
                    break;
                }
            }
            else
            {
                if (!curr->r_thread)
                    curr = curr->right;
                else
                    break;
            }
        }
        if (!curr->l_thread && !curr->r_thread)
        {
            root = two_child(root, parent, curr);
        }
        else if (!curr->l_thread)
        {
            root = left_child(root, parent, curr);
        }
        else if (!curr->r_thread)
        {
            root = right_child(root, parent, curr);
        }
        else
        {
            root = no_child(root, parent, curr);
        }
    }
    Node *no_child(Node *root, Node *parent, Node *curr)
    {
        if (parent == NULL)
        {
            root = NULL;
            return root;
        }
        if (parent->left == curr)
        {
            parent->l_thread = true;
            parent->left = curr->left;
            return root;
        }
        parent->r_thread = true;
        parent->right = curr->right;
        return root;
    }
    Node *left_child(Node *root, Node *parent, Node *curr)
    {
        if (parent = NULL)
        {
            root = root->left;
            return root;
        }
        if (parent->left == curr)
        {
            parent->left = curr->left;
        }
        else
        {
            parent->right = curr->left;
        }
        Node *temp = curr->left;
        while (!temp->r_thread)
        {
            temp = temp->right;
        }
        temp->right = curr->right;
        return root;
    }
    Node *right_child(Node *root, Node *parent, Node *curr)
    {
        if (parent == NULL)
        {
            root = root->right;
            return root;
        }
        if (parent->left == curr)
        {
            parent->left = curr->right;
        }
        if (parent->right == curr)
        {
            parent->right = curr->right;
        }
        Node *temp = curr->right;
        while (!temp->l_thread)
        {
            temp = temp->left;
        }
        temp->left = curr->left;
        return root;
    }
    Node *two_child(Node *root, Node *parent, Node *curr)
    {
        Node *next = curr->right;
        while (!next->l_thread)
        {
            next = next->left;
        }
        curr->key = next->key;
        if (next->l_thread && next->r_thread)
        {
            root = no_child(root, curr, next);
        }
        else if (next->l_thread)
        {
            root = left_child(root, curr, next);
        }
        else
        {
            root = right_child(root, curr, next);
        }
        return root;
    }
    Node *left_most(Node *root)
    {
        if (root == NULL)
            return NULL;
        while (root->left != NULL && !root->l_thread)
            root = root->left;
        return root;
    }
    void inorder()
    {
        Node *curr = left_most(root);
        while (curr != NULL)
        {
            cout << curr->key << " ";
            if (curr->r_thread)
            {
                curr = curr->right;
            }
            else
            {
                curr = left_most(curr->right);
            }
        }
    }
    void preorder()
    {
        Node *curr = root;
        while (curr)
        {
            while (curr->left && curr->l_thread != true)
            {
                cout << curr->key << " ";
                curr = curr->left;
            }
            cout << curr->key << " ";
            while (curr && curr->r_thread && curr->right)
            {
                curr = curr->right;
            }
            curr = curr->right;
        }
    }
    void postorder()
    {
        Node*curr = root;
        vector<string> s;
        while(curr)
        {
            while(curr->right && curr->r_thread!=true)
            {
                s.push_back(to_string(curr->key));
                curr = curr->right;
            }
            s.push_back(to_string(curr->key));
            while(curr && curr->l_thread && curr->left)
            {
                curr = curr->left;
            }
            curr = curr->left;
        }
        for(auto x = s.rbegin(); x!=s.rend(); x++)
        {
            cout<<(*x)<<" ";
        }
    }
};
int main()
{
    TBST tree;
    int arr[] = {10, 15, 13, 17, 4, 7, 19, 1, 6};
    for (int i = 0; i < sizeof(arr) / 4; i++)
    {
        tree.insert(arr[i]);
    }
    // cout << tree.root->right->right->key;
    tree.inorder();
    cout << endl;
    tree.preorder();
    cout<<endl;
    tree.postorder();
}