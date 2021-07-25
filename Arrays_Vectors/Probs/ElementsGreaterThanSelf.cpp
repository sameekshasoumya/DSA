/*

Noble integer

Given an integer array A, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p.

*/

//Brute Force : O(N^2)
//Iterate through every element in the loop and count all the elements in the array greater than it
int Solution::solve(vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < A.size(); j++)
        {
            if (A[j] > A[i])
                ++count;
        }
        if (count == A[i])
            return 1;
    }
    return -1;
}

//Better Solution : O(NlogN) + O(N) ~= O(NlogN) time + O(1) space
int Solution::solve(vector<int> &A)
{
    // vector<int> greater_than(A.size());
    sort(A.begin(), A.end());
    for (int i = 0; i < A.size(); i++)
    {
        // int last_occ = i;
        // int lo=0;
        // int hi=A.size()-1;
        // while(hi >= lo)
        // {
        //     int mid = lo + (hi-lo)/2;
        //     if(A[mid] <= A[i])
        //     lo = mid + 1;
        //     else
        //     hi = mid - 1;
        // }
        // if(lo>0)
        // last_occ = lo-1;

        //skips the duplicate elements as they dont matter for count
        if (i < A.size() - 1 && A[i + 1] == A[i])
            continue;
        if (A[i] == A.size() - i - 1)
            return 1;
    }
    // for(int i=0;i<A.size();i++)
    // {
    //     if(A[i]==greater_than[i])
    //     return 1;
    // }
    return -1;
}

//Optimised Solution : O(N) time + O(N) space