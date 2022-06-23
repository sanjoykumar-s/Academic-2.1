#include<bits/stdc++.h>
#define int long long
using namespace std;

struct Stack
{
    int stck[100];int frnt=0;

    void push(int item)
    {
        if(frnt==99)
        {
            cout << "Stack is full.. Push Operation Unsuccessfull.";
            return;
        }
        stck[frnt]=item;
        frnt++;
    }

    void pop()
    {
        if(frnt==0)
        {
            cout << "Stack is NULL. Pop operation Unsuccessfull.";
            return;
        }
        stck[frnt-1]=-1;
        frnt--;
    }
    int size()
    {
        return frnt;
    }

    int top()
    {
        return stck[frnt-1];
    }
};

Stack mystack;

int postflixEv(string s)
{
    for(int i=0;i<s.size();i++)
    {
        char ch = s[i];
        if(ch==',')continue;
        if(ch=='*' || ch =='+' || ch=='-' || ch=='/' || ch == '^')
        {
            if(mystack.size()<2)
            {
                cout << "Invalid Input..\n";
                return -1;
            }
            else
            {
                int a = mystack.top();
                mystack.pop();
                int b = mystack.top();
                mystack.pop();
                if(ch=='*')mystack.push(a*b);
                else if(ch == '+')mystack.push(a+b);
                else if(ch=='-')mystack.push(b-a);
                else if(ch=='/')mystack.push(b/a);
                else if(ch=='^')mystack.push(pow(b,a));
            }
        }
        else
        {
            int a=0;
            int base=1;
            int id = i;
            while(id<s.size() && s[id]!=',')
            {
                id++;
                base*=10;
            }
            base/=10;
            id = i;
            while(id<s.size() && s[id]!=',')
            {
                int p = s[id] - '0';
                a+=p*base;
                id++;
                base/=10;
            }
            mystack.push(a);
            i=id;
        }
    }
    if(mystack.size()>1)
    {
        cout << "Invalid Input..\n";
                return -1;
    }
    int q = mystack.top();
    mystack.pop();
    return q;
}



int32_t main()
{
    string s;
    cin >> s;
    int ev = postflixEv(s);
    if(ev==-1)return 0;
    cout << ev << endl;
    return 0;
}
