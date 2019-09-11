#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	char c;
	int n;
	long long a[105][105];
	for(int t=1; t<=T; t++){
		cin>>c>>c>>n;
		bool ans=true;
		for(int q=0; q<n; q++){
			for(int w=0; w<n; w++){
				cin>>a[q][w];
				if(a[q][w]<0){
					ans=false;
				}
			}
		}
		for(int q=0; q<n; q++){
			for(int w=0; w<n/2; w++){
				if(a[q][w] != a[n-q-1][n-w-1]){
					ans=false;
				}
			}
		}
		cout<<"Test #"<<t<<": "<<(ans?"Symmetric.":"Non-symmetric.")<<endl;
	}
}
