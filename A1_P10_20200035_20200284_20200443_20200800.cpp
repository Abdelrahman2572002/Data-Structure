// =============================================================
// Student: Ahmed Salman Fahmin
// StudentID: 20200035
// =============================================================
// Student: Abdelrahamn Ramdan AboElela
// StudentID: 20200284
// =============================================================
// Student: Mohamed Refaat Mohamed
// StudentID: 20200443
// =============================================================
// Student: Adel Tarek Mouneer
// StudentID: 20200800
// =============================================================

#include <bits/stdc++.h>

using namespace std;
 template <class ty>
 struct node{
 ty d;
 node<ty> *n;

 };


    template<class ty>
    class listn{
private:
    node<ty> *h, *t;
public:
    listn(){
    h=NULL;
    t=NULL;

    }
    listn(ty v, int s){
    node <ty> *tm = new node<ty>;
    tm->d=v;
    tm->n=NULL;
    h=tm;
    t=tm;
    tm=NULL;
    for(int i=0; i<s-1;++i){
        node<ty> *tm=new node<ty>;
        tm->d=v;
        tm->n=NULL;
        t->n=tm;
        t=tm;
    }
    }
    class it{
public:
    node<ty> *node_it;
node <ty> *head_it;
public:

    it(){
    node_it=nullptr;
    head_it=nullptr;
    }
    it(node <ty> *pnode,node <ty> *h){
    node_it=pnode;
    head_it=h;

    }
    bool operator!=(const it& itrn)const {
            return node_it != itrn.node_it;
        }
    void operator++() {
    if(node_it-> n == NULL){
        cout<<"error not in list"<<endl;
        return;
    }
    node_it=node_it->n;

    }
    void operator --(){
        listn<ty> :: it t;
        t.node_it=this->head_it;
        t.head_it=this->head_it;
        if(this->head_it==this->node_it){
            cout<<"error out of list"<<endl;
        }
        else{
            while(t.node_it->n !=NULL){
                if(t.node_it->n==this->node_it){
                    this->node_it =t.node_it;
                    return;
                }
                ++t;
            }
        }
    }
    ty operator *() const{
    return node_it->d;
    }
    bool operator ==(const it& itan) const{
    return node_it==itan.node_it;
    }


    };
    void push_back(ty v)
    {
        node<ty> *tm=new node<ty>;
        tm->d=v;
        tm->n=NULL;
        if(h==NULL)
        {
            h=tm;
            t=tm;
            tm=NULL;
        }
        else
        {
            t->n=tm;
            t=tm;
        }
    }
    void insert(ty v,int po){
    node <ty> *p=new node<ty>;
    node <ty> *c=new node <ty>;
    node <ty> *tm=new node<ty>;
    c=h;
    for(int i=1;i<po;i++){
        p=c;
        c=c->n;
    }
    tm->d=v;
    p->n=tm;
    tm->n=c;
    }



    int size_of_list(){
    int c=0;
    node<ty> *tm=new node<ty>;
    tm=h;
    while(tm !=NULL){
        c++;
        tm=tm->n;
    }
    return c;
    }
    it erase(it pos){
    node<ty> *del = pos.node_it-> n;
    pos.node_it->n=pos.node_it->n->n;
    if(del==t) t=pos.node_it;
    delete del;
    return pos;


    }
    listn<ty> &operator =(listn<ty> an_listn){
    if(this == &an_listn){
        return *this;
    }
    it itan = an_listn.beg();
    this->push_back(*itan);
    do{
        ++itan;
        this->push_back(*itan);
    }while(itan != an_listn.end());
    return *this;
    }
    void delete_last()
    {
        node<ty> *c=new node<ty>;
        node<ty> *p=new node<ty>;
        c=h;
        while(c->n!=NULL)
        {
          p=c;
          c=c->n;
        }
        t=p;
        p->n=NULL;
        delete c;
    }
    it beg(){
    return it(h,h);
    }
    it end() {
    return it(t,h);
    }
~listn(){
do{
    delete_last();
}while(h !=t);
delete h;
delete t;
}



    };

int main()
{
listn<int> l(5,3);
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    cout<<l.size_of_list()<<endl;
    l.insert(2,5);
    l.delete_last();
    listn<int>:: it it1 = l.beg();
    listn<int>:: it it2 = l.beg();
    cout<<*it1;
    ++it1;
    cout<<*it1;
    l.erase(it2);
    listn<int> l2;
    l2 = l;
    return 0;
}
