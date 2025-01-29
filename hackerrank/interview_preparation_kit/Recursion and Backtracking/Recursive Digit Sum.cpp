#include <bits/stdc++.h>

using namespace std;
int g_k = 0;
char buffer[sizeof(int) * 8 + 1];

int superDigit(string n, int k)
{
    if (n.size() == 1)
        return stoi(n);
    else
    {
        long sum = 0;
        for (auto x : n)
        {
            sum += ((int)x - 48);
        }
        return superDigit(to_string(sum * k), 1);
    }
}

int main()
{
    int k = 4;
    string n = "9875";
    cout << superDigit(n, k) << endl;
    // string n2 = "98759";
    return 0;
}