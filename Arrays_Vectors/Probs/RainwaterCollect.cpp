/*

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

*/

//O(N^2)
//For every element, find its max on right side and max on left side. Then take minimum of maximum on both
//the sides and to get the water content, subtract the height of current bar.

//O(N)
//We saved the nesting by pre computing the max array for both the sides
int trap(vector<int> &height)
{
    int total = 0;
    vector<int> right_max(height.size()), left_max(height.size());
    int max_right = 0, max_left = 0;
    for (int i = 0; i < height.size(); i++)
    {
        max_left = max(max_left, height[i]);
        max_right = max(max_right, height[height.size() - i - 1]);
        left_max[i] = max_left;
        right_max[height.size() - i - 1] = max_right;
    }
    for (int i = 0; i < height.size(); i++)
    {
        total += (min(right_max[i], left_max[i]) - height[i]);
    }
    return total;
}