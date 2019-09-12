#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> fib;
	fib.push_back(1);
	fib.push_back(1);
	for(int q=1; fib[q]<100000000; q++) {
		fib.push_back(fib[q-1]+fib[q]);
	}
	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<n<<" = ";
		int i=fib.size()-1;
		while(fib[i]>n){
			i--;
		}
		for(;i>0; i--){
			if(n>=fib[i]){
				cout<<1;
				n-=fib[i];
			}else{
				cout<<0;
			}
		}
		cout<<" (fib)"<<endl;
	}
}
