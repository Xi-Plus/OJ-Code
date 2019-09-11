#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int calc(int n){
	if(n<10) {
		return n;
	}
	int temp=0;
	while(n){
		temp+=n%10;
		n/=10;
	}
	return calc(temp);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while(cin>>n, n){
		cout<<calc(n)<<endl;
	}
}

