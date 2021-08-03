//FINDING NEAREST K CARS

//HEAP BUILDING TAKES O(N) AND NOT O(NLOGN) AS 
/*
The main idea is that in the build_heap algorithm the actual heapify cost is not O(log n)for all elements.

When heapify is called, the running time depends on how far an element might move down in the tree before the process terminates.
In other words, it depends on the height of the element in the heap. 
In the worst case, the element might go down all the way to the leaf level.

*/

APPROACHES : 
1. BRUTE FORCE : SORT THE WHOLE VECTOR BASED ON THE EUCLIDEAN DISTANCE --> O(NlogN)
2. HEAP : PUSH ALL THE EUCLIDEAN DIST INTO HEAP AND POP OUT K ELEMENTS --> O(N + KlogN)
 ---> O(N) to build the heap, O(KlogN) to pop out k elements where each popping takes logN
3. HEAP : RESTRICT HEAP SIZE TO K O(K+(N-K)logK+KlogK)
 ---> O(K) to build heap of k elements, O((N-K)logK) to iterate over the remaining N-K elements and in worst, pushing all of them, KlogK to sort

#include <bits/stdc++.h>

using namespace std;

void Nearest(vector<string> &names, vector<int> &x, vector<int> &y, int k)
{
    unordered_map<string, int> mpp;
    for (int i = 0; i < names.size(); i++)
    {
        mpp[names[i]] = ((x[i] * x[i]) + (y[i] * y[i]));
    }
    //use max heap to stor minimum
    priority_queue<int> heap;
    for (int i = 0; i < names.size(); i++)
    {
        int dist = (x[i] * x[i]) + (y[i] * y[i]);
        if (heap.size() < k)
        {
            heap.push(dist);
        }
        else
        {
            if (dist < heap.top())
            {
                heap.pop();
                heap.push(dist);
            }
        }
    }
    unordered_set<int> s;
    while (!heap.empty())
    {
        int element = heap.top();
        s.insert(element);
        heap.pop();
    }
    for (auto i : mpp)
    {
        if (k > 0 && s.find(i.second) != s.end())
        {
            cout << i.first << " ";
            k--;
        }
    }
}

int main()
{
    vector<int> x{1, 2, 3, 0, 2}, y{1, 1, 2, 1, 3};
    vector<string> names{"C1", "C2", "C3", "C4", "C5"};
    Nearest(names, x, y, 3);
    return 0;
}