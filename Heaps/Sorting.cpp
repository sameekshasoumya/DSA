/*--------------------DESCENDING ORDER SORT (BY DEFAULT)------------------------------------------------------------------------------------------*/

#include <bits/stdc++.h>

using namespace std;

void sort(vector<int> &v)
{
    priority_queue<int> heap;
    for (int i : v)
        heap.push(i);
    while (!heap.empty())
    {
        cout << heap.top() << " ";
        heap.pop();
    }
}

int main()
{
    vector<int> v{199, 29, 20, 843, 90, 2};
    sort(v);
    return 0;
}

/*--------------------ASCENDING ORDER USING INBUILT COMP------------------------------------------------------------------------------------------*/

#include <bits/stdc++.h>

using namespace std;

void sort(vector<int> &v)
{
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i : v)
        heap.push(i);
    while (!heap.empty())
    {
        cout << heap.top() << " ";
        heap.pop();
    }
}

int main()
{
    vector<int> v{199, 29, 20, 843, 90, 2};
    sort(v);
    return 0;
}

/*--------------------ASCENDING ORDER SORT USING CLASS CUSTOM COMP-------------------------------------------------------------------------------*/
//USING OPERATOR OVERLOADING
#include <bits/stdc++.h>

using namespace std;

class comp
{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

void sort(vector<int> &v)
{
    priority_queue<int, vector<int>, comp> heap;
    for (int i : v)
        heap.push(i);
    while (!heap.empty())
    {
        cout << heap.top() << " ";
        heap.pop();
    }
}

int main()
{
    vector<int> v{199, 29, 20, 843, 90, 2};
    sort(v);
    return 0;
}