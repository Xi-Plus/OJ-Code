// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	long long n,k;
	cin>>n>>k;
	cout<<(n*(k-1)+1)*n+n*(n-1)/2*(n-k+1)<<endl;
	for(int q=0;q<n;q++){
		for(int w=0;w<k-1;w++){
			cout<<q*(k-1)+1+w<<" ";
		}
		for(int w=0;w<n-k+1;w++){
			cout<<n*(k-1)+1+(n-k+1)*q+w<<" ";
		}
		cout<<endl;
	}
}

