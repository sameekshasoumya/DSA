/*

Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Try in O(N) time

*/

//Intuitve --> UPDATE + SORTING : O(NlogN) time + O(1) space

vector<int> sortedSquares(vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        A[i] *= A[i];
    }
    sort(A.begin(), A.end());
    return A;
}

//Optimized --> UPDATE + SLIDING WINDOW/TWO PTR : O(N) time + O(N) space
vector<int> sortedSquares(vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
        A[i] *= A[i];
    vector<int> output(A.size());

    //main logic : sliding window
    int ptr_front = 0;
    int ptr_end = A.size() - 1;
    int ptr_place = A.size() - 1;
    while (ptr_place >= 0 && ptr_front <= ptr_end)
    {
        if (A[ptr_front] >= A[ptr_end])
        {
            output[ptr_place] = A[ptr_front];
            ptr_place--;
            ptr_front++;
        }
        else
        {
            output[ptr_place] = A[ptr_end];
            ptr_end--;
            ptr_place--;
        }
    }

    return output;
}

//Cleaner code for optimized approach

vector<int> sortedSquares(vector<int> &A)
{
    vector<int> output(A.size());
    //main logic : sliding window
    int ptr_front = 0;
    int ptr_end = A.size() - 1;
    int ptr_place = A.size() - 1;
    while (ptr_place >= 0 && ptr_front <= ptr_end)
    {
        //no need to do the squaring before, just compare the absolute values --> saves one loop iteration

        //increment front as well as decrement end in bracket itself : use post incrementor
        if (abs(A[ptr_front]) >= abs(A[ptr_end]))
            output[ptr_place--] = A[ptr_front] * A[ptr_front++];
        else
            output[ptr_place--] = A[ptr_end] * A[ptr_end--];
    }
    return output;
}