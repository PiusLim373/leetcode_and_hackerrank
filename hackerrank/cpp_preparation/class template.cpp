#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

int start_up() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}

int static r = start_up();

#define endl '\n';

template<class T>
class AddElements{
    public:
        T ele1;
        AddElements(T ele): ele1(ele) {};
        T add(T ele){
            return ele1 + ele; 
        }

        T concatenate(T ele){
            return ele1.append(ele); 
        }
};
/*Write the class AddElements here*/

// int main () {
//   int n,i;
//   cin >> n;
//   for(i=0;i<n;i++) {
//     string type;
//     cin >> type;
//     if(type=="float") {
//         double element1,element2;
//         cin >> element1 >> element2;
//         AddElements<double> myfloat (element1);
//         cout << myfloat.add(element2) << endl;
//     }
//     else if(type == "int") {
//         int element1, element2;
//         cin >> element1 >> element2;
//         AddElements<int> myint (element1);
//         cout << myint.add(element2) << endl;
//     }
//     else if(type == "string") {
//         string element1, element2;
//         cin >> element1 >> element2;
//         AddElements<string> mystring (element1);
//         cout << mystring.concatenate(element2) << endl;
//     }
//   }
//   return 0;
// }
int main(){
    double element1 = 4.0,element2 = 1.5;
    AddElements<double> myfloat (element1);
    cout << myfloat.add(element2) << endl;

    string element3 = "pius", element4 = "lim";
    AddElements<string> mystr (element3);
    cout << mystr.concatenate(element4) << endl;
}