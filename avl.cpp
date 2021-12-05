#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    int height;
    Node *left;
    Node *right;
    Node(int k)
    {
        key = k;
        height = 1;
        left = NULL;
        right = NULL;
    }
};
struct AVL
{
    Node *root;
    AVL()
    {
        root = NULL;
    }
    void insert(int key)
    {
        root = insert(root, key);
    }
    Node *insert(Node *node, int key)
    {
        if (node == NULL)
        {
            node = new Node(key);
            return node;
        }
        else if (key < node->key)
        {
            node->left = insert(node->left, key);
        }
        else if (key > node->key)
        {
            node->right = insert(node->right, key);
        }
        node->height = 1 + max(height(node->left),
                               height(node->right));
        int bf = get_balance(node);

        if (bf > 1 && key < node->left->key)
        {
            return left_left(node);
        }
        if (bf < -1 && key > node->right->key)
        {
            return right_right(node);
        }
        if (bf > 1 && key > node->left->key)
        {
            node->left = right_right(node->left);
            return left_left(node);
        }
        if (bf < -1 && key < node->right->key)
        {
            node->right = left_left(node->right);
            return right_right(node);
        }
        return node;
    }
    void remove(int key)
    {
        root = remove(root, key);
    }
    Node *remove(Node *root, int key)
    {
        if (root == NULL)
            return root;
        if (key < root->key)
            root->left = remove(root->left, key);
        else if (key > root->key)
            root->right = remove(root->right, key);
        else
        {
            if (root->left == NULL || root->right == NULL)
            {
                Node *temp = root->left ? root->left : root->right;
                if (!temp)
                {
                    root = NULL;
                }
                else
                {
                    *root = *temp;
                }
            }
            else
            {
                Node *temp = min_node(root->right);
                root->key = temp->key;
                root->right = remove(root->right, temp->key);
            }
        }
        if (root == NULL)
            return root;
        root->height = max(height(root->left), height(root->right)) + 1;
        int bf = get_balance(root);
        if (bf > 1 && get_balance(root->left) >= 0)
        {
            return left_left(root);
        }
        if (bf > 1 && get_balance(root->left) < 0)
        {
            root->left = right_right(root->left);
            return left_left(root);
        }
        if (bf < -1 && get_balance(root->right) <= 0)
        {
            return right_right(root);
        }
        if (bf < -1 && get_balance(root->right) > 0)
        {
            root->right = left_left(root->right);
            return right_right(root);
        }
        return root;
    }
    void inorder(Node *node, ostream &out)
    {
        if (node)
        {
            inorder(node->left, out);
            out << node->key << " ";
            inorder(node->right, out);
        }
    }
    void print_inorder()
    {
        inorder(root, cout);
    }
    void preorder(Node *node, ostream &out)
    {
        if (node)
        {
            out << node->key << " ";
            preorder(node->left, out);
            preorder(node->right, out);
        }
    }
    void print_preorder()
    {
        preorder(root, cout);
    }
    void postorder(Node *node, ostream &out)
    {
        if (node)
        {
            postorder(node->left, out);
            postorder(node->right, out);
            out << node->key << " ";
        }
    }
    void print_postorder()
    {
        postorder(root, cout);
    }
    int get_balance(Node *N)
    {
        if (N == NULL)
            return 0;
        return height(N->left) - height(N->right);
    }
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
    int height(Node *N)
    {
        if (N == NULL)
            return 0;
        return N->height;
    }
    Node *min_node(Node *node)
    {
        Node *curr = node;
        while (curr->left != NULL)
        {
            curr = curr->left;
        }
        return curr;
    }
    Node *left_left(Node *root)
    {
        Node *left = root->left;
        Node *temp = left->right;
        left->right = root;
        root->left = temp;
        root->height = max(height(root->left), height(root->right)) + 1;
        left->height = max(height(left->left), height(left->right)) + 1;
        return left;
    }
    Node *right_right(Node *root)
    {
        Node *right = root->right;
        Node *temp = right->left;
        right->left = root;
        root->right = temp;
        root->height = max(height(root->left), height(root->right)) + 1;
        right->height = max(height(right->right), height(right->left)) + 1;
        return right;
    }
    void traverse(Node *start, string padding, string pointer)
    {
        if (start != NULL)
        {
            string s;
            s.append(padding);
            s.append(pointer);
            s.append(to_string(start->key));
            cout << s << endl;
            string new_padding = padding;
            if (start == root)
                new_padding += "";
            else
                new_padding += "|  ";
            string pointer_for_left = "|--";
            string pointer_for_right = start->right != NULL ? "|--" : "|--";
            traverse(start->right, new_padding, pointer_for_right);
            traverse(start->left, new_padding, pointer_for_left);
        }
    }
    void print()
    {
        traverse(root, "", "");
    }
};
int main()
{
    AVL tree;
    int arr[] = {10, 20, 30, 40, 50, 45, 35, 25, 15, 5, 8, 18, 28};
    for (size_t i = 0; i < sizeof(arr) / 4; i++)
    {
        cout<<"started "<<i<<endl;
        tree.insert(arr[i]);
    }
    tree.print();
    // tree.remove(7);
    // cout<<"\n\n";
    // tree.print();
    // tree.remove(3);
    // cout<<"\n\n";
    // tree.print();
    // tree.remove(5);
    // cout<<"\n\n";
    // tree.print();
    // tree.remove(1);
    // cout<<"\n\n";
    // tree.print();
}