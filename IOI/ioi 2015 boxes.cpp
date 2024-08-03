// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
long long delivery(int N,int K,int L,int p[]){
	vector<int> left,right;
	for(int q=0;q<N;q++){
		if(p[q]==0);
		else if(p[q]<=L/2)left.push_back(p[q]);
		else right.push_back(L-p[q]);
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
	return ans;
}
