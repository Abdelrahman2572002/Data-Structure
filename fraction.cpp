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
#include "fraction.h"
using namespace std;
//class
fraction_numbers::fraction_numbers()
{

}
    //constructor
fraction_numbers::fraction_numbers(int n1,int n2)
{
    num1=n1;
    num2=n2;
}
fraction_numbers ::fraction_numbers(const fraction_numbers &ob)
{

    num1 = ob.num1;
    num2=ob.num2;
    this->reduce_fraction();
}

int fraction_numbers ::common_divisor(int n1, int n2)
{
    if (n2 == 0)
        return n1;
    return common_divisor(n2, n1 % n2);
}
void fraction_numbers :: reduce_fraction ()
{
    int y=common_divisor(num1,num2);
    num1/=y;
    num2/=y;

}
    //equal operator
bool fraction_numbers :: operator == (fraction_numbers ob)
{

    if (num1==ob.num1&&num2==ob.num2)
        return true;
    else
        return false;
}
    // not equal operator
bool fraction_numbers :: operator != (fraction_numbers ob)
{

    if (num1==ob.num1&&num2==ob.num2){
                return false;}
    else{
    return true;}
}

bool fraction_numbers :: operator >(fraction_numbers ob)
{

    if(( double )num1/num2>( double )ob.num1/ob.num2)
        return true ;
    else
    return 0;

}

bool fraction_numbers :: operator <(fraction_numbers ob)
{

    if(( double )num1/num2<( double )ob.num1/ob.num2)
        return true ;
    else
        return 0;

}
bool fraction_numbers :: operator <= (fraction_numbers ob)
{

    if(( double )num1/num2<=( double )ob.num1/ob.num2)
        return true;
    else
        return false;
}
bool fraction_numbers :: operator >= (fraction_numbers ob)
{

    if(( double )num1/num2>=( double )ob.num1/ob.num2)
        return true;
    else
        return false;
}
istream & operator >> (istream & input , fraction_numbers & ob)
{
    cout<<"please enter the nominator ";
    input>>ob.num1;
    cout<<"please enter the dominator  ";
    input>>ob.num2;
    ob.reduce_fraction();
    return input;
}
ostream & operator << (ostream & output , fraction_numbers  ob)
{
    if (ob.num2==0)
        output<<"error dominator can't be zero "<<endl;
    else if (ob.num1==0)
        output<<0<<endl;
    else if (ob.num2==ob.num1)
        output<<1<<endl;
    else
        output<<ob.num1<<'/'<<ob.num2;
    return output;
}
 fraction_numbers fraction_numbers ::operator+(fraction_numbers  ob)
{
    fraction_numbers t;
    t.num2 = num2*ob.num2;
    t.num1 = num1*ob.num2+ob.num1*num2;
    t.reduce_fraction();
    return t;
}

fraction_numbers fraction_numbers  ::operator-(fraction_numbers  ob)
{
    fraction_numbers t;
    t.num2 = num2*ob.num2;
    t.num1 = num1*ob.num2-ob.num1*num2;
    t.reduce_fraction();
    return t;
}

fraction_numbers fraction_numbers ::operator*(fraction_numbers  ob)
{
    fraction_numbers t;
    t.num2 = num2*ob.num2;
    t.num1 = num1*ob.num1;
    t.reduce_fraction();
    return t;
}

fraction_numbers fraction_numbers  ::operator/(fraction_numbers  ob)
{
    fraction_numbers t;
    t.num2 = num2*ob.num1;
    t.num1 = num1*ob.num2;
    t.reduce_fraction();
    return t;
}

int main()
{

    return 0;
}
