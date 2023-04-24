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

#include "fraction_calculator.h"
#include "fraction.h"
using namespace std;

fraction_calculator::fraction_calculator()
{

}

void fraction_calculator::begining(){
    cout<<"welcome to calculator  "<<endl;
    fraction_numbers t1,t2;
    cout<<" please Enter your first number ";
    cin>>t1;
    cout<<" please Enter your second number ";
    cin>>t2;
    int a;
    while(true){
        cout<<"please choose 1-Add\n"<<
        "2-subtract"<<endl
        <<"3-multiplication"<<endl
        <<"4-divide"<<endl
        <<"5-exit"<<endl
        <<"choose one ";
        cin>>a;
        if(a==1){
                fraction_numbers t3(t1+t2);

                cout<<"t1+t2= "<<t3<<endl;

        }
        else if(a==2){

                fraction_numbers t3(t1-t2);
                cout<<"t1-t2= "<<t3<<endl;

        }
        else if(a==3){
                fraction_numbers t3(t1*t2);

                cout<<"t1*t2= "<<t3<<endl;

        }
         else if(a==4){
                fraction_numbers t3(t1/t2);
                cout<<"t1/t2= "<<t3<<endl;

        }
        else if(a==5){
              cout<<"salam"<<endl;
                break;

        }
    }
}
