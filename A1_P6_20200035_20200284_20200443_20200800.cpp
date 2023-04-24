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
class PhoneDirectory
{
private:
    string first_name;
    string last_name;
    string phone_number;
public:
    PhoneDirectory()
    {
        first_name="";
        last_name="";
        phone_number="0";

    }

    PhoneDirectory(string a ,string b ,string c)
    {
        first_name=a;
        last_name=b;
        phone_number=c;


    }
   void  setfirst_name (string a)
    {
        first_name=a;

    }
    void setlast_name (string b)
    {
        last_name=b;
    }
    void setphone_number (string c)
    {
        phone_number=c;
    }

    string getfirst_name ()
    {
        return first_name;
    }

    string getlast_name ()
    {
        return last_name;

    }

    string getphone_number ()
    {
        return phone_number ;
    }



};
class Node
{
    friend PhoneDirectory ;
public:
    PhoneDirectory data ;

    Node *next ;
    Node* previous;
    Node operator=(Node var)
    {
        data.setfirst_name((var).data.getfirst_name());
        data.setlast_name((var).data.getlast_name());
        data.setphone_number((var).data.getphone_number());
        return *this;
    }



};
class linked
{
public:
    Node*head;




    linked()
    {
        head=NULL;
    }


    bool isempty ()
    {
        if(head==NULL)
        {
            return true;
        }
        else {
            return false;
        }
    }
    void insert_first(string first,string last ,string phone)         //1_inseart
    {
        Node *newnode=new Node ;
        newnode->data.setfirst_name(first);
        newnode->data.setlast_name(last);
        newnode->data.setphone_number(phone);


        if( isempty() )
        {
            newnode->next=NULL;
            head=newnode;
        } else{


            newnode->next=head;
            head=newnode;

        }

    }

    void Delete_entity(string item) //4. Delete an entry from the directory
    {
        if(isempty())
        {
            cout<<"list is empty"<<endl;
        }
        if(head->data.getfirst_name()==item)
        {
            Node*delptr=head;
            head=head->next;
            delete delptr;


        }
        else
        {
            Node *prev=NULL;
            Node*delptr=head;
            while (delptr->data.getfirst_name()!=item)
            {
                prev=delptr;
                delptr=delptr->next;
            }
            prev->next=delptr->next;
            delete delptr ;

        }
    }
    void look_up_name(string item) // 3- look up name
    {


        Node *temp = head;
        int pos=0;
        while (temp!=NULL )
        {
            if(temp->data.getfirst_name()==item)
            {
                cout<<"Entry Data:"<<endl;
                cout<< pos+1<<" ";
                cout<< temp->data.getfirst_name() << " " << temp->data.getlast_name() << " "<<temp->data.getphone_number()<<endl;
                break;
            }
            temp=temp->next;
            pos=pos+1;

        }
        if(pos==0)
        {
            cout<<-1<<endl;
        }

    }
    void look_up_phone(string number)    //2- look up number
    {

        Node *temp = head;
        int pos=0;
        while (temp!=NULL )
        {
            if(temp->data.getphone_number()==number)
            {
                cout<<"Entry Data:"<<endl;
                cout<< pos+1<<" ";
                cout<< temp->data.getfirst_name() << " " << temp->data.getlast_name() << " "<<temp->data.getphone_number()<<endl;
                break;
            }
            temp=temp->next;
            pos=pos+1;

        }
        if(pos==0)
        {
            cout<<-1<<endl;
        }

    }



    void display() //5- All entries in phone directory
    {


           Node *temp =head ;
           int count =1;
            while (temp!=NULL)
            {
                cout<<count <<") "<<temp->data.getfirst_name()<<" ";
                cout<<temp->data.getlast_name()<<" ";
                cout<<temp->data.getphone_number()<<endl;
                temp=temp->next;
                count++;
            }
        }



    void bubbleSort()     //sorted
    {
        Node *i , *j, temp;
        for (i=head;i->next!=NULL;i=i->next) 
        {
            for(j=i->next;j!=NULL;j=j->next)
            {
                if(i->data.getfirst_name()[0]>j->data.getfirst_name()[0])
                {
                    cout << i->data.getfirst_name()[0] << " in if " << j->data.getfirst_name()[0] << endl;

                    temp=*i;
                    *i = *j;
                    *j = temp;
                }
                else
                    cout << i->data.getfirst_name()[0] << " not in if " << j->data.getfirst_name()[0] << endl;
            }

        }
    }
    

};






int main() {
    Node a ;
    PhoneDirectory  d ;
    linked ls ;

    int count ,i;
        while (1)          // menu of phone directory
        {
            cout<<"Choose one of the following options"<<endl;
            cout<<"1. Add an entry to the directory"<<endl;
            cout<<"2. Look up a phone number"<<endl;
            cout<<"3. Look up by first name"<<endl;
            cout<<"4. Delete an entry from the directory"<<endl;
            cout<<"5. List All entries in phone directory"<<endl;
            cout<<"6. Exit form this program"<<endl;

            cin>>count;
            if(count==1)
            {
                string first_n ,last_n;
                string phone_n;
                cout<<"Enter Your First Name:"<<endl;
                cin>>first_n;
                cout<<"Enter Your Last Name:"<<endl;
                cin>>last_n;
                cout<<"Enter Your Phone Number:"<<endl;
                cin>>phone_n;
                ls.insert_first(first_n,last_n,phone_n);
                ls.bubbleSort();
            }
            
            if (count==2)
            {
                string phone ;
                cout<<"Enter Phone Number:"<<endl;
                cin>>phone;
                // cout<<"The Phone Number is in Position : ";
                ls.look_up_phone(phone);


            }
            if(count==3)
            {
                string first_n;
                cout<<"Enter This first Name you want to search it"<<endl;
                cin>>first_n;
                // cout<<"The first Name is in position : ";
                ls.look_up_name(first_n);
            }
            if(count==4)
            {
                string first_n;
                cout<<"Enter this first Name:"<<endl;
                cin>>first_n;
                ls.Delete_entity(first_n);

            }
            if(count==5)
            {
                cout<<"All entries in phone directory"<<endl;
                ls.display();
            }

            if(count==6)
            {

                cout<<"Exit ";
                exit(6);
            }



        }



    return 0;
}
