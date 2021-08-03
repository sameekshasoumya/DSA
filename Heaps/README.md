# HEAP
Heap - Complete Binary Tree

*Complete BT : Each level is completely filled except the last one(last one is also filled from L to R)

         |----  MAX-HEAP  --> Val(Child Node) < Val(Parent Node)
HEAP ----|
         |----  MIN-HEAP  --> Val(Child Node) > Val(Parent Node)

## Time Complexity
Push : O(logN)            --> Depends on height of the tree
PopMin/PopMax : O(logN)
GetMin/GetMax : O(1)      --> Constant time for lookup as the min/max lies either at root or the leaf nodes

## STL
Max Heap by default :
priority_queue<int> MaxHeap

To make this as min heap :
priority_queue<int, vector<int> ,greater<int>> MinHeap;
//priority_queue<data_type, vector<data_type> ,greater<data_type>> MinHeap;
or
Using operator overloading with custom compatator

## REMEMBER

1. Insertion happens at the bottom of the heap/end of the array and not at top.
2. A complete binary tree is a binary tree in which every level of the tree is fully filled, except for perhaps the last level. To the extent that the last level is filled, it is filled left to right. HEAP is a complete binary tree.
3. Heap is a complete binary tree, hence height is always O(LogN). There is no best or worst case complexity in it.
4. In a binary max heap containing N integers, the smallest element can be found in O(N) --> In a max heap, the smallest element is always present at a leaf node. So we need to check for all leaf nodes for the minimum value. Worst case complexity will be O(n). WE USE LINEAR SEARCH.
5. Heap sort is efficient, consistent and uses minimum memory.