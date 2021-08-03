/*

You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].

We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.

Return the largest number of chunks we can make to sort the array.

*/


int maxChunksToSorted(vector<int> &arr)
{
    int max_chunks = 0, max_so_far = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        max_so_far = max(max_so_far, arr[i]);
        if (max_so_far == i)
        {
            max_chunks++;
            max_so_far = -1;
        }
    }
    return max_chunks;
}