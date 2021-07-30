/*

Finding Square root in log time without STL

*/

//O(sqrt(N))
int i = 0;
while (i * i <= N)
{
    i++;
}
return (i - 1);

//O(logN)

int mySqrt(int x)
{
    long int lo = 0;
    long int hi = x;
    while (hi >= lo)
    {
        long int mid = lo + (hi - lo) / 2;
        if (mid * mid == (long int)x)
            return mid;
        else if (mid * mid < (long int)x)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return (int)(lo - 1);
}

//With a desired precision

#include <iostream>

using namespace std;

float sqrtcode(int num, int places)
{
    //first binary search to get integer part
    long int lo = 0;
    long int hi = num;
    while (hi >= lo)
    {
        long int mid = lo + (hi - lo) / 2;
        if (mid * mid == num)
            return (int)mid;
        else if (mid * mid < num)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    float inc = 0.1;
    double integer = (lo - 1.0);
    //do linear search to get the entire answer in ~ O(precision*9)
    while (places--)
    {
        while (integer * integer <= num)
            integer += inc;
        integer -= inc;
        inc /= 10.0;
    }
    return integer;
}

int main()
{
    int num, places;
    cin >> num >> places;
    cout << sqrtcode(num, places) << endl;
    return 0;
}
