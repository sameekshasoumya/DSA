/*


You may recall that an array arr is a mountain array if and only if:
arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.


*/

//Time : O(N), Space : O(1)

int longestMountain(vector<int>& arr) {
        int max_peak = 0;
        for(int i=1;i<arr.size()-1;)
        {
            //checking if the element is peak element
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
            {
                int elements = 1;
                //temp counter for back slope
                int temp_i = i;
                //count the steep slope elements
                while(temp_i>0 && arr[temp_i]>arr[temp_i-1])
                {
                    temp_i--;
                    elements++;
                }
                //count the down slope elements
                while(i<(arr.size()-1) && arr[i]>arr[i+1])
                {
                    i++;
                    elements++;
                }
                max_peak = max(max_peak,elements);
            }
            //increment counter variable if it is not a peak element
            else
                i++;
        }
        return max_peak;
    }