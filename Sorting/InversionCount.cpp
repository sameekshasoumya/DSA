/*

Count the total number of inversions in an array, i.e. for an integer array A, find the total number of pairs such that : ( A[i]>A[j] && i<j )

*/

//Brute Force Approach --> O(N^2) time, O(1) space
int totalInversions(vector<int> &v)
{
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i] > v[j])
                ++count;
        }
    }
    return count;
}


