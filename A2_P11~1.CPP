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
    /// node <t> *p
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
    int countleaves(node <t> *p)
    {
        if(p==nullptr)
            return 0;
        ///left null ptr and right null ptr
        if(p->left==p->right &&p->left==nullptr)
        {
            return 1;
        }
        return countleaves(p->left)+countleaves(p->right);

    }
    int countnodes(node <t> *p)
    {
        if(p==nullptr)
        {
            return 0;

        }
        return 1+countnodes(p->left)+countnodes(p->right);
    }
    int countheight(node <t> *p)
    {
        if(p==nullptr)
            return 0;
        return 1+max(countheight(p->left),countheight(p->right));
    }
    void inordertree(node <t> *p)
    {
        if(p==nullptr)
            return;
        inordertree(p->left);
        cout<<p->data<<" ";
        inordertree(p->right);
    }
    void preordertree(node <t> *p)
    {

        if(p==nullptr)
            return;
        /// Root left right
        cout<<p->data<<" ";
        preordertree(p->left);
        preordertree(p->right);

    }
    void postordertree(node <t> *p)
    {
        if(p==nullptr)
            return;
        preordertree(p->left);
        preordertree(p->right);
        cout<<p->data<<" ";
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
    bool subtree(node<t>*root1,node<t>*root2)
    {
        if(root2==nullptr)
            return true;
        if(root1==nullptr)
            return false;
        if(root1->data!=root2->data)
            return false ;
        return subtree(root1->left,root2->left)&&subtree(root1->right,root2->right);
    }
    bool SupTree(node<t>*root1,node<t>*root2)
    {

        if(root1==nullptr)
            return false;
        if(subtree(root1,root2))
            return true;
        return SupTree(root1->left,root2)||SupTree(root1->right,root2);
    }

public:
    binary_tree()
    {
        root=nullptr;
    }
    binary_tree(binary_tree&another)
    {
        if(another.root!=nullptr)
            another.destroy();
        copyTree(root,another.root);
    }
    void operator = (binary_tree&another)
    {
        if(another.root!=nullptr)
            another.destroy();
        copytree(root,another.root);
    }
    bool searchbyptr(node<t> *p,t data)
    {
        if(p==nullptr)
            return false;

        if(p->data==data)
            return true;
        return searchbyptr(p->left,data)||searchbyptr(p->right,data);
    }
    bool search(t data)
    {
        return searchbyptr(this->root,data);
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
            if(current->data>data)
            {
                current=current->left;
                continue;
            }
            if(current->data<data)
            {
                current=current->right;
                continue;
            }

        }
    }
    void insert(t data)
    {
        node<t>*newnode=new node <t>;
        newnode->data=data;
        newnode->left=newnode->right=nullptr;
        node<t>*leave=new node <t>;
        node<t>*rootleave=new node <t>;

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
    int leaves()
    {
        return countleaves(root);

    }
    int nodes()
    {
        return countnodes(root);

    }
    int height()
    {
        return countheight(root);
    }
    void inorder()
    {
        inordertree(root);
    }
    void preorder()
    {
        preordertree(root);

    }
    void postorder()
    {
        postordertree(root);

    }


    ~binary_tree()
    {
        deletetree(root);
    }
    void destroy()
    {
        deletetree(root);
    }
    void PrintRange(int front,int back)
    {
        for(int i=front; i<=back; i++)
        {
            if(BST_Search(i))
                cout<<i<<" ";
        }
    }
    bool Balance(node<t> *p)
    {
        if(p==nullptr)
            return true;
        if(countheight(p->left)!=countheight(p->right))
            return false;
        Balance(p->left);
        Balance(p->right);
    }
    bool  isBalance()
    {
        return Balance(root);

    }
    bool isSupTree(binary_tree <t>& bt2)
    {
        return SupTree(this->root,bt2.root);
    }







protected:
    node<t> * root;

};



int main()
{
    binary_tree<int> bt1,bt2,bt3,bt4,bt5;
    bt1.insert(5);
    bt1.insert(4);
    bt1.insert(6);
    cout<<"range(0,6) : ";
    bt1.PrintRange(0,6);
    cout<<endl;
    if(bt1.isBalance())
    {
        cout<<"isBalance\n";
    }
    else cout<<"is not Balance \n";


    bt2.insert(5);
    bt2.insert(6);
    cout<<"range(6,50) : ";
    bt2.PrintRange(6,50);
    cout<<endl;
    if(bt2.isBalance())
    {
        cout<<"isBalance\n";
    }
    else cout<<"is not Balance \n";

    bt3.insert(5);
    bt3.insert(4);
    bt3.insert(6);
    bt3.insert(85);
    bt3.insert(524);
    bt3.insert(796);
    bt3.insert(25);
    cout<<"range(6,796) : ";
    bt3.PrintRange(6,796);
    cout<<endl;
    if(bt3.isBalance())
    {
        cout<<"isBalance\n";
    }
    else cout<<"is not Balance \n";



    bt4.insert(0);
    bt4.insert(1);
    bt4.insert(2);
    bt4.insert(3);
    bt4.insert(4);

    cout<<"range(3,4) : ";
    bt4.PrintRange(3,4);
    cout<<endl;
    if(bt4.isBalance())
    {
        cout<<"isBalance\n";
    }
    else cout<<"is not Balance \n";



    bt5.insert(8);
    bt5.insert(9);
    bt5.insert(25);
    bt5.insert(12);
    bt5.insert(0);
    cout<<"range(0,9) : ";
    bt5.PrintRange(0,9);
    cout<<endl;
    if(bt5.isBalance())
    {
        cout<<"isBalance\n";
    }
    else cout<<"is not Balance \n";
        cout<<"Preorder Trees \n";
    cout<<"Tree 1 = (preorder) "; bt1.preorder(); cout<<endl;
    cout<<"Tree 2 = (preorder) "; bt2.preorder(); cout<<endl;
    cout<<"Tree 3 = (preorder) "; bt3.preorder(); cout<<endl;
    cout<<"Tree 4 = (preorder) "; bt4.preorder(); cout<<endl;
    cout<<"Tree 5 = (preorder) "; bt5.preorder(); cout<<endl;
        cout<<"Sub Trees"<<endl;
    cout<<" Tree 1.subTree(Tree 2) ";
    if(bt1.isSupTree(bt2)){
        cout<<"yes \n";
    }
    else cout<<"no \n";
    cout<<" Tree 2.subTree(Tree 3) ";
    if(bt2.isSupTree(bt3)){
        cout<<"yes \n";
    }
    else cout<<"no \n";
    cout<<" Tree 3.subTree(Tree 4) ";
    if(bt3.isSupTree(bt4)){
        cout<<"yes \n";
    }
    else cout<<"no \n";
    cout<<" Tree 4.subTree(Tree 5) ";
    if(bt4.isSupTree(bt5)){
        cout<<"yes \n";
    }
    else cout<<"no \n";
    cout<<" Tree 2.subTree(Tree 1) ";
    if(bt2.isSupTree(bt1)){
        cout<<"yes \n";
    }
    else cout<<"no \n";
    cout<<" Tree 4.subTree(Tree 3) ";
    if(bt4.isSupTree(bt3)){
        cout<<"yes \n";
    }
    else cout<<"no \n";

}
