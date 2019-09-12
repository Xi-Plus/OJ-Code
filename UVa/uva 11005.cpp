#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int cost[36];
vector<int> anslist;
int mincost;
void calc(int n, int m){
	int ans=0;
	if(n==0){
		ans=cost[0];
	}else{
		while(n){
			ans+=cost[n%m];
			n/=m;
		}
	}
	if(ans<mincost){
		anslist.clear();
		anslist.push_back(m);
		mincost=ans;
	}else if(ans==mincost){
		anslist.push_back(m);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T, k, n;
	cin>>T;
	for(int t=1; t<=T; t++){
		if(t>1){
			cout<<endl;
		}
		cout<<"Case "<<t<<":"<<endl;
		for(int q=0; q<36; q++){
			cin>>cost[q];
		}
		cin>>k;
		while(k--){
			cin>>n;
			mincost=INT_MAX;
			for(int q=2; q<=36; q++){
				calc(n, q);
			}
			cout<<"Cheapest base(s) for number "<<n<<":";
			for(int ans:anslist){
				cout<<" "<<ans;
			}
			cout<<endl;
		}
	}
}
