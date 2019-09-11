#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int arr[3005];
	int n;
	while(cin>>n) {
		for(int q=0; q<n; q++){
			cin>>arr[q];
		}
		for(int q=0; q<n-1; q++){
			arr[q]=abs(arr[q]-arr[q+1]);
		}
		sort(arr, arr+n-1);
		bool ans=true;
		for(int q=0; q<n-1; q++){
			if(arr[q]!=q+1) {
				ans=false;
				break;
			}
		}
		if(ans){
			cout<<"Jolly"<<endl;
		}else {
			cout<<"Not jolly"<<endl;
		}
	}
}
