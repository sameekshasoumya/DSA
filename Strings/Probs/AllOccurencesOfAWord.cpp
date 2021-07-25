/*

count number of occurences of a word inside a big paragraph

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> stringSearch(string big, string small)
{
    //store the occurrences in the result vector
    vector<int> result;
    int index = big.find(small);
    while (index != -1)
    {
        result.push_back(index);
        int next_occ = -1;
        next_occ = big.find(small, index + 1);
        index = next_occ;
    }
    return result;
}