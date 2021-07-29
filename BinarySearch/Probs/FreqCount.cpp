/*

FIRST AND LAST OCCURENCE OF AN ELEMENT IN SORTED ARRAY

1. O(N) time, O(1) space approach --> one pass thru entire array
2. O(logN) time, O(1) space approac --> 1st Binary search to check the presence of target element and simultaneously store the
   index of the first occurence and 2nd Binary search performed (if the element is present) to obtain the last occurence of the element

FREQUENCY COUNT 

1. O(N) --> Single pass, keep count
2. Perform first and last occurence (2.) then calculate (last_occ - first_occ +1);

*/

vector<int> answer;

vector<int> searchRange(vector<int> &nums, int target)
{
    int hi = nums.size() - 1, idx;
    bool not_present = true;
    int lo = 0;
    while (hi >= lo)
    {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] > target)
            hi = mid - 1;
        else if (nums[mid] < target)
            lo = mid + 1;
        else
        {
            not_present = false;
            idx = mid;
            hi = mid - 1;
        }
    }
    if (not_present)
    {
        answer.push_back(-1);
        answer.push_back(-1);
        return answer;
    }
    answer.push_back(idx);
    lo = 0, hi = nums.size() - 1;
    while (hi >= lo)
    {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] <= target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    answer.push_back(lo - 1);
    return answer;
}

int countFreq(vector<int>&answer)
{
    return (answer[1]-answer[0])+1 ;
    //return upper_bound(answer.begin(),answer.end(),target) - lower_bound(answer.begin(),answer.end(),target) ; ---> STL One liner
}