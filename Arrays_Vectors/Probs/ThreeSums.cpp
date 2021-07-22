/*
VARIATION 1:

Given an array of integers nums and an integer target, return triplet of numbers such that they add up to target.

Ascending order.

*/

//BRUTE FORCE : O(N^3) --> considering each triplet
vector<vector<int>> threeSum(vector<int> &nums, int target)
{
    vector<vector<int>> result;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                if (nums[i] + nums[j] + nums[k] == target)
                {
                    result.push_back({nums[i],nums[j]nums[k]});
                    return result;
                }
            }
        }
    }
    return result;
}

//HASHMAP TECHNIQUE : O(N^2) time + O(N) space --> space overhead
vector<vector<int>> threeSum(vector<int> &nums, int target)
{
    vector<vector<int>> result;
    for (int i = 0; i < nums.size(); i++)
    {
        int curr_sum = target - nums[i];
        unordered_map<int,int> hash;
        for(int j=i+1;j<nums.size();j++)
        {
            //find or lookup in hashmap takes O(1) time
            if(hash.find(target-nums[j])!=hash.end())
            {
                result.push_back({nums[i],curr_sum-nums[j],nums[j]});
            }
            else
            ++hash[nums[i]];
        }
    }
    return result;
}

//SORTING + TWO POINTER : O(N^2) time + O(1) space --> MOST OPTIMIZED
vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 3)
            return result;
        set<vector<int>> temp_result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            int curr_sum = 0 - nums[i];
            int ptr_front = i + 1;
            int ptr_back = nums.size() - 1;
            while(ptr_front < ptr_back)
            {
                if(nums[ptr_back] + nums[ptr_front] == curr_sum){
                    temp_result.insert({nums[i],nums[ptr_front],nums[ptr_back]});
                    ptr_front++;
                    ptr_back--;
                }
                else if(nums[ptr_back] + nums[ptr_front] > curr_sum)
                    ptr_back--;
                else
                    ptr_front++;
            }
        }
        for(auto x : temp_result)
        {
            result.push_back(x);
        }
        return result;
    }
