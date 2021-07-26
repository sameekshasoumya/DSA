//see the tokenisation thru sstream,strtok and strtok code


#include <bits/stdc++.h>

using namespace std;

//char c is the delimiter
vector<string> strtoken(string s, char c)
{
    vector<string> output;
    string temp = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == c)
        {
            output.push_back(temp);
            temp = "";
        }
        else
            temp += s[i];
    }
    return output;
}

int main()
{
    string s = "Hey How are?  ?  You free today na?  ooops..... okay?";
    vector<string> print = strtoken(s, '?');
    for (auto x : print)
        cout << x << " , ";
    cout << endl;
    return 0;
}