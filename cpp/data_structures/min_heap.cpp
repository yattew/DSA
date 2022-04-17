#include <bits/stdc++.h>
using namespace std;

struct min_heap
{
    int *arr;
    size_t fill;
    size_t ln;
    min_heap(int size)
    {
        arr = new int[size];
        fill = -1;
        ln = size;
    }
    void insert(int el)
    {
        arr[++fill] = el;
        int pt = fill;
        while(arr[pt]<arr[pt/2]){
            swap(arr[pt],arr[pt/2]);
            pt = pt/2;
        }
    }
    void remove_min()
    {
        arr[0] = arr[fill--];
        int pt = 0;
        while(pt<fill)
        {
            if(pt*2<=fill && arr[pt]>arr[pt*2])
            {
                swap(arr[pt],arr[pt*2]);
                pt = pt*2;
                continue;
            }
            if(pt*2+1<=fill && arr[pt]>arr[pt*2+1])
            {
                swap(arr[pt],arr[pt*2+1]);
                pt = pt*2+1;
                continue;
            }
            break;
        }
    }
};

int main()
{
    min_heap hp(10);
    hp.insert(5);
    hp.insert(7);
    hp.insert(15);
    hp.insert(3);
    hp.insert(1);
    hp.insert(20);
    hp.insert(8);
    for(int i = 0; i<= hp.fill; i++)
    {
        cout<<hp.arr[i]<<" ";
    }
    cout<<endl;
    hp.remove_min();
    for(int i = 0; i<= hp.fill; i++)
    {
        cout<<hp.arr[i]<<" ";
    }
    cout<<endl;
}