#include<bits/stdc++.h>
using namespace std;
template<class t>
struct node
{
    t data;
    node*left,*right;
};
template<class t>
class binary_tree
{
private:
    void deletetree(node <t> *p)
    {
        if(p==nullptr)
            return;
        deletetree(p->left);
        deletetree(p->right);
        delete p;
        p=nullptr;
    }
public:
    binary_tree()
    {
        root=nullptr;
    }
    bool BST_Search(t data)
    {
        node<t>*current=root;
        if(current==nullptr)
            return false;
        while(current!=nullptr)
        {
            if(current->data==data)
                return true;
            else if(current->data > data)
            {
                current=current->left;
            }
            else if(current->data < data)
            {
                current=current->right;
            }
            else return false;
        }
    }
    void insert(t data)
    {
        node<t>*newnode=new node <t>;
        newnode->data=data;
        newnode->left=newnode->right=nullptr;
        node<t> * leave = new node <t>;
        node<t> * rootleave=new node <t>;

        if(root==nullptr)
        {
            root=newnode;
            return;
        }
        leave=root;
        while(leave!=nullptr)
        {
            rootleave=leave;
            if(leave->data==data)
            {
                return;
            }
            if(leave->data>data)
            {
                leave= leave->left;
                continue;
            }
            if(leave->data<data)
            {
                leave=leave->right;
            }
        }
        if(rootleave->data>data)
        {
            rootleave->left=newnode;
        }
        else if(rootleave->data<data)
            rootleave->right=newnode;
    }
    bool empty()
    {
        return root==nullptr;
    }
    ~binary_tree()
    {
        deletetree(root);
    }
    t  min_element()
    {

        node<t>*current=new node <t>;
        current=root;
        node<t>*rootleave=new node <t>;
        while(current!=nullptr)
        {
            rootleave=current;
            current=current->left;
        }
        return rootleave->data;
    }



protected:
    node<t> * root;

};
int count_min_or_equal( binary_tree<int>&bt,int data)
{
    int count=0;
    for(int i=bt.min_element(); i<=data; i++)
    {
        if(bt.BST_Search(i))
            count+=i;
    }
    return count;
}
int main()
{
    binary_tree<int> bt;

    bt.insert(5);
    bt.insert(4);
    bt.insert(6);
    cout<<"range (0,"<<3<<") : "<<count_min_or_equal(bt,3);

    cout<<endl;
    binary_tree<int> bt1;
    bt1.insert(1);
    bt1.insert(2);
    bt1.insert(3);
    bt1.insert(8);
    bt1.insert(15);
    bt1.insert(30);
    cout<<"range (0,"<<15<<") : "<<count_min_or_equal(bt1,15);

    cout<<endl;


    binary_tree<int> bt2;
    bt2.insert(193);
    bt2.insert(22);
    bt2.insert(3);
    bt2.insert(89);
    bt2.insert(25);
    bt2.insert(40);
    cout<<"range (0,"<<89<<") : "<<count_min_or_equal(bt2,89);
    binary_tree<int> bt3;
    cout<<endl;


    bt3.insert(10);
    bt3.insert(20);
    bt3.insert(30);
    bt3.insert(80);
    bt3.insert(5);
    bt3.insert(310);
    cout<<"range (0,"<<80<<") : "<<count_min_or_equal(bt3,80);
    binary_tree<int> bt4;

    cout<<endl;

    bt4.insert(10);
    bt4.insert(100);
    bt4.insert(5);
    bt4.insert(28);
    bt4.insert(17);
    bt4.insert(42);
    cout<<"range (0,"<<17<<") : "<<count_min_or_equal(bt4,17);
    cout<<endl;


}
