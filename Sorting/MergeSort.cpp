/*

Based on the Divide and conquer algorithm

More like a depth first algo

*/
#include <bits/stdc++.h>
using namespace std;

//merger : to merge the array into sorted form
void merge(vector<int> &array, int start, int end)
{
    //temp bucket to store sorted array
    vector<int> temp;
    //divide the array about mid
    int mid = start + (end - start) / 2;
    int i = start;
    int j = mid + 1;
    int k = 0;
    //compare then store
    while (i <= mid && j <= end)
    {
        if (array[i] >= array[j])
        {
            temp.push_back(array[j++]);
        }
        else
        {
            temp.push_back(array[i++]);
        }
    }
    //if element from 1st half remains, then push it
    while (i <= mid)
        temp.push_back(array[i++]);
    //if element from 2nd half remains, then push it
    while (j <= end)
        temp.push_back(array[j++]);
    //overwrite the sorted aaray to original one 
    for (int idx = start; idx <= end; idx++)
        array[idx] = temp[k++];
}

//divide the array recursively then pass into merge function
void mergesort(vector<int> &array, int start, int end)
{
    //base case
    if (start >= end)
        return;
    //divide the array about mid into two halves
    int mid = start + (end - start) / 2;
    //mergesort on 1st half
    mergesort(array, start, mid);
    //mergesort on 2nd half
    mergesort(array, mid + 1, end);
    //then merge the array so obtained
    merge(array, start, end);
}

int main()
{
    //taking input
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (auto i : v)
        cout << i << ",";
    cout << endl;
    mergesort(v, 0, n - 1);
    for (auto i : v)
        cout << i << ",";
    cout << endl;
}