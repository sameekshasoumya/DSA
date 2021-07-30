class Solution
{
public:
    //Function to find minimum number of pages.
    bool ispossible(int arr[], int n, int mid, int m)
    {
        int sum = 0, stu = 1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > mid)
                return false;
            else if ((arr[i] + sum) > mid)
            {
                stu++;
                sum = arr[i];
                if (stu > m)
                    return false;
            }
            else
                sum += arr[i];
        }
        return true;
    }
    int findPages(int arr[], int n, int m)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];
        int hi = sum;
        int lo = 0;
        while (hi >= lo)
        {
            int mid = lo + (hi - lo) / 2;
            if (ispossible(arr, n, mid, m))
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return hi + 1;
    }
};