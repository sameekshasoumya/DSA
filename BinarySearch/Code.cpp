//The search space needs to be monotonic - either non-increasing or non-decreasing
//Sometimes it might be tricky to figure out the search space, as it is the main logic part

//FALSE Binary Search can be applied only on sorted arrays. --> TRUE Binary Search is applied on Monotonic Searchspaces, not just arrays.
//We divide the problem into smaller problem, hence its D&C.
//SPACE COMPLEXITY FOR BS IS O(LOGN) IN REC AND O(1) IN ITERATIVE
//FALSE Ternary Search is more efficient than binary search in terms of number of worst case comparisons.


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


/*

What you knowThese are questions you got right on the first try.
Binary Search is a ________________ algorithm.


What you should review
Space Complexity of simple binary search algorithms is _______________
Ternary Search is more efficient than binary search in terms of number of worst case comparisons.
Binary Search can be applied only on sorted arrays.

*/