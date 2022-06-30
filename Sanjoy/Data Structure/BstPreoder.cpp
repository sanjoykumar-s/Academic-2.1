#include<bits/stdc++.h>
using namespace std;

struct BST
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
        if(rt>=100)
        {
            cout << "Memory Overflowed\n";
            return;
        }
        else if(arr[rt]==-1)
        {
            arr[rt]=item;
            return;
        }
        else if(arr[rt]==item)
        {
            cout << "The item is found at " << rt << endl;
            return;
        }
        else if(arr[rt]<item)add(item,(2*rt)+1);
        else if(arr[rt]>item)add(item,(2*rt));

    }

    void display(int rt)
    {
        if(rt>=100)
        {
            cout << "Overflow\n";
            return;
        }
        if(arr[rt]==-1)return;
        display(rt*2);
        cout << arr[rt] << " ";
        display((rt*2)+1);
    }
    void insert(int item)
    {
        add(item,root);
        cout << "PreOder Traverse: ";
        display(root);
        cout << endl;
    }
};

int main()
{
    BST tree;
    tree.init();
    cout << "Please Giva an integer input to Search / insert to BST : " << endl;
    int n;
    cin >> n;
    while(n!=-1)
    {
        tree.insert(n);
        cout << "Please Giva an integer input to Search / insert to BST : " << endl;
        cin >> n;
    }
    return 0;
}
