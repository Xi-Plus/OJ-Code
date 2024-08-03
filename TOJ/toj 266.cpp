// By xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct T{
	int maxbid;
	long long maxval;
}tree[40010];
priority_queue<long long> bucket[10001];
void init(int tid,int l,int r){
	tree[tid].maxbid=0;
	tree[tid].maxval=-1e18;
	if(l==r) return;
	int m=(l+r)/2;
	init(tid*2,l,m);
	init(tid*2+1,m+1,r);
}
int bid2tid(int tid,int l,int r,int bid){
	if(l==r) return tid;
	int m=(l+r)/2;
	if(bid<=m){
		return bid2tid(tid*2,l,m,bid);
	}else {
		return bid2tid(tid*2+1,m+1,r,bid);
	}
}
void up(int tid){
	if(tree[tid*2+1].maxval>=tree[tid*2].maxval){
		tree[tid].maxval=tree[tid*2+1].maxval;
		tree[tid].maxbid=tree[tid*2+1].maxbid;
	}else {
		tree[tid].maxval=tree[tid*2].maxval;
		tree[tid].maxbid=tree[tid*2].maxbid;
	}
}
void add(int bid,long long val,int l,int r){
	bucket[bid].push(val);
	int tid=bid2tid(1,l,r,bid);
	tree[tid].maxbid=bid;
	tree[tid].maxval=bucket[bid].top();
	tid/=2;
	while(tid){
		up(tid);
		tid/=2;
	}
}
int ansbid;
long long ansval;
void get_max(int ql,int qr,int tl,int tr,int tid){
	if(ql==tl&&qr==tr){
		if(tree[tid].maxval<-1e10) return ;
		if(tree[tid].maxval>ansval){
			ansval=tree[tid].maxval;
			ansbid=tree[tid].maxbid;
		}else if(tree[tid].maxval==ansval){
			ansbid=max(ansbid,tree[tid].maxbid);
		}
		return ;
	}
	int tm=(tl+tr)/2;
	if(ql<=tm){
		get_max(ql,min(qr,tm),tl,tm,tid*2);
	}
	if(qr>tm){
		get_max(max(ql,tm+1),qr,tm+1,tr,tid*2+1);
	}
}
void del(int l,int r){
	bucket[ansbid].pop();
	int tid=bid2tid(1,l,r,ansbid);
	tree[tid].maxval=bucket[ansbid].top();
	tree[tid].maxbid=ansbid;
	tid/=2;
	while(tid){
		up(tid);
		tid/=2;
	}
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n,q;
	cin>>n>>q;
	init(1,1,n);
	for(int q=1;q<=n;q++){
		bucket[q].push(-1e18);
	}
	int a,b,c;
	while(q--){
		cin>>a>>b>>c;
		if(a==0){
			b++;
			add(b,c,1,n);
		}else {
			b++;
			c++;
			ansbid=0;
			ansval=-1e18;
			get_max(b,c,1,n,1);
			if(ansbid==0){
				cout<<-1<<endl;
			}else {
				cout<<ansval<<endl;
				del(1,n);
			}
		}
	}
}
