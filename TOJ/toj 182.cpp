#include <algorithm>
#include <iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    long long int v[3];
    while (t--){
        for (int q = 0; q < 3; q++)cin >> v[q];
        sort(v, v + 3);
        if (v[0] == v[1] && v[1] == v[2])cout << "Equilateral_triangle" << endl;
        else if (v[0] * v[0]<v[2] * v[2] - v[1] * v[1])cout << "Obtuse_triangle" << endl;
        else if (v[0] * v[0] == v[2] * v[2] - v[1] * v[1])cout << "Right_triangle" << endl;
        else if (v[0] * v[0]>v[2] * v[2] - v[1] * v[1])cout << "Acute_triangle" << endl;
    }
}