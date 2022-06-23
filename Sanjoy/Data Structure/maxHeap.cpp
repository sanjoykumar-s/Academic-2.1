#include<bits/stdc++.h>
using namespace std;

struct MaxHeap
{
    int arr[100];
    int length=0;
    void init()
    {
        for(int i=0;i<100;i++)arr[i]=-1;
    }
    int root = 1;

    void add(int item,int rt)
    {
        if(length+1>=100)
        {
            cout << "Memory is Overflow\n";
            return;
        }
        int ptr = length+1;
        while(ptr>1)
        {
            int par = ptr/2;
            if(item>arr[par])
            {
                arr[ptr]=arr[par];
                ptr=par;
            }
            else if(item==arr[par])
            {
                cout << "Item is found at " << par << "\n";
                break;
            }
            else
            {
                arr[ptr]=item;
                break;
            }
        }
        if(ptr==1)arr[ptr]=item;
        length++;

    }


    void display(int rt)
    {
        if(rt>=100)
        {
            cout << "Overflow\n";
            return;
        }
        if(arr[rt]==-1)return;
        cout << arr[rt] << " (" << rt << ") ";
        display(rt*2);
        display((rt*2)+1);
    }
    void insert(int item)
    {
        add(item,root);
        display(root);
        cout << endl;
    }
};

int main()
{
    MaxHeap maxHeap;
    maxHeap.init();
    cout << "Please Giva an integer input to insert to Max Heap : " << endl;
    int n;
    cin >> n;
    while(n!=-1)
    {
        maxHeap.insert(n);
        cout << "Please Giva an integer input to insert to Max Heap : " << endl;
        cin >> n;
    }
    return 0;
}

