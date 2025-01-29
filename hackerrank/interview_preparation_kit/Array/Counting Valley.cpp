#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'countingValleys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
 */


int countingValleys(int steps, string path) {
    int sealevel = 0, valley = 0, previous_lv = 0; 
    for(int i = 0; i < steps; i++){
        previous_lv = sealevel;
        if(path[i] == 'U') sealevel ++;
        else sealevel--;

        if (!sealevel && previous_lv<0) valley++;
    }
    return valley;
}

int main(){
    int steps = 8;
    string path = "UDDDUDUU";
    int result = countingValleys(steps, path);
    cout << result;
    return 0;
}

// int main()
// {
//     ofstream fout(getenv("OUTPUT_PATH"));

//     string steps_temp;
//     getline(cin, steps_temp);

//     int steps = stoi(ltrim(rtrim(steps_temp)));

//     string path;
//     getline(cin, path);

//     int result = countingValleys(steps, path);

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
