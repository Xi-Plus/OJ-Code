#include <algorithm>
#include <iostream>
using namespace std;
int main(){
    int t, a[1001], b[1001];
    while (cin >> t){
        for (int q = 0; q < t; q++)cin >> a[q];
        for (int q = 0; q < t; q++)cin >> b[q];
        sort(a, a + t);
        sort(b, b + t);
        long long int ans = 0;
        for (int q = 0; q < t; q++)ans += a[q] * b[q];
        cout << ans << endl;
    }
}