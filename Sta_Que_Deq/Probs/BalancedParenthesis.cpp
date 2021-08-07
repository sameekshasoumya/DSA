#include <bits/stdc++.h>

using namespace std;

bool isvalid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else if (s[i] == ')' && !st.empty() && st.top() == '(')
            st.pop();
        else if (s[i] == ']' && !st.empty() && st.top() == '[')
            st.pop();
        else if (s[i] == '}' && !st.empty() && st.top() == '{')
            st.pop();
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
            return false;
    }
    if (st.size())
        return false;
    return true;
}

int main()
{
    cout << isvalid("((a+b))*[h}") << endl;
    cout << isvalid("([a+b])*{h*([i])}") << endl;
    cout << isvalid("(([a+b])*{h*([i])}") << endl;
    cout << isvalid("(({[[a+b])*{h*([i])}]]]") << endl;
    return 0;
}