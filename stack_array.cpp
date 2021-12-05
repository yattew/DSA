#include <bits/stdc++.h>
using namespace std;
template <class T>
class Stack
{
public:
    int len = 0;
    T *arr;
    Stack()
    {
        arr = NULL;
    }
    void push(const T& data)
    {
        if (arr == NULL)
        {
            arr = (T *)malloc(sizeof(T));
            len = 1;
        }
        else
        {
            arr = (T *)realloc(arr, sizeof(arr) + sizeof(T));
            len++;
        }
        arr[len-1] = data;
    }
    T pop(){
        T temp = arr[len-1];
        len--;
        return temp;
    }
    ~Stack(){
        free(arr);
    }
    friend ostream& operator<<(ostream& out, const Stack& s){
        int l = s.len;
        for(int i = 0; i<l; i++){
            out<<s.arr[i]<<' ';
        }
        return out;
    }
};
int main()
{
    Stack<int> s;
    for(int i = 0; i<10; i++){
        s.push(i+1);
    }
    cout<<s<<endl;
    int t = s.pop();
    cout<<s<<endl;
    cout<<t<<endl;
}