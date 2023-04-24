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

#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED
#include <iostream>
using namespace std;
class fraction_numbers
{
    public:
        fraction_numbers();
        fraction_numbers (int n1,int n2);
        fraction_numbers (const fraction_numbers &ob);
        int common_divisor(int n1,int n2);
        void reduce_fraction();



        bool operator <= (fraction_numbers ob);
        bool operator >= (fraction_numbers ob);
        bool operator == (fraction_numbers ob);
        bool operator != (fraction_numbers ob);
        bool operator > (fraction_numbers ob);
         bool operator < (fraction_numbers ob);
        friend istream & operator >> (istream & input , fraction_numbers & ob);
        friend ostream & operator << (ostream & output , fraction_numbers  ob);
        fraction_numbers operator + (fraction_numbers  ob);
        fraction_numbers operator - (fraction_numbers  ob);
        fraction_numbers operator * (fraction_numbers  ob);
        fraction_numbers operator / (fraction_numbers  ob);
        protected:
        int num1,num2;
};



#endif // FRACTION_H_INCLUDED
