// By KRT girl xiplus
#include <iostream>
#define endl '\n'
using namespace std;
const int INF=1e9;
int ran(){
	int x=20160829;
	x=x*0xdefaced+1;
	return x&2147483647;
}
struct Treap{
	Treap *l,*r;
	int key,sz,add,mini;
	bool reverse;
	Treap(int k){
		l=r=NULL;
		key=mini=k;
		sz=1;
		add=0;
		reverse=false;
	}
	void down(){
		if(reverse){
			swap(l,r);
			if(l)l->reverse^=1;
			if(r)r->reverse^=1;
			reverse=false;
		}
		if(add){
			key+=add;
			if(l)l->add+=add;
			if(r)r->add+=add;
			add=0;
		}
	}
	void up(){
		sz=+1;
		mini=key;
		if(l){
			sz+=l->sz;
			mini=min(mini,l->mini+l->add);
		}
		if(r){
			sz+=r->sz;
			mini=min(mini,r->mini+r->add);
		}
	}
};
int size(Treap *o){
	return o?o->sz:0;
}
Treap* merge(Treap *a,Treap *b){
	if(!a||!b) return a?a:b;
	if(ran()%(size(a)+size(b))<size(a)){
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
void reverse(Treap *&o,int l,int r){
	Treap *a,*b,*c;
	split(o,a,b,l-1);
	split(b,b,c,r-l+1);
	b->reverse^=1;
	o=merge(merge(a,b),c);
}
void revolve(Treap *&o,int l,int r,int x){
	int n=r-l+1;
	x=(x%n+n)%n;
	Treap *a,*b,*c,*d;
	split(o,a,b,l-1);
	split(b,b,c,n-x);
	split(c,c,d,x);
	o=merge(merge(a,c),merge(b,d));
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
	int x=b->mini;
	o=merge(merge(a,b),c);
	return x;
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n,q;
	Treap *root=NULL;
	cin>>n;
	int t;
	for(int q=0;q<n;q++){
		cin>>t;
		root=merge(root,new Treap(t));
	}
	cin>>q;
	string s;
	int l,r,x;
	while(q--){
		cin>>s;
		if(s=="ADD"){
			cin>>l>>r>>x;
			add(root,l,r,x);
		}else if(s=="REVERSE"){
			cin>>l>>r;
			reverse(root,l,r);
		}else if(s=="REVOLVE"){
			cin>>l>>r>>x;
			revolve(root,l,r,x);
		}else if(s=="INSERT"){
			cin>>l>>x;
			insert(root,l,x);
		}else if(s=="DELETE"){
			cin>>l;
			remove(root,l);
		}else {
			cin>>l>>r;
			cout<<ans(root,l,r)<<endl;
		}
	}
}
