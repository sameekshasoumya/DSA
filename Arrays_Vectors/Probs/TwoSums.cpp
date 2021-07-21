/*
VARIATION 1:

Given an array of integers nums and an integer target, return the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

*/

//BRUTE FORCE : O(1) space , time O(N^2) --> We consider each and every pair (i.e N^(N+1)/2 ~= N^2) and check whether or not they add up to the target sum

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> result;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                result.push_back(nums[i]);
                result.push_back(nums[j]);
                return result;
            }
        }
    }
    return result;
}

//SORTING + TWO POINTER : O(NlogN) + O(N) = O(NlogN) time , space O(1)
//BINARY SEARCH : O(NlogN --> sort the array/vector, for each index i, binary search for target-nums[i] on the remaining array

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> result;
    //stl sort --> O(NlogN)
    sort(nums.begin(), nums.end());
    int ptr_front = 0;
    int ptr_back = nums.size() - 1;

    //roughly takes O(N)
    while (ptr_front < ptr_back)
    {
        if (nums[ptr_front] + nums[ptr_back] == target)
        {
            result.push_back(nums[ptr_front]);
            result.push_back(nums[ptr_back]);
            return result;
        }
        else if (nums[ptr_front] + nums[ptr_back] < target)
        {
            //add something larger, so move the front pointer ++
            ptr_front++;
        }
        else
        {
            //as the sum is larger, we need to reduce the number, so move the back pointer --
            ptr_back--;
        }
    }
    return result;
}

//OPTIMIZED : HASHING --> O(N) time O(N) space

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> hash;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++)
    {
        if (hash.find(target - nums[i]) != hash.end())
        {
            result.push_back(target - nums[i]);
            result.push_back(nums[i]);
            return result;
        }
        else
            ++hash[nums[i]];
    }
    return result;
}



/*
VARIATION 2:

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

*/

//BRUTE FORCE : O(1) space , time O(N^2) --> We consider each and every pair (i.e N^(N+1)/2 ~= N^2) and check whether or not they add up to the target sum

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> result;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
    return result;
}

//SORTING CANNOT BE APPLIED AS WE NEED TO RETAIN THE INDEXING

//OPTIMIZED : HASHING --> O(N) time O(N) space

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> hash;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++)
    {
        if (hash.find(target - nums[i]) != hash.end())
        {
            result.push_back(hash[target - nums[i]]);
            result.push_back(i);
            return result;
        }
        else
            hash[nums[i]]=i;
    }
    return result;
}