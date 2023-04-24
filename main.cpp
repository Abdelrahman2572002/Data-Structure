#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    string data;
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
    void push(string n)
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
    string front()
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
    string back()
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
    string top()
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
    void push(string n)
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
    bool empty(){
        return !size();
    }
};
string simplify(string input){
    Stack str;
    string result;
for(int i=0;i<input.size();i++){
    if(input[i]=='/'){continue;}
        string tmp;
    while(i<input.size()&&input[i]!='/'){
        tmp +=input[i];
        ++i;
        }
    if(tmp=="."){continue;}
    else if(tmp==".."){
        if(!str.empty()){
            str.pop();
            }
            }
            else{
                str.push(tmp);
                }
        }

        while(!str.empty())
        {
            result = "/" + str.top() + result;
            str.pop();
        }

        if(result.size() == 0){
            return "/";
            }

        return result;
}

int main(){
    //1
 cout<<simplify("/home/")<<endl;
    //2
 cout<<simplify("/../")<<endl;
    //3
cout<<simplify("/home//foo/")<<endl;
    //4
cout<<simplify("/home/../abc/./foo/")<<endl;
    //5
cout<<simplify("/ezz/./ahmed/..////mostafa")<<endl;
}
