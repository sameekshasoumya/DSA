//sum up to N then subtract arr elements
int MissingNumber(vector<int> &arr, int n)
{
    int sumUptoN = (n * (n + 1)) / 2;
    for (int i = 0; i < n - 1; i++)
        sumUptoN -= arr[i];
    return sumUptoN;
}

//modified...for above
//to avoid int overflow
int MissingNumber(vector<int>& arr, int n) {
        int missing=1;
        for(int i=0,j=2;i<n-1;i++,j++)
        {
            missing += j;
            missing -= arr[i];
        }
        return missing;
    }

//xor technique
int MissingNumber(vector<int> &array, int n)
{
    int xor_till_n = 0;
    for (int i = 1; i <= n; i++)
        xor_till_n ^= i;
    for (int i = 0; i < n - 1; i++)
        xor_till_n ^= array[i];
    return xor_till_n;
}

//space+time O[N]
int MissingNumber(vector<int> &arr, int n)
{
    vector<bool> uptoN(n + 1, false);
    uptoN[0] = true;
    for (int i = 0; i < n - 1; i++)
        uptoN[arr[i]] = true;
    for (int i = 0; i <= n; i++)
    {
        if (!uptoN[i])
            return i;
    }
}
