//problem 7
#include <bits/stdc++.h>
using namespace std;

struct node
{
	int num;
	 node *le;
	  node*ri;
};
 node* newnode(int x)
{



 node* t=( node*)
                         malloc(sizeof( node));


	t->num = x;
	t->le = t->ri = NULL;
	return t;
}


void flip( node* n)
{
    if (n == NULL)
        return;
    else
    {
         node* t;


        flip(n->le);
        flip(n->ri);


        t     = n->le;
        n->le = n->ri;
        n->ri = t;
    }
}


void printtree(node *r)
{

	if (r == NULL) return;
	queue<node *> que;
	que.push(r);

	while (1)
	{
		int c = que.size();
		if (c == 0)
			break;

    while (c > 0)
		{
			node *n = que.front();
			cout << n->num << " ";
			que.pop();
			if (n->le != NULL)
				que.push(n->le);
			if (n->ri != NULL)
				que.push(n->ri);
			c--;
		}
		cout << endl;
	}
}


int main()
{
    //test case1
	 node* r = newnode(1);
	r->le = newnode(2);
	r->ri = newnode(3);
	r->le->le = newnode(4);
	r->le->ri = newnode(5);

	cout << "given tree\n";
	printtree(r);

	flip(r);

	cout << "flip tree\n";

	printtree(r);
	delete(r);
	//test case 2
	  r = newnode(5);
	r->le = newnode(6);
	r->ri = newnode(4);
	r->le->le = newnode(1);
	r->le->ri = newnode(2);

	cout << "given tree\n";
	printtree(r);

	flip(r);

	cout << "flip tree\n";
	printtree(r);
	delete(r);
	//test case 3
	  r = newnode(100);
	r->le = newnode(50);
	r->ri = newnode(200);
	r->le->le = newnode(300);
	r->le->ri = newnode(400);

	cout << "given tree\n";
	printtree(r);

	flip(r);

	cout << "flip tree\n";

	printtree(r);
	delete(r);
	//test case 4
	  r = newnode(10);
	r->le = newnode(20);
	r->ri = newnode(30);
	r->le->le = newnode(40);
	r->le->ri = newnode(50);
	r->ri->le =newnode(60);
	r->ri->ri =newnode(70);

	cout << "given tree\n";
	printtree(r);

	flip(r);

	cout << "flip tree\n";

	printtree(r);
	delete(r);
	//test case 5
	  r = newnode(10);
	r->le = newnode(5);
	r->ri = newnode(8);
	r->le->le = newnode(9);
	r->le->ri = newnode(15);
	r->ri->le =newnode(6);
	r->ri->ri =newnode(7);
	r->le->le->le =newnode(11);
	r->le->le->ri =newnode(12);

	cout << "given tree\n";
	printtree(r);

	flip(r);

	cout << "flip tree\n";

	printtree(r);
	delete(r);
	return 0;
}
