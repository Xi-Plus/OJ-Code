#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, t=1;
	while(cin>>n, n>0){
		if(n==1){
			cout<<"Case "<<t++<<": 0"<<endl;
		}else{
			cout<<"Case "<<t++<<": "<<(int)log2(n-1)+1<<endl;
		}
	}
}
