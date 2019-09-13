#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
bool notp[46340];
vector<int> plist;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int q=2; q<46340; q++){
		if(!notp[q]){
			plist.push_back(q);
		}
		for(int w=q*2; w<46340; w+=q){
			notp[w]=true;
		}
	}
	int n, l, u;
	cin>>n;
	while(n--){
		cin>>l>>u;
		int ans, ansc=0;
		for(int q=l; q<=u; q++){
			int tn=q, ta=1;
			for(int w=0; w<plist.size()&&tn; w++){
				int cnt=1;
				while(tn%plist[w]==0){
					tn/=plist[w];
					cnt++;
				}
				ta*=cnt;
			}
			if(tn>1){
				ta*=2;
			}
			if(ta>ansc){
				ans=q;
				ansc=ta;
			}
		}
		cout<<"Between "<<l<<" and "<<u<<", "<<ans<<" has a maximum of "<<ansc<<" divisors."<<endl;
	}
}
