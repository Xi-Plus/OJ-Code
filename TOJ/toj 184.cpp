#include <iostream>
#include <cstring>
using namespace std;
int main(){
    string a, b;
    int la, lb;
    bool m1, m2;
    while (cin >> a >> b){
        la = a.size();
        lb = b.size();
        m1 = (a[0] == '-');
        m2 = (b[0] == '-');
        if (a == "0" || b == "0")cout << "0";
        else {
            if (m1){
                if (m2)
                    b.erase(0,1);
                else
                    cout << "-";
                a.erase(0,1);
            }
            a.erase(0,1);
            cout << b << a;
        }
        cout << endl;
    }
}