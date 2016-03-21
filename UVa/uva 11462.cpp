// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n;
	while(cin>>n,n){
		int t;
		vector<int> v;
		for(int q=0;q<n;q++){
			cin>>t;
			v.push_back(t);
		}
		sort(v.begin(),v.end());
		cout<<v[0];
		for(int q=1;q<n;q++)cout<<" "<<v[q];
		cout<<endl;
	}
}	
