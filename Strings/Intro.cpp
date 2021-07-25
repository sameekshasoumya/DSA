/**/


#include <bits/stdc++.h>
using namespace std;

int main()
{
    //string uses a dynamic array thus very flexible over character array
    string s;
    //string str("Hello World"); same as string str = "Hello World";
    cin>>s;
    //this by defualt assumes that string terminates on a new line
    getline(cin,s);
    //thrid arg is delimiter...string read only stops when in encounters the given delimiter
    getline(cin,s,'.');
    return 0;
}
