// KADANE'S ALGO : MAXIMUM SUBARRAY SUM / Largest Sum Contiguous Subarray

/*

Find the sum of contiguous subarray within a one-dimensional array of numbers that has the largest sum

*/

//FOLLOW UP : To print the subarray with the maximum sum, we maintain indices whenever we get the maximum sum.

//BRUTE FORCE : O(N^2)
//Considering each and every subset

int maxSubArraySum(vector<int> arr)
{
    int n = arr.size();
    int max_sum = 0;
    for (int i = 0; i < n; i++)
    {
        int temp_sum = 0;
        for(int j=i+1;j<n;j++)
        {
            temp_sum = max(temp_sum+arr[j], arr[j]);
            max_sum = max(max_sum, temp_sum);
        }
    }

    return max_sum;
}

//O(N) time, O(1) space approach

//geeks
int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

//my

int maxSubArraySum(vector<int> arr)
{
    int n = arr.size();
    int max_sum = 0;
    int curr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum = max(curr_sum + arr[i], arr[i]);
        max_sum = max(max_sum, curr_sum);
    }

    return max_sum;
}