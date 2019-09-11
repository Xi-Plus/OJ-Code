#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T, x, y;
	long long arr[47000]={0};
	for(long long i=1; i<47000; i++){
		if(i&1){
			arr[i]=(1+i/2)*(i/2)+i/2+1;
		}else{
			arr[i]=(1+i/2)*(i/2);
		}
	}
	cin>>T;
	while(T--){
		cin>>x>>y;
		cout<<upper_bound(arr,arr+47000, y-x-1)-arr<<endl;
	}
}
