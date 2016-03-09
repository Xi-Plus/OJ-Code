// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n;
	vector<int> v;
	cin>>n;
	int a,b;
	int ans=0;
	for(int q=0;q<n;q++){
		cin>>a>>b;
		while(!v.empty()&&v.back()>b){
			v.pop_back();
		}
		if(v.empty()||v.back()!=b){
			v.push_back(b);
			ans++;
		}
	}
	cout<<ans<<endl;
}
