#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
        right(right) {}
};
class Solution
{
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        return isequal(p,q);
    }
    bool isequal(TreeNode* p, TreeNode* q)
    {
        if(p==q&&q==nullptr)
        {
            return true;
        }
        else if(p==nullptr&&q!=nullptr||q==nullptr&&p!=nullptr)
            return false ;
        else  if(p->val!=q->val)
            return false;
        return isequal(p->left,q->left)&&isequal(p->right,q->right);


    }
    friend void input(TreeNode *&p,vector<int>v);
    friend void getarray(TreeNode * &p,vector<int>&v);
};
void getarray(TreeNode * &p,vector<int>&v)
{
    if(v.front()==NULL)
    {
        v.erase(v.begin());
        return;
    }
    if(v.empty())
        return;
    p=new TreeNode(v.front());
    v.erase(v.begin());
    getarray(p->left,v);
    getarray(p->right,v);
}
void input(TreeNode *&p,vector<int>v)
{

    getarray(p,v);
}
int main()
{
    Solution s;
    cout<<"Test 1 : \n";
    TreeNode *t1;
    t1=new TreeNode(1);
    t1->left=new TreeNode(3);
    t1->right=new TreeNode(8);

    TreeNode *t2;
    t2=new TreeNode(1);
    t2->left=new TreeNode(3);
    t2->right=new TreeNode(8);
    if(s.isSameTree(t1,t2))
    {
        cout<<"is same\n";
    }
    else cout<<"No\n";



    cout<<"Test 2 : \n";
    delete t1;
    t1=new TreeNode(1);
    t1->left=new TreeNode(3);
    t1->right=new TreeNode(8);
    t1->left->left=new TreeNode(8);
    delete t2;

    t2=new TreeNode(1);
    t2->left=new TreeNode(3);
    t2->right=new TreeNode(8);
    t2->left->right=new TreeNode(8);
    if(s.isSameTree(t1,t2))
    {
        cout<<"is same\n";
    }
    else cout<<"No\n";



    cout<<"Test 3 : \n";
    delete t1;
    t1=new TreeNode(1);
    t1->left=new TreeNode(3);
    t1->right=new TreeNode(8);
    t1->left->left=new TreeNode(8);
    delete t2;

    t2=new TreeNode(1);
    t2->left=new TreeNode(3);
    t2->right=new TreeNode(8);
    t2->left->left=new TreeNode(8);
    if(s.isSameTree(t1,t2))
    {
        cout<<"is same\n";
    }
    else cout<<"No\n";


    cout<<"Test 4 : \n";
    delete t1;
    t1=new TreeNode(9);
    t1->left=new TreeNode(3);
    t1->right=new TreeNode(8);
    t1->left->left=new TreeNode(89);
    delete t2;

    t2=new TreeNode(1);
    t2->left=new TreeNode(3);
    t2->right=new TreeNode(8);
    t2->left->right=new TreeNode(8);
    if(s.isSameTree(t1,t2))
    {
        cout<<"is same\n";
    }
    else cout<<"No\n";


    cout<<"Test 5 : \n";
    delete t1;
    t1=new TreeNode(15);
    t1->left=new TreeNode(31);
    t1->right=new TreeNode(82);
    t1->left->left=new TreeNode(833);
    delete t2;

    t2=new TreeNode(15);
    t2->left=new TreeNode(31);
    t2->right=new TreeNode(8);
    t2->left->right=new TreeNode(833);
    if(s.isSameTree(t1,t2))
    {
        cout<<"is same\n";
    }
    else cout<<"No\n";







}
