
int pick = 2;
int guess(int num)
{
    if (num < pick)
        return 1;
    else if (num > pick)
        return -1;
    else
        return 0;
}

int guessNumber(int n)
{
    if (n == 1)
        return 1;
    int left = 0;
    int right = n;
    long long middle = (left + right) / 2;
    int result = guess(middle);
    while (result != 0)
    {
        if (result == 1)
            left = middle + 1;
        else 
            right = middle - 1;
        middle = (left + right) / 2;
        result = guess(middle);
    }   
    return middle;
}

int main()
{
    int n = 2;
    auto ans = guessNumber(n);
    return 0;
}