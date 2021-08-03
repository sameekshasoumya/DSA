/*

Asked in FB,DES,MS,Adobe,Amazon and many tech giants

Q. Given an input stream of N integers. 
   The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.

*/

TODO : https://leetcode.com/problems/find-median-from-data-stream/

//Brute Force : keep taking input and add in vector, sort that vector and then find the median after each input --> N*NlogN

//Better : Maintain a sorted array/vector of elements so far and add the current input at its sorted place in the vector --> for each input
//N, it can take O(N) in worst case. So, overall complexity is N*N = O(N^2)

//The most optimized solution --> NlogN

#include <bits/stdc++.h>

using namespace std;

int main()
{
    //maxHeap for previous biggest int --> left side elements in descending order
    priority_queue<int> maxHeap;
    //minheap for next smallest int --> right side elements in ascending order
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int input;
    double median = 0;
    while (cin >> input)
    {
        /*
        Each min heap and max heap should have N elements if curr number of elements in stream is 2N
        Median in such case will be the average of top() of both the heaps
        or
        Either of MinHeap or MaxHeap can have N+1 elements and the remaining one will have N elements
        Median in such case will be the top() of the heap having N+1 elements
        */
        int s_min = minHeap.size();
        int s_max = maxHeap.size();
        if (median > (double)input)
        {
            //add input to left half max heap
            if (s_min > s_max)
            {
                maxHeap.push(input);
                int top_e1 = maxHeap.top();
                int top_e2 = minHeap.top();
                double ans = (top_e1 + top_e2) / 2.0;
                median = ans;
            }
            else if (s_min == s_max)
            {
                maxHeap.push(input);
                median = (double)maxHeap.top();
            }
            else
            {
                //s_min<s_max
                int top_ele = maxHeap.top();
                maxHeap.pop();
                minHeap.push(top_ele);
                maxHeap.push(input);
                int top_e1 = maxHeap.top();
                int top_e2 = minHeap.top();
                double ans = (top_e1 + top_e2) / 2.0;
                median = ans;
            }
        }
        else if (median == (double)input)
        {
            if (s_min >= s_max)
            {
                maxHeap.push(input);
            }
            else
            {
                minHeap.push(input);
            }
        }
        else
        {
            //median<input
            //add input to right half min heap
            if (s_min > s_max)
            {
                int top_ele = minHeap.top();
                minHeap.pop();
                maxHeap.push(top_ele);
                minHeap.push(input);
                int top_e1 = maxHeap.top();
                int top_e2 = minHeap.top();
                double ans = (top_e1 + top_e2) / 2.0;
                median = ans;
            }
            else if (s_min == s_max)
            {
                minHeap.push(input);
                median = (double)minHeap.top();
            }
            else
            {
                //s_min<s_max
                minHeap.push(input);
                int top_e1 = maxHeap.top();
                int top_e2 = minHeap.top();
                double ans = (top_e1 + top_e2) / 2.0;
                median = ans;
            }
        }
        cout << median << endl;
    }
    return 0;
}