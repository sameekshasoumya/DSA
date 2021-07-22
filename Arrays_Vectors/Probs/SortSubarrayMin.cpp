//O(NlogN) time ,  O(N) space

int findUnsortedSubarray(vector<int> &nums)
{
    vector<int> temp_nums;
    for (auto ele : nums)
    {
        temp_nums.push_back(ele);
    }
    sort(temp_nums.begin(), temp_nums.end());
    int left = -1, right = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (temp_nums[i] != nums[i])
        {
            left = i;
            break;
        }
    }
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (temp_nums[i] != nums[i])
        {
            right = i;
            break;
        }
    }
    if (right == left)
        return 0;
    return (right - left + 1);
}

//Cleaner O(NlogN) code

int findUnsortedSubarray(vector<int> &nums)
{
    vector<int> temp(nums);
    sort(temp.begin(), temp.end());
    int left = 0;
    while (left < nums.size() && nums[left] == temp[left])
        left++;
    int right = nums.size() - 1;
    while (right >= 0 && nums[right] == temp[right])
        right--;
    if (left == nums.size())
        return 0;
    return (right - left + 1);
}
