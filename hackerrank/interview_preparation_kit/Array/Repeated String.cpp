#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'repeatedString' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. LONG_INTEGER n
 */

long repeatedString(string s, long n) {
    int count = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'a') count++;
    }
    long divisor, remainder;
    divisor = n/(s.size());
    remainder = n%(s.size());
    count *= divisor;

    string truncated_str = s.substr(0, remainder);
    cout <<"trunc str"<< truncated_str <<endl;
    for (int i = 0; i < truncated_str.size(); i++){
        if (truncated_str[i] == 'a') count++;
    }
    return count;
}

int main(){
    string to_repeat = "a";
    long n = 1000;
    cout << repeatedString(to_repeat, n);
    return 0;
}

// int main()
// {
//     ofstream fout(getenv("OUTPUT_PATH"));

//     string s;
//     getline(cin, s);

//     string n_temp;
//     getline(cin, n_temp);

//     long n = stol(ltrim(rtrim(n_temp)));

//     long result = repeatedString(s, n);

//     fout << result << "\n";

//     fout.close();

//     return 0;
// }

// string ltrim(const string &str) {
//     string s(str);

//     s.erase(
//         s.begin(),
//         find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
//     );

//     return s;
// }

// string rtrim(const string &str) {
//     string s(str);

//     s.erase(
//         find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
//         s.end()
//     );

//     return s;
// }
