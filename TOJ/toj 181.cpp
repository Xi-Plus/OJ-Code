#include <cmath>
#include <iostream>
using namespace std;
int main(){
    char c[64];
    for (int q = 0; q < 26; q++)c[q] = 'A' + q;
    for (int q = 0; q < 26; q++)c[26 + q] = 'z' - q;
    for (int q = 0; q < 5; q++)c[52 + q] = '0' + q * 2;
    for (int q = 0; q < 5; q++)c[57 + q] = '1' + q * 2;
    int n;
    while (cin >> n){
        n = abs(n);
        if (n >= 63)cout << "ERROR!" << endl;
        else {
            for (int i = 0; i < n; i++){
                for (int j = n - 1; j > i; j--)
                    cout << " ";
                for (int j = 0; j <= i; j++)
                    cout << c[j];
                for (int j = i - 1; j >= 0; j--)
                    cout << c[j];
                cout << endl;
            }
            for (int i = 0; i < n; i++){
                for (int j = 1; j < n; j++)
                    cout << " ";
                cout << c[n - 1] << endl;
            }
        }
    }
}