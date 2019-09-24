#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int sumdig(int n){
	int ans=0;
	while(n){
		ans+=n%10;
		n/=10;
	}
	return ans;
}
vector<int> plist;
bool notp[46340];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int q=2; q<46340; q++){
		if(!notp[q]){
			plist.push_back(q);
			for(int w=q*2; w<46340; w+=q){
				notp[w]=true;
			}
		}
	}
	int n, k, dig, dig2, n2;
	cin>>n;
	while(n--){
		cin>>k;
		int ans=k+1;
		for(;; ans++){
			dig=sumdig(ans);
			n2=ans;
			dig2=0;
			int pcnt=0;
			for(int c:plist){
				while(n2%c==0){
					dig2+=sumdig(c);
					n2/=c;
					pcnt++;
				}
				if(n2==1){
					break;
				}
			}
			if(n2!=1){
				dig2+=sumdig(n2);
				pcnt++;
			}
			if(pcnt==1){
				continue;
			}
			if(dig2==dig){
				break;
			}
		}
		cout<<ans<<endl;
	}
}
