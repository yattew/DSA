#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int* keys;
    Node* *children;
    Node*parent;
    int fill;
    int size;
    Node()
    {
        fill = 0;
        parent = NULL;
        size = k;
        for (int i = 0; i < size; i++)
        {
            children[i] = NULL;
        }
        for (int i = 0; i < size - 1; i++)
        {
            keys[i] = -1;
        }
    }
};
struct Btree
{
    Node<K> *root;
    int size;
    Btree()
    {
        root = NULL:
    }
    void insert(int key)
    {
        if (root == NULL)
        {
            root = new Node<size>;
            root->keys[(root->fill)++] = key;
        }
    }
};
int main()
{
    Btree<5> tree;
}