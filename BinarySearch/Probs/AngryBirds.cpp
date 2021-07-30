#include <bits/stdc++.h>
using namespace std;
bool ispossible(vector<int> &v, int mid, int birds)
{
    birds--;
    int curr = v[0];
    int last = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        curr = v[i];
        if (curr - last >= mid)
        {
            last = curr;
            birds--;
            if (birds == 0)
                return true;
        }
    }
    return false;
}

int code(vector<int> &v, int birds)
{
    int lo = 0;
    int hi = v[v.size() - 1] - v[0];
    while (hi >= lo)
    {
        int mid = lo + (hi - lo) / 2;
        if (ispossible(v, mid, birds) == true)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return lo - 1;
}

int main()
{
    int num, birds;
    cin >> num >> birds;
    vector<int> v(num);
    for (int i = 0; i < num; i++)
        cin >> v[i];
    cout << code(v, birds) << endl;
    return 0;
}