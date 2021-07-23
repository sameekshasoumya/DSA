/*

Minimum swaps to make the array sorted - GOOGLE + AMAZON

*/

//Function to find the minimum number of swaps required to sort the array.

/*
    nums------- 2 8 5 4
    old_index-- 0 1 2 3
    sort_index- 0 3 2 1
    
    after sorting
    2 4 5 8
    0 1 2 3
    */
int minSwaps(vector<int> &nums)
{
    int n = nums.size();
    int answer = 0;
    pair<int, int> idx[n];
    for (int i = 0; i < n; i++)
    {
        idx[i].first = nums[i];
        idx[i].second = i;
    }
    vector<bool> visited(n, false);
    sort(idx, idx + n);
    for (int i = 0; i < n; i++)
    {
        if (!(visited[i] == true || idx[i].second == i))
        {
            int curr_node = i;
            int cycle = 0;
            while (visited[curr_node] == false)
            {
                visited[curr_node] = true;
                curr_node = idx[curr_node].second;
                cycle++;
            }
            answer += (cycle - 1);
        }
    }
    return answer;
}