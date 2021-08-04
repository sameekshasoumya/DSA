#include <iostream>

using namespace std;

int steps(int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    return steps(n - 1) + steps(n - 2) + steps(n - 3);
}

int main()
{
    cout << steps(10);

    return 0;
}