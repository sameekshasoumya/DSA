//lol code
#include <bits/stdc++.h>
using namespace std;

vector<char> FindFirstNonRepeatingCharacter(string S)
{
    int N = S.size();
    vector<char> res(N);
    queue<char> q;
    unordered_map<char, int> hash;
    hash[S[0]]++;
    q.push(S[0]);
    res[0] = S[0];
    for (int i = 1; i < N; i++)
    {
        hash[S[i]]++;
        if (hash[S[i]] == 1)
            q.push(S[i]);
        if (!q.empty())
        {
            char top = q.front();
            while (!q.empty())
            {
                if (hash[top] == 1)
                    break;
                q.pop();
                top = q.front();
            }
            if (q.empty())
                res[i] = '0';
            else
                res[i] = q.front();
        }
        else
            res[i] = '0';
    }
    return res;
}