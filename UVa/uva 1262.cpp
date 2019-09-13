#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, k;
	char c;
	cin>>t;
	while(t--){
		cin>>k;
		set<char> can1[5];
		for(int q=0; q<6; q++){
			for(int w=0; w<5; w++){
				cin>>c;
				can1[w].insert(c);
			}
		}
		vector<char> can[5];
		for(int q=0; q<6; q++){
			for(int w=0; w<5; w++){
				cin>>c;
				if(can1[w].count(c)){
					can[w].push_back(c);
				}
			}
		}
		int poss=1;
		for(int q=0; q<5; q++) {
			sort(can[q].begin(), can[q].end());
			poss*=can[q].size();
		}
		if(k>poss){
			cout<<"NO"<<endl;
		}else{
			string ans;
			for(int q=4; q>=0; q--){
				ans=can[q][k%can[q].size()]+ans;
				k/=can[q].size();
			}
			cout<<ans<<endl;
		}
	}
}
