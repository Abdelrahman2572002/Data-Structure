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

#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;
int n;
void BiasedSort(vector<string>&stuff){
    string name;
    for(int i=0;i<n;i++){
        cin>>name;
        stuff.push_back(name);}
        int counter =0;
    for(int k =0;k<stuff.size();k++){
        if(stuff[k]=="Untitled"){
            swap(stuff[k],stuff[counter]);
            counter++;
        }
    }
sort(stuff.begin(),stuff.end());
}


// function to print the vector
void print(vector<string>&stuff){
    for(int j=0 ;j<stuff.size();j++){
        cout<<stuff[j]<<endl;
    }
}
int main(){
    cout<<"Enter the number of the songs to be added "<<endl;
    cin>>n;
    vector<string>names;

   // string names;
    cout<<"Enter Their Names of them: "<<endl;

    BiasedSort(names);
    cout<<"Songs after sorting : "<<endl;
    for(int j=0 ;j<names.size();j++){
        cout<<names[j]<<endl;
    }




    return 0;
}
