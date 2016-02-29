#include <algorithm>
#include <iostream>
const int K=10000000;
bool nisp[K]={false};
int p[664580]={0};
using namespace std;
int main(){
    nisp[0] = nisp[1] = true;
    int i = 2, j, k = 1;
    while (i < K){
        if (!nisp[i]){
            p[k++] = i;
            j = i * 2;
            while (j < K){
                nisp[j] = true;
                j += i;
            }
        }
        i++;
    }
    int a, b, m; char c;
    while (cin >> a >> c >> b){
        a=lower_bound(p,p+664580,a)-p;
        b=lower_bound(p,p+664580,b)-p;
        switch (c){
            case '+':
                cout << p[a + b] << endl;
                break;
            case '-':
                cout << p[a - b] << endl;
                break;
            case '*':
                cout << p[a*b] << endl;
                break;
            case '/':
                cout << p[a / b] << endl;
                break;
        }
    }
    return 0;
}