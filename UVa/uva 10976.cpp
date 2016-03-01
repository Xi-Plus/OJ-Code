// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n;
	while(cin>>n){
		vector<int> ans;
		for(int q=n+1;q<=2*n;q++){
			if((q*n)%(q-n)==0){
				ans.push_back(q);
			}
		}
		cout<<ans.size()<<endl;
		for(auto i:ans){
			cout<<"1/"<<n<<" = 1/"<<(i*n)/(i-n)<<" + 1/"<<i<<endl;
		}
	}
}