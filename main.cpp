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
void RecPermute(string soFar, string rest)
{
    set<string> names;
if (rest == "") // No more characters
cout << soFar << endl; // Print the word
else // Still more chars
// For each remaining char
for (int i = 0; i < rest.length(); i++) {
string next = soFar + rest[i]; // Glue next char
string remaining = rest.substr(0, i)+ rest.substr(i+1);
int length= names.size();
names.insert(next);
if(names.size()>length)
RecPermute(next, remaining);
}
}
// "wrapper" function
void ListPermutations(string s) {
RecPermute("", s);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ListPermutations("makka");
    return 0;
}
