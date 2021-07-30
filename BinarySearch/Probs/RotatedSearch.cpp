/*

Array is sorted then rotated about an element. Find whether the target is present in the given array or not.

*/

//FIND THE POINT OF ROTATION!!

//BRUTE : O(N) --> Single pass
//MODIFIED BINARY SEARCH :
1. CODE 1 : single BS loop

int search(vector<int> &nums, int target)
{
    int lo = 0;
    int hi = nums.size() - 1;
    while (hi >= lo)
    {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] >= nums[lo])
        {
            if (nums[mid] > target && nums[lo] <= target)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        else if (nums[mid] <= nums[hi])
        {
            if (nums[mid] < target && nums[hi] >= target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
    }
    return -1;
}

2. CODE 2

int pivot(vector<int> &nums)
{
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi)
    {
        int mid = lo + ((hi - lo) / 2);
        if (nums[mid] > nums[hi])
        {
            lo = mid + 1;
        }
        else
            hi = mid;
    }
    return lo - 1;
}

int binSearch(vector<int> &nums, int lo, int hi, int key)
{
    int idx = -1;
    while (lo <= hi)
    {
        int mid = lo + ((hi - lo) / 2);
        if (nums[mid] == key)
        {
            idx = mid;
            break;
        }
        else if (nums[mid] > key)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return idx;
}

int search(vector<int> &nums, int target)
{
    int p = pivot(nums);
    int x = binSearch(nums, 0, p, target);
    if (x != -1)
        return x;
    else
    {
        x = binSearch(nums, p + 1, nums.size() - 1, target);
        if (x != -1)
            return x;
    }
    return -1;
}