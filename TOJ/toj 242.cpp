// By KRT girl xiplus
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
struct Tree{
	Tree *l,*r;
	int sum;
	int color; //1=blue 2=yellow 3=mixed
	int lcolor,rcolor;
	Tree(){
		l=r=NULL;
		sum=0;
		color=lcolor=rcolor=2;
	}
};
void up(Tree *id){
	id->color=id->l->color|id->r->color;
	
	id->lcolor=id->l->lcolor;
	id->rcolor=id->r->rcolor;
	
	if(id->color==2){
		id->sum=0;
	}else {
		id->sum=id->l->sum+id->r->sum;
		if((id->l->rcolor|id->r->lcolor)==1){
			id->sum--;
		}
	}
}
void down(Tree *id){
	if(id->color<=2){
		id->l->color=id->r->color=id->color;
		id->l->lcolor=id->r->lcolor=id->lcolor;
		id->l->rcolor=id->r->rcolor=id->rcolor;
		id->l->sum=id->r->sum=id->sum;
	}
}
void edit(Tree *id,int tl,int tr,int ql,int qr,int color){
	if(tl==ql&&tr==qr){
		id->color=id->lcolor=id->rcolor=color;
		id->sum=(id->color==1);
		return ;
	}
	if(!id->l)id->l=new Tree();
	if(!id->r)id->r=new Tree();
	down(id);
	int tm=(tl+tr)/2;
	if(ql<=tm){
		edit(id->l,tl,tm,ql,min(qr,tm),color);
	}
	if(qr>tm){
		edit(id->r,tm+1,tr,max(ql,tm+1),qr,color);
	}
	up(id);
}
int query(Tree *id,int tl,int tr,int ql,int qr){
	if(tl==ql&&tr==qr){
		return id->sum;
	}
	if(!id->l)id->l=new Tree();
	if(!id->r)id->r=new Tree();
	down(id);
	int tm=(tl+tr)/2;
	int ans=0;
	if(ql<=tm){
		ans+=query(id->l,tl,tm,ql,min(qr,tm));
	}
	if(qr>tm){
		ans+=query(id->r,tm+1,tr,max(ql,tm+1),qr);
	}
	up(id);
	if(ql<=tm&&qr>tm&&(id->l->rcolor|id->r->lcolor)==1){
		ans--;
	}
	return ans;
}
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	Tree *root=new Tree();
	int n,q;
	cin>>n>>q;
	edit(root,0,n,0,0,1);
	int x,l,r;
	while(q--){
		cin>>x>>l>>r;
		if(x==1){
			edit(root,0,n,l,r,1);
		}else if(x==2){
			edit(root,0,n,l,r,2);
		}else {
			cout<<query(root,0,n,l,r)<<endl;
		}
	}
}

