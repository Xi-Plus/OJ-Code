#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int m;
bool cmp(int a, int b){
	if(a%m==b%m){
		if((a&1)+(b&1)!=1){
			if(a&1){
				return a>b;
			}else{
				return a<b;
			}
		}
		return (a&1)>(b&1);
	}
	return a%m<b%m;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, arr[10005];
	while(cin>>n>>m, n||m){
		for(int q=0; q<n; q++){
			cin>>arr[q];
		}
		sort(arr, arr+n, cmp);
		cout<<n<<" "<<m<<endl;
		for(int q=0; q<n; q++){
			cout<<arr[q]<<endl;
		}
	}
	cout<<"0 0"<<endl;
}
