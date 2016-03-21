// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct T{
	int idx;
	string s;
	int bit;
};
bool cmp(T a,T b){
	if(a.bit==b.bit)return a.idx<b.idx;
	return a.bit<b.bit;
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		string s;
		vector<T> v;
		for(int i=0;i<m;i++){
			cin>>s;
			int k=0;
			for(int q=0;q<n-1;q++){
				for(int w=q+1;w<n;w++){
					if(s[q]>s[w])k++;
				}
			}
			v.push_back({i,s,k});
		}
		sort(v.begin(),v.end(),cmp);
		for(auto i:v){
			cout<<i.s<<endl;
		}
		if(t)cout<<endl;
	}
}
