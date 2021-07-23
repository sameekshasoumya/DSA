/*

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

*/

vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> output(nums.size(), 1);
    int left = 1, right = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        output[i] *= left;
        left *= nums[i];
    }
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        output[i] *= right;
        right *= nums[i];
    }
    return output;
}