// By KRT girl xiplus
#include <iostream>
#define endl '\n'
using namespace std;
const int INF=1e9;
struct Treap{
	Treap *l,*r;
	int key,sz,add,maxi;
	bool reverse;
	Treap(int k){
		l=r=NULL;
		key=maxi=k;
		sz=1;
		add=0;
	}
	void down(){
		if(add){
			key+=add;
			if(l)l->add+=add;
			if(r)r->add+=add;
			add=0;
		}
	}
	void up(){
		sz=1;
		maxi=key;
		if(l){
			sz+=l->sz;
			maxi=max(maxi,l->maxi+l->add);
		}
		if(r){
			sz+=r->sz;
			maxi=max(maxi,r->maxi+r->add);
		}
	}
};
int size(Treap *o){
	return o?o->sz:0;
}
Treap* merge(Treap *a,Treap *b){
	if(!a||!b) return a?a:b;
	if(rand()%(size(a)+size(b))<size(a)){
		a->down();
		a->r=merge(a->r,b);
		a->up();
		return a;
	}else {
		b->down();
		b->l=merge(a,b->l);
		b->up();
		return b;
	}
}
void split(Treap *o,Treap *&a,Treap *&b,int k){
	if(!o){
		a=b=NULL;
		return ;
	}
	o->down();
	if(size(o->l)+1<=k){
		a=o;
		split(o->r,a->r,b,k-size(o->l)-1);
		a->up();
	}else {
		b=o;
		split(o->l,a,b->l,k);
		b->up();
	}
}
void add(Treap *&o,int l,int r,int x){
	Treap *a,*b,*c;
	split(o,a,b,l-1);
	split(b,b,c,r-l+1);
	b->add+=x;
	o=merge(merge(a,b),c);
}
void insert(Treap *&o,int k,int x){
	Treap *a,*b;
	split(o,a,b,k);
	o=merge(merge(a,new Treap(x)),b);
}
void remove(Treap *&o,int k){
	Treap *a,*b,*c;
	split(o,a,b,k-1);
	split(b,b,c,1);
	o=merge(a,c);
}
int ans(Treap *&o,int l,int r){
	Treap *a,*b,*c;
	split(o,a,b,l-1);
	split(b,b,c,r-l+1);
	int x=b->maxi;
	o=merge(merge(a,b),c);
	return x;
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n,q;
	Treap *root=NULL;
	cin>>n>>q;
	int t;
	for(int q=0;q<n;q++){
		cin>>t;
		root=merge(root,new Treap(t));
	}
	int s;
	int l,r,x;
	while(q--){
		cin>>s;
		if(s==1){
			cin>>l>>x;
			add(root,l,l,x-ans(root,l,l));
		}else if(s==3){
			cin>>l>>x;
			insert(root,l,x);
		}else if(s==4){
			cin>>l;
			remove(root,l);
		}else if(s==2){
			cin>>l>>r;
			cout<<ans(root,l,r)<<endl;
		}
	}
}
