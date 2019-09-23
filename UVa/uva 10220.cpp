#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while(cin>>n){
		vector<int> ans;
		ans.push_back(1);
		for(int q=2; q<=n; q++){
			for(int w=ans.size()-1; w>=0; w--){
				ans[w]*=q;
			}
			for(int w=0; w<ans.size(); w++){
				if(ans[w]>=10){
					if(w==ans.size()-1){
						ans.push_back(0);
					}
					ans[w+1]+=ans[w]/10;
					ans[w]%=10;
				}
			}
		}
		int res=0;
		for(int c:ans){
			res+=c;
		}
		cout<<res<<endl;
	}
}
