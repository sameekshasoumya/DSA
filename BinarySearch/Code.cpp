int binarySearch(vector<int>&arr,int hi,int lo,int key)
{
    while(hi>=lo)
    {
        int mid = lo + (hi-lo)/2 ;
        if(arr[mid]==key)
        return mid;
        else if(arr[mid]>key)
        hi = mid-1;
        else
        lo = mid+1;
    }
    return -1;
}