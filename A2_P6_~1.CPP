//problem 6
#include <bits/stdc++.h>
using namespace std;


class node
{
public:
    string expression;
    node *le = NULL, *ri = NULL;
    node(string n)
    {
        expression = n;
    }
};

//function to convert string to integer
int convert_to_integer(string x)
{
    int n = 0;

    if(x[0]!='-')
        for (int j=0; j<x.length(); j++)
            n = n*10 + (int(x[j])-48);
    else
    {
        for (int j=1; j<x.length(); j++)
            n = n*10 + (int(x[j])-48);
        n = n*-1;
    }

    return n;
}
//function to evaluate
int evaluate(node* r)
{

    if (!r)
        return 0;
    if (!r->le&& !r->ri)
        return convert_to_integer(r->expression);

    int left_value = evaluate(r->le);
    int right_value = evaluate(r->ri);
    if (r->expression=="+")
        return left_value+right_value;

    if (r->expression=="-")
        return left_value-right_value;

    if (r->expression=="*")
        return left_value*right_value;

    return left_value/right_value;
}


int main()
{
    //test case 1
    node *r = new node("+");
    r->le = new node("3");
    r->ri = new node("*");
    r->ri->le= new node("4");
    r->ri->ri = new node("/");
    r->ri->ri->le = new node("8");
    r->ri->ri->ri = new node("2");

    cout << evaluate(r) << endl;
    delete(r);
    //test case 2
    r = new node("*");
    r->le = new node("3");
    r->ri = new node("+");
    r->ri->le= new node("6");
    r->ri->ri = new node("+");
    r->ri->ri->le = new node("4");
    r->ri->ri->ri = new node("10");

    cout << evaluate(r) << endl;
    delete(r);
    //test case 3
    r = new node("*");
    r->le = new node("12");
    r->ri = new node("+");
    r->ri->le= new node("10");
    r->ri->ri = new node("*");
    r->ri->ri->le = new node("5");
    r->ri->ri->ri = new node("8");

    cout << evaluate(r) << endl;
    delete(r);
    //test case 4
    r = new node("+");
    r->le = new node("10");
    r->ri = new node("*");
    r->ri->le= new node("25");
    r->ri->ri = new node("+");
    r->ri->ri->le = new node("5");
    r->ri->ri->ri = new node("*");
    r->le->ri =new node("10");
    r->le->le =new node("8");

    cout << evaluate(r) << endl;
    delete(r);
//test case 5
    r = new node("+");
    r->le = new node("15");
    r->ri = new node("*");
    r->le->le= new node("5");
    r->le->ri = new node("+");
    r->le->ri->le = new node("10");
    r->le->ri->ri = new node("20");


    cout << evaluate(r) << endl;
    delete(r);




    return 0;
}
