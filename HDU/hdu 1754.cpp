// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n;
struct T{
	int l,r;
	int maxg;
}v[800000];
void init(int p,int l,int r){
	v[p].l=l;
	v[p].r=r;
	v[p].maxg=-2147483647;
	if(l==r) return ;
	int mid=(l+r)/2;
	init(p*2,l,mid);
	init(p*2+1,mid+1,r);
}
int get_index(int p,int find){
	if(v[p].l==v[p].r) return p;
	int mid=(v[p].l+v[p].r)/2;
	if(find<=mid){
		return get_index(p*2,find);
	}else {
		return get_index(p*2+1,find);
	}
}
void edit(int i,int val){
	int index=get_index(1,i);
	v[index].maxg=val;
	index/=2;
	while(index){
		v[index].maxg=max(v[index*2].maxg,v[index*2+1].maxg);
		index/=2;
	}
}
int ansg;
void ans(int p,int l,int r){
	if(v[p].l==l&&v[p].r==r){
		ansg=max(ansg,v[p].maxg);
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
	while(cin>>n>>m){
		init(1,1,n);
		long long t;
		for(int q=1;q<=n;q++){
			cin>>t;
			edit(q,t);
		}
		int a,b;
		char c;
		while(m--){
			cin>>c>>a>>b;
			if(c=='Q'){
				ansg=-2147483647;
				ans(1,a,b);
				cout<<ansg<<endl;
			}else {
				edit(a,b);
			}
		}
	}
}
