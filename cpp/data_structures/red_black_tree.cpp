#include <bits/stdc++.h>
using namespace std;
enum COLOR : bool
{
    black,
    red
};
struct Node
{
    int key;
    COLOR color;
    Node *left;
    Node *right;
    Node *parent;
    Node(int d) : key(d),
                  color(red),
                  left(NULL),
                  right(NULL),
                  parent(NULL) {}
};
struct RBTree
{
    Node *root;
    RBTree()
    {
        root = NULL;
    }
    void insert(int key)
    {
        Node *node = new Node(key);
        root = bst_insert(root, node);
        fix_tree(root, node);
    }
    Node *bst_insert(Node *root, Node *node)
    {
        if (root == NULL)
        {
            return node;
        }
        else if (node->key < root->key)
        {
            root->left = bst_insert(root->left, node);
            root->left->parent = root;
        }
        else if (node->key > root->key)
        {
            root->right = bst_insert(root->right, node);
            root->right->parent = root;
        }
        return root;
    }
    void remove(Node*x)
    {
        if(x == root)
        {
            root = NULL;
            return;
        }
        Node*parent = x->parent;
        if(parent->right == x)
        {
            parent->right = NULL;
            x->parent = NULL;
            return;
        }
        parent->left = NULL;
        x->parent = NULL;
        return;
    }
    void remove(int key)
    {
        Node *to_remove = NULL;
        bst_remove(key, root, to_remove);
        //to_remove contains the leaf node which needs to be removed
        fix_remove(root, to_remove);
        remove(to_remove);
    }
    void bst_remove(int key, Node *root, Node *&to_remove)
    {
        if (key == root->key)
        {
            if (root->right)
            {
                Node *temp = root->right;
                while (temp->left)
                {
                    temp = temp->left;
                }
                root->key = temp->key;
                bst_remove(temp->key, temp, to_remove);
            }
            else if (root->left)
            {
                Node *temp = root->left;
                while (temp->right)
                {
                    temp = temp->right;
                }
                root->key = temp->key;
                bst_remove(temp->key, temp, to_remove);
            }
            else
            {
                to_remove = root;
            }
        }
        else if (key < root->key)
        {
            bst_remove(key, root->left, to_remove);
        }
        else
        {
            bst_remove(key, root->right, to_remove);
        }
    }
    void fix_remove(Node *&root, Node *x)
    {
        while (true)
        {
            Node*sibling = get_sibling(x);
            Node*nephew = get_nephew(x);
            Node*neice = get_neice(x);
            // cout<<endl;
            // cout<<"sibling:"<<sibling->key<<endl;
            // cout<<"nephew:"<<nephew->key<<endl;
            // break;
            if (x == root)
                break;
            else if (x->color == red)
                break;
            else if(sibling && sibling->color == red)
            {
                x->parent->color = red;
                sibling->color = black;
                rotate_sibling_to_parent(x->parent,sibling);
            }
            else if(nephew && nephew->color == red)
            {
                sibling->color = x->parent->color;
                x->parent->color = black;
                nephew->color = black;
                rotate_sibling_to_parent(x->parent,sibling);
                x = root;
                break;
            }
            else if(neice && neice->color == red)
            {
                neice->color = black;
                sibling->color = black;
                rotate_neice_to_sibling(x);
            }
            else{
                sibling->color = red;
                x = x->parent;
            }
        }
        x->color = black;
    }
    Node* get_sibling(Node*node)
    {
        if(!node->parent)
            return NULL;
        if(node->parent->left == node)
            return node->parent->right;
        return node->parent->left;
    }
    Node* get_nephew(Node*x)//right child of sibling of x
    {
        Node*sibling = get_sibling(x);
        if(!sibling)
            return NULL;
        return sibling->right;
    }
    Node* get_neice(Node*x)//left child of sibling of x
    {
        Node*sibling = get_sibling(x);
        if(!sibling)
            return NULL;
        return sibling->left;
    }
    void rotate_sibling_to_parent(Node*&parent,Node*sibling)
    {
        if(parent->right == sibling)
        {
            left_rotate(root,parent);
        }
        else
        {
            right_rotate(root,parent);
        }
    }
    void rotate_neice_to_sibling(Node*x)
    {
        Node*sibling = get_sibling(x);
        Node*neice = get_neice(x);
        if(sibling->right == neice)
        {
            left_rotate(root,sibling);
        }
        else
        {
            right_rotate(root,sibling);
        }
    }
    void inorder(Node *root)
    {
        if (root)
        {
            inorder(root->left);
            cout << root->key << " ";
            inorder(root->right);
        }
    }
    void inorder()
    {
        inorder(root);
    }
    void left_rotate(Node *&root, Node *&node)
    {
        Node *right_node = node->right;
        node->right = right_node->left;
        if (node->right)
            node->right->parent = node;
        right_node->parent = node->parent;

        if (node->parent == NULL)
            root = right_node;
        else if (node == node->parent->left)
            node->parent->left = right_node;
        else
            node->parent->right = right_node;
        right_node->left = node;
        node->parent = right_node;
    }
    void right_rotate(Node *&root, Node *&node)
    {
        Node *left_node = node->left;
        node->left = left_node->right;
        if (node->left)
            node->left->parent = node;
        left_node->parent = node->parent;
        if (node->parent == NULL)
            root = left_node;
        else if (node == node->parent->left)
            node->parent->left = left_node;
        else
            node->parent->right = left_node;

        left_node->right = node;
        node->parent = left_node;
    }
    void fix_tree(Node *&root, Node *node)
    {
        Node *parent_node = NULL;
        Node *grand_parent_node = NULL;
        while (
            (node != root) &&
            (node->color != black) &&
            (node->parent->color == red))
        {
            parent_node = node->parent;
            grand_parent_node = node->parent->parent;

            if (parent_node == grand_parent_node->left)
            {
                Node *uncle_node = grand_parent_node->right;
                if (uncle_node != NULL && uncle_node->color == red)
                {
                    grand_parent_node->color = red;
                    parent_node->color = black;
                    uncle_node->color = black;
                    node = grand_parent_node;
                }
                else
                {
                    if (node == parent_node->right)
                    {
                        left_rotate(root, parent_node);
                        node = parent_node;
                        parent_node = node->parent;
                    }
                    right_rotate(root, grand_parent_node);
                    swap(parent_node->color, grand_parent_node->color);
                    node = parent_node;
                }
            }
            else
            {
                Node *uncle_node = grand_parent_node->left;

                if (uncle_node != NULL && uncle_node->color == red)
                {
                    grand_parent_node->color = red;
                    parent_node->color = black;
                    uncle_node->color = black;
                    node = grand_parent_node;
                }
                else
                {
                    if (node == parent_node->left)
                    {
                        right_rotate(root, parent_node);
                        node = parent_node;
                        parent_node = node->parent;
                    }
                    left_rotate(root, grand_parent_node);
                    swap(parent_node->color, grand_parent_node->color);
                    node = parent_node;
                }
            }
        }
        root->color = black;
    }
    void traverse(Node *start, string padding, string pointer)
    {
        if (start != NULL)
        {
            string s;
            s.append(padding);
            s.append(pointer);
            s.append(start->color == red ? "R" : "B");
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
    RBTree tree;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto x : arr)
    {
        tree.insert(x);
    }
    tree.print();
    cout << endl;
    tree.remove(4);
    cout << endl;
    tree.print();
    // tree.inorder();
}