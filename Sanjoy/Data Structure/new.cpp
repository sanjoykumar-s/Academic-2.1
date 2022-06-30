#include<bits/stdc++.h>
using namespace std;

struct MaxHeap
{
    int arr[100];
    int length=0;
    int dis[100][100];
    void init()
    {
        for(int i=0;i<100;i++)arr[i]=-1;
        memset(dis,-1,sizeof(dis));
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
    int l = 0;
    int r = 99;
    int maker()
    {
        int row = 0;
        int mid = (l+r)/2;
        int i = 1;
        int n = length;
        int el = 1;
        while(i<=n){
                int cnt = 0;
            for(int k = mid+1;cnt<el && i<=n;k+=mid)
            {
                dis[row][k]=arr[i];
                cnt++;
                i++;
            }
            row++;
            el = el << 1;
            mid = (l+r)/(el+1);
        }
        return row;
    }

    void display()
    {
        int rw = maker();
        //cout << rw << " " << length << endl;
        for(int i=0;i<=rw;i++)
        {
            for(int j=0;j<100;j++)
            {
                if(dis[i][j]==-1)cout << " ";
                else  cout << dis[i][j];
            }
            cout << endl;
            cout << endl;
            cout << endl;
        }
    }
    void insert(int item)
    {
        add(item,root);
        display();
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

