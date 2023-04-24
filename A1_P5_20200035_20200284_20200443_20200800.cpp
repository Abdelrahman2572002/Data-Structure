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


#include <iostream>
using namespace std ;
#include <vector>

class StudentName
{
private:
    string name ;
public:
    StudentName(string n) {
        int space = 0, pos = 0;
        for (int i = 0; i < n.length(); ++i) {
            if (n[i] == ' ') {
                ++space;
                pos = i;
            }



        }
        if (space < 2) {
            if (space == 0) {
                name = n + " " + n + " " + n;

            } else {
                name = n + n.substr(pos);
            }

        } else {
            name = n;
        }
    }



    void print ()
    {
        vector<string>ls ; //list of name
        string s="";
        int space=0 ;
        for(int i=0;i<name.length();i++)
        {
            if(name[i]==' ')
            {
                ls.push_back(s);
                s="";
                space++;
            }
            else if(i==name.length()-1)
            {
                s+=name[i];
                ls.push_back(s);
            }
            else
            {
                s+=name[i];

            }
        }
        for(auto j:ls)
        {
            cout<<j<<endl;
        }

    }
    bool replace(int a,int b)
    {
        vector<string>ls ; //list of name
        string s="";
        int space=0 ;
        for(int i=0;i<name.length();i++)
        {
            if(name[i]==' ')
            {
                ls.push_back(s);
                s="";
                space++;
            }
            else if(i==name.length()-1)
            {
                s+=name[i];
                ls.push_back(s);
            }
            else
            {
                s+=name[i];

            }
        }
        if(a>ls.size()||b>ls.size())
        {
            cout<<"false"<<endl;
            return false ;
        }
        else
        {
            swap(ls[a-1],ls[b-1]);
            for(auto i:ls)
            {
                cout<<i<<" ";
            }
            cout<<endl;

            return true;

        }
    }

};

int main() {
    StudentName  test_case1 ("Mohamed Refaat Rohamed");
    test_case1.replace(1,2);

    StudentName  test_case2 ("Adel Tarek Mouneer");
    test_case2.replace(3,1);

    StudentName  test_case3 ("Ahmed salman");
    test_case3.replace(1,4);

    StudentName  test_case4 ("Abelrahman Ramdan Abelrahman");
    test_case4.replace(2,1);

    StudentName  test_case5 ("Hussien Mostafa Ahmed");
    test_case5.replace(3,2);





    return 0;
}
