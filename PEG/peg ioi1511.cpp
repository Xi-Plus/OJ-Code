// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int N,K,L;
	cin>>N>>K>>L;
	vector<int> left,right;
	int t;
	for(int q=0;q<N;q++){
		cin>>t;
		if(t==0);
		else if(t<=L/2)left.push_back(t);
		else right.push_back(L-t);
	}
	reverse(right.begin(),right.end());
	int lsz=left.size(),rsz=right.size();
	long long ans=0;
	for(int q=lsz-1;q>=0;q-=K)ans+=left[q]*2;
	for(int q=rsz-1;q>=0;q-=K)ans+=right[q]*2;
	for(int q=0;q<=K&&lsz-q>=0;q++){
		int w=min(K-q,rsz);
		long long tans=L;
		for(int e=lsz-1-q;e>=0;e-=K)tans+=left[e]*2;
		for(int e=rsz-1-w;e>=0;e-=K)tans+=right[e]*2;
		ans=min(ans,tans);
	}
	cout<<ans<<endl;
}
