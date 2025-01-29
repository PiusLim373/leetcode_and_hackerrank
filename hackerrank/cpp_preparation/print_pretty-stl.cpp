#include <iostream>
#include <iomanip> 
using namespace std;

// int main() {
// 	int T; cin >> T;
// 	cout << setiosflags(ios::uppercase);
// 	cout << setw(0xf) << internal;
// 	while(T--) {
// 		double A; cin >> A;
// 		double B; cin >> B;
// 		double C; cin >> C;

// 		/* Enter your code here */
        

// 	}
// 	return 0;

// }
int main(){

    cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;

    double A = 100.991234123;
    cout << A <<endl;
     cout <<  hex << showbase << (long long)A << endl;

    double B = 2006.1;
    double B_2dec = (B*100.0)/100.0;
    // B = B*100.0/100.0;
    string B_string = to_string(B);
    // printf(".2f", B);
    cout << setw(15) << setfill('_')<< right << setprecision(2) << fixed << showpos <<  B <<endl;

    double C = 2331.5678;
    // double C = 2.345e12;
    cout << setiosflags(ios::uppercase) << setprecision(9) << scientific << C << endl;
}