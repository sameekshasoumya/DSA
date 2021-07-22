/*

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

*/

//SORTING + IMPLEMENTATION : O(NlogN + N) ~= O(NlogN)

/*
    
    100 , 4 , 200 , 1 , 3 , 2
    
    1 , 2 , 3 , 4 , 100 , 200
    
     
    i          1 2 3 4
    temp_len   1 2 3 4    
    
    */
int longestConsecutive(vector<int> &nums)
{
    if (nums.size() == 0 || nums.size() == 1)
        return nums.size();
    sort(nums.begin(), nums.end());
    int longest_cons_seq = 0;
    for (int i = 1; i < nums.size();)
    {
        int temp_len = 1;
        if (nums[i] - nums[i - 1] == 1)
        {
            while (i <= (nums.size() - 1) && nums[i] - nums[i - 1] == 1)
            {
                i++;
                temp_len++;
                //resolve duplicate elements
                while (i <= (nums.size() - 1) && nums[i] - nums[i - 1] == 0)
                    i++;
            }
        }
        else
            i++;
        longest_cons_seq = max(longest_cons_seq, temp_len);
    }
    return longest_cons_seq;
}

//WHOOOOOPS A DIRTY CODE BY MEEEEEEEEEEEE......ignoreeeeeeeeeeeeeeee
int longestConsecutive(vector<int> &nums)
{
    unordered_map<int, int> hash;
    int longest_cons_seq = 0;
    for (auto i : nums)
    {
        ++hash[i];
    }
    for (int i = 0; i < nums.size(); i++)
    {
        int temp_len = 1;
        if (hash.find(nums[i] - 1) == hash.end())
        {
            int curr = nums[i];
            while (hash.find(curr + 1) != hash.end())
            {
                temp_len++;
                curr += 1;
            }
        }
        longest_cons_seq = max(longest_cons_seq, temp_len);
    }
    return longest_cons_seq;
}

//O(N) space + O(N) time approach

int longestConsecutive(vector<int> &nums)
{
    int longest_cons_seq = 0;
    //hash table for lookup
    unordered_set<int> hash;
    for (auto ele : nums)
        hash.insert(ele);
    for (auto look : hash)
    {
        if (hash.find(look - 1) == hash.end())
        {
            //means this can be the beginning element of the largest band
            int temp_len = 1;
            int curr_num = look + 1;
            //search for all its consecutive elements present in the nums array in a go
            while (hash.find(curr_num) != hash.end())
            {
                temp_len++;
                curr_num++;
            }
            longest_cons_seq = max(longest_cons_seq, temp_len);
        }
    }
    return longest_cons_seq;
}