// By xiplus
#include <iostream>
#define endl '\n'
using namespace std;
int n;
struct T{
	long long sum;
	long long lazy;
}v[400000];
void init(int p,int l,int r){
	v[p].sum=0;
	if(l==r) return;
	int mid=(l+r)/2;
	init(p*2,l,mid);
	init(p*2+1,mid+1,r);
}
void up(int id){
	v[id].sum=v[id*2].sum+v[id*2+1].sum;
}
void down(int id,int l,int r){
	if(v[id].lazy){
		int m=(l+r)/2;
		v[id*2].lazy+=v[id].lazy;
		v[id*2].sum+=(m-l+1)*v[id].lazy;
		v[id*2+1].lazy+=v[id].lazy;
		v[id*2+1].sum+=(r-m)*v[id].lazy;
		v[id].lazy=0;
	}
}
void add(int L,int R,long long val,int l,int r,int id){
	if(L==l&&R==r){
		v[id].lazy+=val;
		v[id].sum+=val*(r-l+1);
		return ;
	}
	down(id,l,r);
	int m=(l+r)/2;
	if(L<=m){
		add(L,min(R,m),val,l,m,id*2);
	}
	if(R>m){
		add(max(L,m+1),R,val,m+1,r,id*2+1);
	}
	up(id);
}
long long anssum;
void ans(int L,int R,int l,int r,int id){
	if(L==l&&R==r){
		anssum+=v[id].sum;
		return ;
	}
	down(id,l,r);
	int m=(l+r)/2;
	if(L<=m){
		ans(L,min(R,m),l,m,id*2);
	}
	if(R>m){
		ans(max(L,m+1),R,m+1,r,id*2+1);
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
		add(q,q,t,1,n,1);
	}
	int a,b;
	char c;
	while(m--){
		cin>>c;
		if(c=='Q'){
			cin>>a>>b;
			anssum=0;
			ans(a,b,1,n,1);
			cout<<anssum<<endl;
		}else {
			cin>>a>>b>>t;
			add(a,b,t,1,n,1);
		}
	}
}
