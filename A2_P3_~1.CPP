#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node*next;
};
class Queue
{
public:
    node *first,*last;
    int count;
    Queue()
    {
        count=0;
        first=nullptr;
        last=nullptr;
    }
    void push(int n)
    {
        count++;
        if(count==1)
        {

            node *tmp;
            tmp=new node;
            tmp->data=n;
            first=tmp;
            last=tmp;
        }
        else
        {
            node *tmp=new node;
            tmp->data=n;
            last->next=tmp;
            last=last->next;

        }
    }
    int front()
    {
        if(count>0)
            return first->data;
        else
        {
            try
            {
                throw(" ");
            }
            catch(...)
            {
                cout<<"No Data To Show\n";
                exit(505);


            }
        }
    }
    int back()
    {
        if(count>0)
            return last->data;
        else
        {
            try
            {
                throw(" ");
            }
            catch(...)
            {
                cout<<"No Data To Show\n";
                exit(505);

            }
        }
    }
    void pop()
    {
        if(count>0)
        {
            node *tmp=first;
            first=first->next;
            delete tmp;
            count--;
        }
        else
        {
            try
            {
                throw(" ");
            }
            catch(...)
            {
                cout<<"No Data To Erase\n";
                exit(505);

            }
        }
    }
    int size()
    {
        return count;
    }
};
class Stack
{
private:
    Queue qk;
public:
    int top()
    {
        if(qk.size()>0)
            return qk.front();
        else
        {
            try
            {
                throw("NO Data \n");
            }
            catch(...)
            {
                cout<<"NO Data \nThis Value is random :  ";
            }
        }

    }
    void push(int n)
    {
        int s=qk.size();
        qk.push(n);
        for(int i=0; i<s; i++)
        {
            qk.push(qk.front());
            qk.pop();
        }
    }

    void pop()
    {
        if(qk.size()>0)
            qk.pop();
        else
        {
            try
            {
                throw("NO Data \n");
            }
            catch(...)
            {
                cout<<"NO Data To Erase \n";
                exit(505);
            }
        }


    }
    int size()
    {
        return qk.size();
    }

};
int main()
{
    Stack sk;
    cout<<"stack 1 : ";
    int ar1[]= {1,2,3,4,5,6};
    for(int i=0; i<sizeof(ar1)/sizeof(ar1[0]); i++)
    {
        sk.push(ar1[i]);
    }
    while(sk.size())
    {
        cout<<sk.top()<<" ";
        sk.pop();
    }
    cout<<"\nstack 2 : ";

    int ar2[]= {154,273,342,4784,5676,6124};
    for(int i=0; i<sizeof(ar1)/sizeof(ar1[0]); i++)
    {
        sk.push(ar2[i]);
    }
    while(sk.size())
    {
        cout<<sk.top()<<" ";
        sk.pop();
    }


    cout<<"\nstack 3 : ";

    int ar3[]= {157,267,312,4022,4465,67};
    for(int i=0; i<sizeof(ar1)/sizeof(ar1[0]); i++)
    {
        sk.push(ar3[i]);
    }
    while(sk.size())
    {
        cout<<sk.top()<<" ";
        sk.pop();
    }

    cout<<"\nstack 4 : ";

    int ar4[]= {13,24,38,47,59,685};
    for(int i=0; i<sizeof(ar1)/sizeof(ar1[0]); i++)
    {
        sk.push(ar4[i]);
    }
    while(sk.size())
    {
        cout<<sk.top()<<" ";
        sk.pop();
    }

    cout<<"\nstack 5 : ";

    int ar5[]= {16,29,33,44,55,68};
    for(int i=0; i<sizeof(ar1)/sizeof(ar1[0]); i++)
    {
        sk.push(ar5[i]);
    }
    while(sk.size())
    {
        cout<<sk.top()<<" ";
        sk.pop();
    }

}


/*
class Stack
{
private:
    queue<int>qk;
public:
    int top()
    {
        if(qk.size()>0)
            return qk.front();
        else
        {
            try
            {
                throw("NO Data \n");
            }
            catch(...)
            {
                cout<<"NO Data \n";
                exit(505);
            }
        }

    }
    void push(int n)
    {
        int s=qk.size();
        qk.push(n);
        for(int i=0; i<s; i++)
        {
            qk.push(qk.front());
            qk.pop();
        }
    }

    void pop()
    {
        if(qk.size()>0)
            qk.pop();
        else
        {
            try
            {
                throw("NO Data \n");
            }
            catch(...)
            {
                cout<<"NO Data \n";
                exit(505);
            }
        }


    }
    int size()
    {
        return qk.size();
    }

};*/






