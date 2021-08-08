//No. of 5 in the factors of N! contribute to the number of 0s.

int trailingZeroes(int N)
{
    int z = 0;
    for (int i = 5; i <= N; i *= 5)
        z += (N / i);
    return z;
}