#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;

int replaceSpaces(char str[])
{
    int curr_len = 0, spaces = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        curr_len++;
        if (str[i] == ' ')
            spaces++;
    }
    int add_space = 2 * spaces;
    //" " --> "%20" --> 1 space we need 3 space, i.e. 2 additional space
    str[curr_len + add_space] = '\0';
    int temp = curr_len - 1;
    for (int i = (curr_len + add_space) - 1; i >= 0; i--, temp--)
    {
        if (str[temp] == ' ')
        {
            str[i] = '0';
            str[i - 1] = '2';
            str[i - 2] = '%';
            i -= 2;
        }
        else
        {
            str[i] = str[temp];
        }
    }
    return (add_space + curr_len);
}

int main()
{
    char str[MAX] = "Mr John Smith";

    // Prints the replaced string
    int new_length = replaceSpaces(str);
    for (int i = 0; i < new_length; i++)
        printf("%c", str[i]);
    return 0;
}