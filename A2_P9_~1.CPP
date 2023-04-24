#include<bits/stdc++.h>
using namespace std;
template<class t>
struct node
{
    t data;
    node *left;
    node *right;
    node<t>() : data(0), left(nullptr), right(nullptr) {}
    node<t>(t x) : data(x), left(nullptr), right(nullptr) {}
    node<t>(t x, node *left, node *right) : data(x), left(left),
        right(right) {}
};
template<class t>
class binary_tree
{
private:
    void copyTree(node<t>* &copiedTreeRoot,node<t>* otherTreeRoot)
    {
        if (otherTreeRoot == NULL)
            copiedTreeRoot = NULL;
        else
        {
            copiedTreeRoot = new node<t>;
            copiedTreeRoot->data = otherTreeRoot->data;
            copyTree(copiedTreeRoot->left, otherTreeRoot->left);
            copyTree(copiedTreeRoot->right, otherTreeRoot->right);
        }
    }
    node <t> *create()
    {
        t x;
        cout<<"enter data : ";
        cin>>x;
        if(x==-1)
            return 0;
        node <t>*newnode= new node <t>;
        newnode->data=x;
        cout<<"Eter left of node : "<<x<<endl;
        newnode->left=create();
        cout<<"Eter right of node : "<<x<<endl;
        newnode->right=create();
        return newnode;
    }
    void deletetree(node <t> *p)
    {
        if(p==nullptr)
            return;
        deletetree(p->left);
        deletetree(p->right);
        delete p;
        p=nullptr;

    }
    bool isequal(node <t> *p, node <t> *q)
    {
        if(p==q&&q==nullptr)
        {
            return true;
        }
        else if(p==nullptr&&q!=nullptr||q==nullptr&&p!=nullptr)
            return false ;
        return isequal(p->left,q->left)&&isequal(p->right,q->right);
    }
    bool isSameTree(node<t>* p, node<t>* q)
    {
        return isequal(p,q);
    }
    void flip( node <t> * n)
    {
        if (n == nullptr)
            return;
        else
        {
            struct node<t>*k;
            flip(n->left);
            flip(n->right);
            k= n->left;
            n->left = n->right;
            n->right = k;
        }
    }
public:
    node<t> * root;
    binary_tree()
    {
        root=nullptr;
    }
    binary_tree(const binary_tree<t>&another)
    {
        copyTree(root,another.root);
    }
    bool empty()
    {
        return root==nullptr;
    }
    ~binary_tree()
    {
        deletetree(root);
    }
    void begin()
    {
        root=create();
    }
    bool isFoldable()
    {
        binary_tree<t> bt2(*this);
        flip(bt2.root);
        return isSameTree(root,bt2.root);
    }


};
int main()
{

    binary_tree<int> bt1;
    node <int>*p;
    p=new node<int>(5,new node <int>(3),new node <int>(8));
    bt1.root=p;
    if(bt1.isFoldable()) cout<<1 <<" is foldable";
    else cout<<1<<"is not foldable";

    cout<<endl;


    binary_tree<int> bt2;
    node <int>*p2;
    p2=new node<int>(10,new node <int>(3,new node <int>(5),new node <int>(7)),new node <int>(8,new node <int>(10),new node <int>(15)));
    bt2.root=p2;
    if(bt2.isFoldable()) cout<<2 <<" is foldable";
    else cout<<2<<"is not foldable";
        cout<<endl;


    binary_tree<int> bt3;
    node <int>*p3;
    p3=new node<int>(5,new node <int>(90,new node <int>(2),new node <int>(85,new node <int>(42),new node <int>(58))),new node <int>(8));
    bt3.root=p3;
    if(bt3.isFoldable()) cout<<3 <<" is foldable";
    else cout<<3<<" is not foldable";

        cout<<endl;


    binary_tree<int> bt4;
    node <int>*p4;
    p4=new node<int>(5,new node <int>(3,new node <int>(73),new node <int>(49)),new node <int>(8,new node <int>(5),new node <int>(48)));
    bt4.root=p4;
    if(bt4.isFoldable()) cout<<4 <<" is foldable";
    else cout<<4<<"is not foldable";

        cout<<endl;


    binary_tree<int> bt5;
    node <int>*p5;
    p5=new node<int>(5,new node <int>(3,new node <int>(20),new node <int>(8)),new node <int>(39,new node <int>(39),new node <int>(45)));
    bt5.root=p5;
    if(bt5.isFoldable()) cout<<5 <<" is foldable";
    else cout<<5<<"is not foldable";
}

