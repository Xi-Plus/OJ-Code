#include <bits/stdc++.h>
#define endl '\n'
#define MAXN 10005
using namespace std;
bool notp[MAXN];
vector<int> plist;
bool isp(int n){
	n=n*n+n+41;
	for(int p:plist){
		if(n%p==0 && n>p){
			return false;
		}
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int q=2; q<MAXN; q++){
		if(!notp[q]){
			plist.push_back(q);
			for(int w=q*2; w<MAXN; w+=q){
				notp[w]=1;
			}
		}
	}
	int ans[MAXN];
	ans[0]=0;
	for(int q=1; q<MAXN; q++){
		ans[q]=ans[q-1]+isp(q-1);
	}
	int a, b;
	cout<<fixed<<setprecision(2);
	while(cin>>a>>b){
		double cnt=ans[b+1]-ans[a];
		cout<<cnt*100/(b-a+1)+0.000001<<endl;
	}
}
