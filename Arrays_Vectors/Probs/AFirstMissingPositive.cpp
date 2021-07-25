/*

Amazon , Leet Hard

Given an unsorted integer array nums, find the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.

*/

//O(N) time O(1) space

int firstMissingPositive(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        //nums[i] will be swapped to its correct place only if it lies between 1 and nums.size()+1
        //nums[i]!=nums[nums[i]-1] is vvi condition
        if (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1])
        {
            swap(nums[i], nums[nums[i] - 1]);
            i--;
        }
    }
    int missing_num = 1;
    while (missing_num <= nums.size() && nums[missing_num - 1] == missing_num)
        missing_num++;
    return missing_num;
}