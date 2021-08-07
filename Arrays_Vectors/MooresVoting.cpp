/*

Boyer-Moore Voting Algorithm

Finds the majority element in an array, i.e. an element which has occured more than arr.size/2 times (Hence, there is atmost one such element)

*/

//O(N^2) time + O(1) space : Run nested loop, maintain a count of the current element and update the max count. If at any point
//max count exceeds N/2, return the curr element else continue. If we come out of the loops, return -1 as no such element exists.
int majorityElement(int a[], int size)
{
    int count = 0;
    int max_count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (a[i] == a[j])
                ++count;
        }
        max_count = max(max_count, count);
        if (max_count > size / 2)
            return a[i];
        count = 0;
    }
    return -1;
}

//O(N) space+time - Hashing
int majorityElement(int a[], int size)
{
    unordered_map<int, int> hash;
    for (int i = 0; i < size; i++)
    {
        hash[a[i]]++;
        if (hash[a[i]] > (size / 2))
            return a[i];
    }
    return -1;
}

//Moore's Voting algorithm
int majorityElement(vector<int> &nums)
{
    int count = 0;
    int maj_index = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[maj_index] == nums[i])
            count++;
        else
            count--;
        if (!count)
        {
            count = 1;
            maj_index = i;
        }
    }
    //check to be sure if the obtained majority element is actually majority element
    count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == nums[maj_index])
            count++;
    }
    if (count > (nums.size() / 2))
        return nums[maj_index];
    return -1;
}