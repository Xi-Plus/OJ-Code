// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct T{
	long long val,pri;
};
bool cmp(T a,T b){
	return a.val<b.val;
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int N,K,L;
	cin>>N>>K>>L;
	vector<T> left,right;
	left.push_back({0,0});
	right.push_back({0,0});
	int t;
	for(int q=0;q<N;q++){
		cin>>t;
		if(t==0);
		else if(t<=L/2)left.push_back({t,0});
		else right.push_back({L-t,0});
	}
	reverse(right.begin()+1,right.end());
	int lsz=left.size()-1,rsz=right.size()-1;
	for(int q=1;q<=min(K,lsz);q++){
		left[q].pri=left[q].val;
	}
	for(int q=K;q<=lsz;q++){
		left[q].pri=left[q-K].pri+left[q].val;
	}
	for(int q=1;q<=min(K,rsz);q++){
		right[q].pri=right[q].val;
	}
	for(int q=K;q<=rsz;q++){
		right[q].pri=right[q-K].pri+right[q].val;
	}
	long long oans=left.back().pri*2+right.back().pri*2,ans=oans;
	for(int q=0;q<=K&&lsz-q>=0;q++){
		int w=min(K-q,rsz);
		ans=min(oans-(left[lsz].pri-left[lsz-q].pri)*2-(right[rsz].pri-right[rsz-w].pri)*2+L,ans);
	}
	cout<<ans<<endl;
}
