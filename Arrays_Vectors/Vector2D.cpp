#include <iostream>
#include <vector>
using namespace std;

int main(){
    //benefit over 2D array : each row can have diff number of columns
    vector<vector<int>> vec = {
        {1,3,6},
        {2,4,6,8},
        {4},
        {1,2,3,4,5}
    };

    //update and re-write in O(1) time
    vec[0][0] += 100;

    //print all the elements
    for(int i=0;i<vec.size();i++)
    {
        for(auto j : vec[i])
        {
            cout<< j <<endl;
        }
    }
    return 0;
}