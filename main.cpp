#include<bits/stdc++.h>

using namespace std;

int search(string a, int rootVal)
{
    for (int i = 0 ; i < a.size(); i++)
        if (a[i] == rootVal)
            return i;
    return -1;
}


void  printPostOrder(string preorder,string inorder)
{
    if(inorder.size()==0)
    {
        return;
    }
    string BEFore_root,AFTER_ROOT;
    for(int i=inorder.find(preorder[0])+1; i<inorder.size(); i++)
    {
        AFTER_ROOT.push_back(inorder[i]);
    }
    for(int i=0; i<inorder.find(preorder[0]); i++)
    {
        BEFore_root.push_back(inorder[i]);
    }
    string preorder_before = preorder , preorder_after = preorder ;
    for(int i = 0 ; i< AFTER_ROOT.size(); i++)
    {
        if(search( preorder_before,AFTER_ROOT[i])!=-1)
        {
            preorder_before.erase(search(preorder_before , AFTER_ROOT[i]),1);
        }
    }
    preorder_before.erase(0,1);
    for(int i=0; i<BEFore_root.size(); i++)
    {
        if(search(preorder_after,BEFore_root[i])!=-1)
        {
            preorder_after.erase(search(preorder_after,BEFore_root[i]),1);
        }
    }
    preorder_after.erase(0,1);

    printPostOrder(preorder_before,BEFore_root);

    printPostOrder(preorder_after,AFTER_ROOT);

    cout<<preorder[0];
}

int main()
{
    ///testcase_1
///--------------------

    printPostOrder("ABFGC", "FBGAC");
    cout<<endl;

    //post : FGBCA

    ///testcase_2
///--------------------

    printPostOrder("ABCEFDG", "ECFBDAG");
    cout<<endl;

    //post : EFCDBGA

    ///testcase_3
///--------------------

    printPostOrder("ABCEFDGHK", "ECFBGDHAK");
    cout<<endl;

    //post : EFCGHDBKA

    ///testcase_4
///--------------------

    printPostOrder("ABCED", "BAECD");
    cout<<endl;

    //post : BEDCA

    ///testcase_5
///--------------------

    printPostOrder("ABCDEF", "ACBEDF");
    cout<<endl;

    //post : CEFDBA



    return 0;

}


