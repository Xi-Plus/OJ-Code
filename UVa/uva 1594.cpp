#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T, n, a, arr[20];
	cin>>T;
	while(T--){
		cin>>n;
		for(int q=0; q<n; q++){
			cin>>arr[q];
		}
		bool zero=false;
		for(int q=0; q<1005; q++){
			a=arr[0];
			bool allzero=true;
			for(int w=0; w<n-1; w++){
				arr[w]=abs(arr[w]-arr[w+1]);
				if(arr[w]!=0){
					allzero=false;
				}
			}
			arr[n-1]=abs(arr[n-1]-a);
			if(allzero&&arr[n-1]==0){
				zero=true;
				break;
			}
		}
		if(zero){
			cout<<"ZERO"<<endl;
		}else{
			cout<<"LOOP"<<endl;
		}
	}
}
