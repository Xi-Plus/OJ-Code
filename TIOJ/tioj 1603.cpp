// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n;
struct T{
	int l,r;
	long long minn,maxn;
}v[400000];
void init(int p,int l,int r){
	v[p].l=l;
	v[p].r=r;
	v[p].minn=1e18;
	v[p].maxn=0;
	if(l==r) return ;
	int mid=(l+r)/2;
	init(p*2,l,mid);
	init(p*2+1,mid+1,r);
}
void add(int p,int i,long long val){
	v[p].minn=min(v[p].minn,val);
	v[p].maxn=max(v[p].maxn,val);
	if(v[p].l==v[p].r) return ;
	int mid=(v[p].l+v[p].r)/2;
	if(i<=mid){
		add(p*2,i,val);
	}else {
		add(p*2+1,i,val);
	}
}
long long ansmin,ansmax;
void ans(int p,int l,int r){
	if(v[p].l==l&&v[p].r==r){
		ansmin=min(ansmin,v[p].minn);
		ansmax=max(ansmax,v[p].maxn);
		return ;
	}
	int mid=(v[p].l+v[p].r)/2;
	if(l<=mid){
		ans(p*2,l,min(r,mid));
	}
	if(r>mid){
		ans(p*2+1,max(mid+1,l),r);
	}
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int m;
	cin>>n>>m;
	init(1,1,n);
	long long t;
	for(int q=1;q<=n;q++){
		cin>>t;
		add(1,q,t);
	}
	int a,b;
	while(m--){
		cin>>a>>b;
		ansmin=1e18;
		ansmax=0;
		ans(1,a,b);
		cout<<ansmax-ansmin<<endl;
	}
}
