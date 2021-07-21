/*
Vectors are sort of dynamic array
They resize themselves according to the need
Main operations : v.size(), v.capacity(), fill constructor, v.push_back(), v.pop_back(), print all elements
*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    //initialization
    vector<int> vec = {1,2,4,8,16};
    /*
    The vector size right now is 5 as well as its capacity is 5
    --> Capacity at time of initialization = size at the time of initialization
    --> When size==capacity, capacity==2*size
    */

   //initalization thru fill constructor
   //initialize a vector of 100 elements all with value 0
   vector<int> v(100,0);
   vector<bool> visited(10,true);

   //removes the last element in O(1) time
   vec.pop_back();

   //pushes the element in O(1) time
   vec.push_back(32);

   //to print all the elements
   for(int i=0;i<vec.size();i++)
   cout<< vec[i] <<endl;
   //or
   for(auto i:vec)
   cout<< i <<endl;

   //to know the size
   cout<< vec.size() <<endl;

   //to know the capacity
   cout<< vec.capacity() <<endl;
    return 0;
}