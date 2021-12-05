#include <iostream>
using namespace std;
template <class T>
class node
{
public:
    T data;
    node<T> *next;
    node<T> *prev;
    node()
    {
        next = NULL;
        prev = NULL;
    }
    node<T> &operator=(const T &data)
    {
        this->data = data;
        return *this;
    }
    node<T> &operator=(const node<T> &node)
    {
        data = node.data;
        return *this;
    }
    bool operator==(const node<T> &node)
    {
        if (node.data == data)
        {
            return true;
        }
        return false;
    }
    bool operator==(const T &data)
    {
        if (this->data == data)
        {
            return true;
        }
        return false;
    }
    friend ostream &operator<<(ostream &out, node<T> &n)
    {
        out << n.data;
    }
};
template <class T>
class dllist
{
public:
    node<T> *head;
    dllist()
    {
        head = NULL;
    }
    int length()
    {
        if(head==NULL){
            return 0;
        }
        int l = 0;
        for(node<T> *temp = head; temp!=NULL; temp=temp->next){
            l++;
        }
        return l;
    }
    void unshift(T data)
    {
        node<T> *n_node = new node<T>;
        n_node->data = data;
        if (head == NULL)
        {
            head = n_node;
            return;
        }
        head->prev = n_node;
        n_node->next = head;
        head = n_node;
    }
    void push(T data)
    {
        node<T> *temp = head;
        node<T> *n_node = new node<T>;
        n_node->data = data;
        if (head == NULL)
        {
            head = n_node;
            return;
        }
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n_node;
        n_node->prev = temp;
    }
    void insert(int pos, T data)
    {
        if (head == NULL || pos <= 0)
        {
            unshift(data);
            return;
        }
        node<T> *temp = head;
        int idx = 0;
        while (temp->next != NULL && idx < pos - 1)
        {
            temp = temp->next;
            idx++;
        }
        node<T> *new_node = new node<T>;
        new_node->data = data;
        new_node->next = temp->next;
        new_node->prev = temp;
        if (temp->next != NULL)
        {
            temp->next->prev = new_node;
        }
        temp->next = new_node;
    }
    void pop(int pos)
    {
        if (head == NULL)
        {
            return;
        }
        if (pos <= 0)
        {
            node<T> *temp = head->next;
            delete temp->prev;
            head = temp;
            head->prev = NULL;
            return;
        }
        node<T> *temp = head;
        int idx = 0;
        while (idx < pos && temp->next != NULL)
        {
            temp = temp->next;
            idx++;
        }
        node<T> *temp_d = temp;
        temp->prev->next = temp->next;
        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }
        delete temp_d;
        return;
    }
    void print()
    {
        for (node<T> *temp = head; temp != NULL; temp = temp->next)
        {
            cout << temp->data << ' ';
        }
    }
    node<T> &operator[](int idx)
    {
        if (idx <= 0)
        {
            return *head;
        }
        node<T> *temp = head;
        while (idx > 0 && temp->next != NULL)
        {
            temp = temp->next;
            idx--;
        }
        return *temp;
    }
    friend ostream &operator<<(ostream &out, dllist<T> &l)
    {
        for (auto *temp = l.head; temp != NULL; temp = temp->next)
        {
            if (temp->next != NULL)
                out << temp->data << ' ';
            else
                out << temp->data;
        }
        return out;
    }
};
int main()
{
    dllist<int> l;
    for (int i = 0; i < 10; i++)
    {
        l.push(i + 1);
    }
    for(int i = 0; i<l.length(); i++){
        cout<<l[i]<<endl;
    }
}