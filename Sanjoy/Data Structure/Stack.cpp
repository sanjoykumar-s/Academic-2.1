#include<bits/stdc++.h>
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


int main()
{
    Stack mystack;
    mystack.push(5);
    mystack.push(10);
    mystack.push(12);
    while(mystack.size())
    {
        cout << mystack.top() << endl;
        mystack.pop();
    }
    return 0;
}
