#include <bits/stdc++.h>

using namespace std;

string primality(int n)
{
    if (n <= 1)
        return "Not prime";
    for (int i = 2; i < (int)sqrt(n) + 1; i++)
    {
        if (n % i == 0)
            return "Not prime";
    }
    return "Prime";
}

int main()
{
    int number = 5;
    cout << primality(number) << endl;
}