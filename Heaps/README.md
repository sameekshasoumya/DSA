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