/*

You are given an array of k vectors, each vector is sorted in ascending order.
Merge all the vectors into one sorted sorted vector and return it.

*/

//BRUTE : TAKE AN EMPTY VECTOR(ANS), PUT ALL THE VECTOR ELEMENTS INTO IT AND THEN SORT THE ANS VECTOR TO GET THE DESIRED VECTOR --> O(NKlogNK)
//Since the total num of elements is NK.

vector<int> mergeKArrays(vector<vector<int>> arrays)
{
    vector<int> output;
    //push all elements into output O(NK)
    for (int i = 0; i < arrays.size(); i++)
    {
        for (int j = 0; j < arrays[i].size(); j++)
        {
            output.push_back(arrays[i][j]);
        }
    }
    //sort the output array O(NKlogNK)
    sort(output.begin(), output.end());
    return output;
}

//OPTIMIZED : MAINTAIN K POINTERS, ONE FOR EACH VECTOR. COMPARE THE ELEMENTS AT K POINTERS AND PUSH THE SMALLEST OF THOSE K ELEMENTS
//            INTO THE OUTPUT VECTOR (USE HEAP OF SIZE K). REPEAT TILL THE HEAP IS EMPTY.
//TIME --> O(NKlogK) , SPACE --> O(NK)

#include <bits/stdc++.h>

using namespace std;

vector<int> Merge(vector<vector<int>> &arr)
{
    vector<int> output;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    int k = arr.size();
    for (int i = 0; i < k; i++)
    {
        pq.push({arr[i][0], i, 0});
    }
    while (!pq.empty())
    {
        vector<int> top = pq.top();
        pq.pop();
        int element = top[0];
        int a_idx = top[1];
        int e_idx = top[2];
        output.push_back(element);
        if (e_idx + 1 < arr[a_idx].size())
        {
            pq.push({arr[a_idx][e_idx + 1], a_idx, e_idx + 1});
        }
    }
    return output;
}

int main()
{
    vector<vector<int>> v{{1, 2, 4}, {3, 10, 12}, {5, 6, 7, 8, 9}};
    vector<int> ans = Merge(v);
    for (auto i : ans)
        cout << i << " ";

    return 0;
}

MERGE TWO SROTED ARRAYS IN PLACE
    // //mycode
    // void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    // {
    //     int ptr1 = 0, ptr2 = 0;
    //     vector<int> temp;
    //     while (ptr1 < m && ptr2 < n)
    //     {
    //         if (nums1[ptr1] >= nums2[ptr2])
    //         {
    //             //temp.push_back(nums2[ptr2]);
    //             //ptr2++;
    //             temp.push_back(nums2[ptr2++]);
    //         }
    //         else
    //         {
    //             //temp.push_back(nums1[ptr1]);
    //             //ptr1++;
    //             temp.push_back(nums2[ptr1++]);
    //         }
    //     }
    //     while (ptr1 < m)
    //     {
    //         //temp.push_back(nums1[ptr1]);
    //         //ptr1++;
    //         temp.push_back(nums2[ptr1++]);
    //     }
    //     while (ptr2 < n)
    //     {
    //         //temp.push_back(nums2[ptr2]);
    //         //ptr2++;
    //         temp.push_back(nums2[ptr2++]);
    //     }
    //     for (int i = 0; i < (m + n); i++)
    //         nums1[i] = temp[i];
    // }

    // //best-code

    // void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    // {
    //     int ptr1 = m - 1, ptr2 = n - 1, ptr = m + n - 1;
    //     while (ptr1 >= 0 && ptr2 >= 0)
    //     {
    //         if (nums1[ptr1] > nums2[ptr2])
    //         {
    //             nums1[ptr--] = nums1[ptr1--];
    //         }
    //         else
    //         {
    //             nums1[ptr--] = nums2[ptr2--];
    //         }
    //     }
    //     while (ptr2 >= 0)
    //     {
    //         nums1[ptr--] = nums2[ptr2--];
    //     }
    // }