#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node() {}
    
    friend ostream &operator<<(ostream &out, const Node<T> &n)
    {
        out << n.data;
        return out;
    }

};

template <class T>
class llist
{
public:
    struct Node<T> *head;
    llist()
    {
        head = NULL;
    };
    void unshift(T x)
    {
        struct Node<T> *temp = new struct Node<T>;
        temp->data = x;
        temp->next = head;
        head = temp;
    }
    void insert(int pos, T value)
    {
        if (pos == 0)
        {
            unshift(value);
            return;
        }
        else if (head == NULL)
        {
            unshift(value);
            return;
        }
        struct Node<T> *curr_node = head;
        int ct = 0;
        while (ct < pos - 1)
        {
            if (curr_node->next == NULL)
            {
                break;
            }
            curr_node = curr_node->next;
            ct++;
        }
        struct Node<T> *temp = new struct Node<T>;
        temp->data = value;
        temp->next = curr_node->next;
        curr_node->next = temp;
    }
    void pop(int pos)
    {
        if (head == NULL)
        {
            return;
        }
        struct Node<T> *prev = head;
        struct Node<T> *curr = head;
        struct Node<T> *temp = curr;
        if (pos == 0)
        {
            head = head->next;
            delete curr;
            return;
        }

        int ct = 0;
        while (ct < pos && curr != NULL)
        {
            prev = curr;
            curr = curr->next;
            ct++;
        }
        if (curr == NULL)
        {
            cout << "list index out of range" << endl;
            return;
        }
        temp = curr;
        prev->next = curr->next;
        delete temp;
    }
    void reverse()
    {
        struct Node<T> *curr, *prev, *next;
        curr = head;
        prev = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    void reverse_r(struct Node<T> *temp)
    {
        if (temp->next == NULL)
        {
            head = temp;
            return;
        }
        reverse_r(temp->next);
        struct Node<T> *temp1 = temp->next;
        temp1->next = temp;
        temp->next = NULL;
    }
    struct Node<T> search(T val)
    {
        for (struct Node<T> *temp = head; temp != NULL; temp = temp->next)
        {
            if (temp->data == val)
            {
                return *temp;
            }
        }
    };
    struct Node<T>& operator[](int idx)
    {
        struct Node<T> *temp = head;
        for (; temp->next != NULL; temp = temp->next)
        {
            if (idx == 0)
            {
                return *temp;
            }
            idx--;
        }
        return *temp;
    };
    friend ostream& operator<<(ostream& out, const llist<T> l){
        for (struct Node<T> *temp = l.head; temp != NULL; temp = temp->next)
        {
            out<<temp->data<<' ';
        }
        return out;
    }
    void print()
    {
        for (struct Node<T> *temp = head; temp != NULL; temp = temp->next)
        {
            cout << temp->data << ' ';
        }
    }
    void print_r(struct Node<T> *temp)
    {
        if (temp == NULL)
        {
            return;
        }
        cout << temp->data << ' ';
        print_r(temp->next);
    }
};

int main()
{
    llist<int> l;
    for (int i = 0; i < 10; i++)
    {
        l.insert(i, i + 1);
    }
    cout<<l[0];
}